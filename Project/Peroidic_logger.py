#Python Automation Script : Periodic Process Logger with Auto Scheduled Log Report Facility 

#Author Name :Pavan Chandrakant Jagtap 
'''In this project we create log file with the current time and store information about all running
processes as its name , PID, memory usage, thread count number of child process.
Our automation script executes periodically depends on the time specified by the user using
scheduler of python.After periodic execution it sends the log file to the specified email address.
'''
#importing required libraries
from sys import*
import psutil
import  smtplib
import urllib.request
from urllib.request import urlopen
import os
from email import encoders
from email.mime.text import MIMEText
from email.mime.base import MIMEBase 
from email.mime.multipart import MIMEMultipart

#Checking internet connection
def is_connected():
    try:
        urllib.request.urlopen('http://216.58.192.142',timeout=6)
        print("connected");
        return True
    except urllib.request.URLError:
        print("Not connected");
        return False

#Sending mail to specific mail id
def MailSender(gmail_user,gamil_password,filename,mail_dest):
    sent_from = gmail_user
    to = mail_dest

    try:
        msg = MIMEMultipart()
        Subject = """Information about running Process"""
        msg['Subject'] = Subject 
        attachment = open(filename,"rb")
        p = MIMEBase('application','octet-stream')
        p.set_payload((attachment).read())
        encoders.encode_base64(p)
        p.add_header('Content-Disposition',"attachment; filename=%s"%filename)
        msg.attach(p)

        server = smtplib.SMTP_SSL('smtp.gmail.com',465)
        server.ehlo()
        server.login(gmail_user,gamil_password)
        text = msg.as_string()
        server.sendmail(sent_from,to,text)
        server.close()

        #Mail is send successfully or not
        print("Log file successfully send to mail")
    except Exception as E:
        print("Unable to send mail.",E)

#Creating a log file in a specific location
def ProcessdisplayLog(log_dir,mail_dest):
    listProcess = []

    if not os.path.exists(log_dir):
        try:
            os.mkdir(log_dir)
        except:
            pass

    seprator = "-"*80
    log_path = os.path.join(log_dir,"proc.log")
    fd = open(log_path,'w')
    fd.write(seprator + "\n")
    fd.write("Process Information :\n")
    fd.write(seprator + "\n")
    fd.write("\n")

    for proc in psutil.process_iter():
        try:
            pinfo = proc.as_dict(attrs = ['pid','name','username'])
            listProcess.append(pinfo)
        
        except (psutil.NoSuchProcess,psutil.AccessDenied,psutil.ZombieProcess):
            pass

    for element in listProcess:
        fd.write("%s\n"%element)

    print("Log file successfully generated at location %s"%(log_path))    

    connected = is_connected()

    if connected:
        user = 'njagtap368@gmail.com'
        password = 'password' 
        MailSender(user,password,log_path,mail_dest)
    else:
        print("There is no internet")


def main():
    print("---Periodic Process Logger with Auto Scheduled Log Report Facility---")
    print("Log file is creating....")

    dir_name = argv[1]
    mail_dest = argv[2]

    ProcessdisplayLog(dir_name,mail_dest)

if __name__ == "__main__":
    main()