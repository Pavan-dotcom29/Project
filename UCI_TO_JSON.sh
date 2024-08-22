#!/bin/sh

. /usr/share/libubox/jshn.sh

# Function to add a remote configuration to the JSON output
add_remote_config() {
    local config_name=$1
    local remote_name=$2

    # Start a new object for the remote section
    json_add_object "$remote_name"

    # Dynamically generate the list of fields using awk and uci show
    fields=$(uci show $config_name | awk -F. '{print $3}' | cut -d'=' -f1)

    # Loop through the fields and add them to the JSON object
    for field in $fields; do
        value=$(uci get $config_name.$field)

        # Add only the specific fields to the JSON object
        case "$field" in
            crypto_proposal | force_crypto_proposal | gateway | authentication_method | remote_identifier | local_identifier)
                json_add_string "$field" "$value"
                ;;
        esac
    done

    # Close the JSON object
    json_close_object
}

# Function to add tunnel configurations to the JSON output
add_tunnel_config() {
    local config_name=$1
    local tunnel_name=$2

    # Start a new object for the tunnel section
    json_add_object "$tunnel_name"

    # Dynamically generate the list of fields using awk and uci show
    fields=$(uci show $config_name | awk -F. '{print $3}' | cut -d'=' -f1)

    # Loop through the fields and add them to the JSON object
    for field in $fields; do
        value=$(uci get $config_name.$field)

        # Add only the specific fields to the JSON object
        case "$field" in
            crypto_proposal | force_crypto_proposal | gateway | authentication_method | remote_identifier | local_identifier)
                json_add_string "$field" "$value"
                ;;
        esac
    done

    # Close the JSON object
    json_close_object
}

# Function to add crypto_proposal configuration to the JSON output
add_crypto_proposal() {
    local config_name=$1
    local section_name=$2

    # Start a new object for the crypto_proposal section
    json_add_object "$section_name"

    # Get the value of crypto_proposal
    value=$(uci get $config_name.crypto_proposal)

    # Add the crypto_proposal field to the JSON object
    json_add_string "crypto_proposal" "$value"

    # Close the JSON object
    json_close_object
}

# Initialize the JSON document
json_init

# Start an array named "strongtune"
json_add_array "strongtune"

# Add configurations for remote
add_remote_config "ipsec.MyVPN" "remote"

# Add configurations for tunnel
add_tunnel_config "ipsec.MyVPN" "tunnel"

# Add the crypto_proposal parameter
add_crypto_proposal "ipsec.MyVPN" "crypto_proposal"

# Add configurations for remote1
add_remote_config "ipsec.MyVPN1" "remote1"

# Add configurations for tunnel1
add_tunnel_config "ipsec.MyVPN1" "tunnel1"

# Add the crypto_proposal1 parameter
add_crypto_proposal "ipsec.MyVPN1" "crypto_proposal1"

# Close the "strongtune" array
json_close_array

# Dump the JSON output and redirect it to a file in /tmp
json_dump > /tmp/config_output.json
