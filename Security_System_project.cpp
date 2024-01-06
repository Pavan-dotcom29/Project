#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
int main()
{
	int a,i=0;
	string text,old,password1,password2,pass,name,password0,age,user,word,word1;
	string creds[2],cp[2];
	cout<<"\t\tSecurity System"<<endl;
	cout<<"\t\t*********************************"<<endl<<endl;
	cout<<"\t\t|          1.Register            |"<<endl<<endl;
	cout<<"\t\t|          2.Login               |"<<endl<<endl;
	cout<<"\t\t|          3.Change password     |"<<endl<<endl;
	cout<<"\t\t|          4.End Program         |"<<endl<<endl;
	cout<<"\t\t*********************************"<<endl<<endl;
	do
	{
		cout<<endl<<endl;
		cout<<"Enter your Choice:";
		cin>>a;
		switch(a)
		{
		case 1:
		{
		      cout<<"______________________________________"<<endl<<endl;
		      cout<<"-----------Register------------------|"<<endl<<endl;
		      cout<<"please enter username:";
		      cin>>name;
		      cout<<"please enter password:";
		      cin>>password0;
		      cout<<"please enter age:";
		      cin>>age;
		      ofstream of1;
		      of1.open("file.txt");
		      if(of1.is_open())
		      {
			      of1<<name<<"\n";
			      of1<<password0;
			      cout<<"Registration successfull"<<endl;
		      }
		      break;
		}
		case 2:
		{
		i=0;
		cout<<"__________________________________"<<endl<<endl;
		cout<<"-----------Login------------------|"<<endl<<endl;
		cout<<"__________________________________"<<endl<<endl;
		ifstream of2;
		of2.open("file.txt");
		cout<<"please enter username:";
		cin>>user;
		cout<<"please enter password:";
		cin>>pass;

		if(of2.is_open())
		{
			while(!of2.eof())
			{
				while(getline(of2,text))
				{
					istringstream iss(text);
					iss>>word;
					creds[i]=word;
					i++;
				}

				if(user==creds[0] && pass==creds[1])
				{
					cout<<"---log in Successfull----";
					cout<<endl<<endl;
					cout<<"Details: "<<endl;
					cout<<"Username: "+ name<<endl;
					cout<<"password: "+ pass<<endl;
					cout<<"Age: " + age<<endl;

				}
				else
				{
					cout<<endl<<endl;
					cout<<"Incorrect Credientails"<<endl;
					cout<<"|          1.press 2 to login                |"<<endl;
					cout<<"|          2.press 3 to change pasword       |"<<endl;
					break;
				}
			}
		}
		break;
        	}	
		case 3:
		{
		i=0;
		cout<<"--------------change password----------------"<<endl;
		ifstream of0;
                of0.open("file.txt");
		cout<<"enter the old password: ";
		cin>>old;
		if(of0.is_open())
		{
			while(of0.eof())
			{
				while(getline(of0,text))
				{
					istringstream iss(text);
					iss>>word1;
					cp[i]=word1;
					i++;

				}
				if(old==cp[1])
				{
					of0.close();
					ofstream of1;
					if(of1.is_open())
					{
						cout<<"enter the new password";
						cin>>password1;
						cout<<"Enter your password again";
						cin>>password2;

						if(password1==password2)
						{
							of1<<cp[0]<<"\n";
							of1<<password1;
							cout<<"password changes successfully"<<endl;
						}

						else
						{
							of1<<cp[0]<<"\n";
							of1<<old;
							cout<<"password do not match"<<endl;
						}
					}
				}
				else
				{
					cout<<"please enter the valid pasword"<<endl;
					break;
				}
			}
		}
		break;
        	}
                case 4:
                {
			cout<<"_____________Thankyou..!_______________";
			break;
		}	
		default:
		cout<<"enter the valid choice"<<endl;
            }
       }
while(a!=4);
return 0;
}
