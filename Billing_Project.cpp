#include<iostream>
#include<ctime>
#include<fstream>
using namespace std;
class Shopping
{
	private:
		int pcode;
		float price;
		float dis;
		string pname;
	public:
		void menu();
		void administrator();
		void buyer();
		void add();
		void edit();
		void rem();
		void list();
		void receipt();
};
void Shopping:: menu()
{
m:
    int choice;
    string email;
    string password;
    cout<<"\t\t\t\t____________________________________\n";
    cout<<"\t\t\t\t                                    \n";
    cout<<"\t\t\t\t                                    \n";    
    cout<<"************Super billing market*****************  ";
    cout<<"\t\t\t\t                                    \n";
    cout<<"\t\t\t\t____________________________________\n";
    cout<<"\t\t\t\t|     1)Admin                       |\n";
    cout<<"\t\t\t\t|     2)Buyer                       |\n";
    cout<<"\t\t\t\t|     3)Exit                       |\n";
    cout<<"\n\t\t\t  please select ";
    cin>>choice;

    switch(choice)
    {
	    case 1:
		    cout<<"\t\t\t please login...\n";
		    cout<<"\t\t\t enter Email...\n";
		    cin>>email;
		    cout<<"\t\t\t password..\n";
		    cin>>password;

		    if(email=="jagtappavan2910@gmail.com" && password=="Pavan@2910")
		    {
                         administrator();
		    }
		    else
		    {
			    cout<<"invalid email/password";
		    }
		    break;
	case 2:
    {

	    buyer();
    }
	case 3:
    {
	    exit(0);

    }
	default:
    {
	    cout<<"please the given option";
    }	
}
goto m;
}

void Shopping:: administrator()
{
m:
	int choice;
	cout<<"\n\n\n\n\t admin menu";
	cout<<"\n\n\n\n\t 1) Add the product";
	cout<<"\n\n\n\n\t********************"; 
	cout<<"\n\n\n\n\t 2) Modify the product";
	cout<<"\n\n\n\n\t********************"; 
	cout<<"\n\n\n\n\t 3) delete the product";
	cout<<"\n\n\n\n\t********************"; 
	cout<<"\n\n\n\n\t 4) back main menu";
	cout<<"\n\n\n\n\t********************"; 
	cout<<"\n\n\n\t  Please enter your choice";
	cin>>choice;
	switch(choice)
	{
		case 1:
			add();
			break;
		case 2:
			edit();
			break;
		case 3:
			rem();
			break;
		case 4:
			menu();
			break;
		default:
			cout<<"Invalid choice...";
	}
	goto m;
}
void Shopping::buyer()
{
m:
	int choice;
	cout<<"\t\t\t Buyer \n";
	cout<<"\t\t\t_________________\n";
	cout<<"                \n";
	cout<<"\t\t\t 1) Buy Prodcut \n";
	cout<<"                     \n";
	cout<<"\t\t\t 2) go Back  \n";
	cin>>choice;
	switch(choice)
	{
		case 1:
			receipt();
			break;
		case 2:
			menu();
			break;
		default:
			cout<<"Invalid choice";
	}
	goto m;
}
void Shopping::add()
{
m:
	fstream data;
	int c;
	int tokens=0;
	float p;
	float d;
	string n;
	cout<<"\n\n\n\t\t\t Add new product";
	cout<<"\n\n\n\t\t\t Product code of the product";
	cin>>pcode;
	cout<<"\n\n\t Name of the product";
	cin>>pname;
	cout<<"\n\n\t Price of the product";
	cin>>price;
	cout<<"\n\n\t dicount of the product";
	cin>>dis;
	data.open("database.txt",ios::in);
	if(!data)
	{
		data.open("database.txt",ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" " <<price<<" "<<dis<<"\n";
		data.close();
	}
	else
	{
		data>>c>>n>>p>>d;
		while(!data.eof())
		{
			if(c==pcode)
			{
				tokens++;
			}
			data>>c>>n>>p>>d;
		}
		data.close();
	}
	if(tokens==1)
		goto m;
	else
	{
		data.open("database.txt",ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" " <<price<<" "<<dis<<"\n";
		data.close();
	}
	cout<<"\n\n\t Record inserted ...!"<<endl;
}
void Shopping::edit()
{
	fstream data,data1;
	int pkey;
	int tokens=0;
	int c;
	float p;
	float d;
	string n;
	cout<<"\n\t\t\t Modify the record";
	cout<<"\n\t\t\t Enter the product code";
	cin>>pkey;

	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\n file does not exits";
	}
	else
	{

		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pkey==pcode)
			{
				cout<<"\n\t\t product of new code";
				cin>>c;
				cout<<"\n\t\t Name of the product";
				cin>>n;
				cout<<"\n\t\t price";
				cin>>p;
				cout<<"\n\t\t discount";
				cin>>d;
				data1<<" "<<c<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\n\t\t record edited";
				tokens++;

			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();

		remove("database.txt");
		rename("database1.txt","database.txt");

		if(tokens==0)
		{
			cout<<"\n\n record not found";
		}
	}
}
void Shopping::rem()
{
	fstream data,data1;
	int pkey;
	int tokens=0;
	cout<<"\n\t delete product";
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"file does not exits";
	}
	else
	{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pcode==pkey)
			{
				cout<<"\n\n\t product delete successfully";
				tokens++;
			}
			else
			{
				data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		if(tokens==0)
		{
			cout<<"\n\n record not found";
		}
	}
}

