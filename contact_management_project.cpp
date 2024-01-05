#include<iostream>
#include<fstream>
#include<stdbool.h>
using namespace std;
string fname,lname,phone_num;
void addcontact();
void searchcontact();
void self_exit();
void help();
bool check_digits(string);
bool check_numbers(string);
void addcontact()
{
	ofstream phone("number.txt",ios::app);
	system("clear");
	cout << "\n\n\t Enter the first Name:";
	cin >> fname;
	cout << "\n\n\t Enter the last name:";
	cin >> lname;
	cout <<" \n\tEnter the 10 -digit number:";
	cin >> phone_num;
	if(check_digits(phone_num)==true)
	{
		if(check_numbers(phone_num)==true)
		{
                     if(phone.is_open())
		     { 
			     phone << fname << " "<<  lname << " " << phone_num << endl;
			     cout<<"Contact saved succesfully\n";
		     }
		     else
		     {
			     cout<< "\n\t error opening file..!";

		     }
		}
		else
		{
			cout << "\n\t Phone number must contains numbers only..!";
		}
	}
	else
	{
		cout << "\n\n\tA phone number must contains 10 digits:";
	}
	phone.close();
}
bool check_digits(string x)
{
	if(x.length()==10)
	{
		return true;
	}
	else
	{
             return false;
	}
}
bool check_numbers(string x)
{
	bool check=true;
	for(int i=0;i<x.length();i++)
	{
		if(!(int(x[i])>=48 && int(x[i]) <=57))
		{
		   check=false;	
		}

	}
	if(check==true)
	{
		return true;
	}
	else
	{
		return false;
	}

}	
void searchcontact()
{
	bool found=false;
	ifstream myfile("number.txt");
	string keyword;
	cout <<"\n\n\t Enter name to search:";
	cin >> keyword;
	while(myfile >> fname >> lname >> phone_num)
	{
		if(keyword == fname || keyword==lname)
		{
                   system("clear");
		   cout << "\n\n\n\t contact details ...";
		   cout << "\n\n\t first name:" << fname;
		   cout << "\n\t last name:" << lname;
		   cout << "\n\t phone number:" << phone_num;
		   found=true;
		   break;
		}
	}
	if(found == false)
	{
		cout <<"\n\t no search contact found";
	}
}

void self_exit()
{
	cout << "\n\n\n\t\t Thank you for Using...!";
	exit(1);

}
void help()
{
	printf("display help");
}
int main()
{
	short int choice;
	cout << "\n\n\n\n\tContact management:";
	cout <<"\n\n\t1.Add contact\n\t2.Search contact\n\t3.Help\n\t4.Exit";
	cin>> choice;
	switch(choice)
	{
		case 1:
			addcontact();
			break;
		case 2:
			searchcontact();
			break;
		case 3:
			help();
			break;
		case 4:
			self_exit();
			break;
		default:
			cout << "\n\n\tInvalid input !";
			cout << "\n\t Press Any key to Continue...";
	}
	return 0;
}