void Shopping::list()
{
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n________________________________________________\n";
	cout<<"product\t\tName\t\tprice\n";
	cout<<"\n\n________________________________________________\n";
	data>>pcode>>pname>>price>>dis;
	while(!data.eof())
	{
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>dis;
	}
	data.close();
}


void Shopping::receipt()
{
	fstream data;
	int arrc[100];
	int arrq[100];
	char choice;
	int c=0;
	float amount=0;
	float disc=0;
	float total=0;
	
	cout<<"\n\n\t\t\t RECEIPT";
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"empty database ";
	}
	else
	{
            data.close();
	    list();
	    cout<<"\n_____________________________\n";
	    cout<<"\n_____________________________\n";
	    cout<<"\n   Please place the order          \n";
	    cout<<"\n_____________________________\n";
	    cout<<"\n_____________________________\n";
	    do
	    {
m:
		    cout<<"\n\n Enter the product code";
		    cin>>arrc[c];
		    cout<<"\n\n Enter the product quantity";
		    cin>>arrq[c];
		    for(int i=0;i<c;i++)
		    {
			    if(arrc[c]==arrc[i])
			    {
				    cout<<"\n\n Duplicate product.please tey again";
				    goto m;
			    }
		    }
		    c++;
		    cout<<"\n\ndo you want to buy anothe product or not .if yes then press Y else no (n)";
		    cin>>choice;
	    }
	    while(choice=='y');
	    cout<<"\n\n\t\t____________________________RECEIPT_____________________________\n";
	    cout<<"\nproduct no\t product Name \t product quantity\tprice\tAmount\tAmount with discount\n";
	    for(int i=0;i<c;i++)
	    {
		    data.open("database.txt",ios::in);
		    data>>pcode>>pname>>price>>dis;
		    while(!data.eof())
		    {
			    if(pcode==arrc[c])
			    {
				    amount=price*arrq[i];
				    dis=amount-(amount*dis/100);
				    total=total+dis;
				    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
			    }
			    data>>pcode>>pname>>price>>dis;
		    } 
	    }
	    data.close();
	}
	cout<<"\n\n_________________________________________";
	cout<<"\n total amount "<<total;
}
int main()
{
	Shopping s;
	s.menu();
	return 0;
}
