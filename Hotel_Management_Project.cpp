#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{
	int quant;
	int choice;
        //Quantity
	int Qrooms=0,Qpasta=0,Qburger=0,Qnoodles=0,Qshake=0,Qchicken=0;
	//food items sold
	int Srooms=0,Spasta=0,Sburger=0,Snoodles=0,Sshake=0,Schicken=0;
	//total price of items
	int Total_rooms=0,Total_pasta,Total_burger=0,Total_noodles=0,Total_shake,Total_chicken=0;

	cout<<"\n\t Quantity of items we have";
	cout<<"\n Room avaliable";
	cin>>Qrooms;
	cout<<"\n Quantity of pasta";
	cin>>Qpasta;
	cout<<"\n Quantity of burger";
	cin>>Qburger;
	cout<<"\n Quantity of noddles";
	cin>>Qnoodles;
	cout<<"\n Quantity of shake";
	cin>>Qshake;
	cout<<"\n Quantity of chicken roll";
	cin>>Qchicken;
m:
	cout<<"\n\t\t\t please select the given menu option";
	cout<<"\n\n1) Rooms";
	cout<<"\n\n2) pasta";
	cout<<"\n\n3) burger";
	cout<<"\n\n4) noodles";
	cout<<"\n\n5) shake";
	cout<<"\n\n6) chicken-rool";
	cout<<"\n\n7) Information regarding sales and collection";
	cout<<"\n\n8) Exit";

	cout<<"\n\n please enter the choice";
	cin>>choice;

	switch(choice)
	{
		case 1:
			cout<<"\n\nenter the number of roms you want";
			cin>>quant;
			if(Qrooms-Srooms >=quant)
			{
				Srooms=Srooms+quant;
				Total_rooms=(Total_rooms+quant*1200);
				cout<<"\n\n\t\t "<<quant<<"rooms have to allocate to you";
			}
			else
			{
				cout<<"\n\tonly"<<Qrooms-Srooms<<"Rooms remaining rooms in hotel";
				break;
			}
		case 2:
			cout<<"\n\nEnter the pasta quantity";
			cin>>quant;
			if(Qpasta-Spasta >=quant)
			{
				Spasta=Spasta+quant;
				Total_pasta=(Total_pasta+quant*250);
				cout<<"\n\n\t\t "<<quant<<"pasta is the order";
			}
			else
			{
				cout<<"\n\tonly"<<Qpasta-Spasta<<"pasta remaining rooms in hotel";
				break;
			}
		case 3:
			cout<<"\n\nEnter the burger quantity";
			cin>>quant;
			if(Qburger-Sburger >=quant)
			{
				Sburger=Sburger+quant;
				Total_burger=(Total_burger+quant*250);
				cout<<"\n\n\t\t "<<quant<<"burger is the order";
			}
			else
			{
				cout<<"\n\tonly"<<Qburger-Sburger<<"burger remaining rooms in hotel";
				break;
			}
		case 4:
			cout<<"\n\nEnter the noodles quantity";
			cin>>quant;
			if(Qnoodles-Snoodles >=quant)
			{
				Snoodles=Snoodles+quant;
				Total_noodles=(Total_noodles+quant*140);
				cout<<"\n\n\t\t "<<quant<<"noodle is the order";
			}
			else
			{
				cout<<"\n\tonly"<<Qnoodles-Snoodles<<"noodle remaining rooms in hotel";
				break;
			}
		case 5:
			cout<<"\n\nEnter the shake quantity";
			cin>>quant;
			if(Qshake-Sshake >=quant)
			{
				Sshake=Sshake+quant;
				Total_shake=(Total_shake+quant*120);
				cout<<"\n\n\t\t "<<quant<<"shake is the order";
			}
			else
			{
				cout<<"\n\tonly"<<Qshake-Sshake<<"shake remaining rooms in hotel";
				break;
			}
		case 6:
			cout<<"\n\nEnter the chicken-roll quantity";
			cin>>quant;
			if(Qchicken- Schicken>=quant)
			{
				Schicken=Schicken+quant;
				Total_chicken=(Total_chicken+quant*150);
				cout<<"\n\n\t\t "<<quant<<"chicken-roll is the order";
			}
			else
			{
				cout<<"\n\tonly"<<Qchicken-Schicken<<"chicken-roll remaining rooms in hotel";
				break;
			}
		case 7:
			cout<<"\n\t\t Details of sales and collections";

			cout<<"\n\n Numbers of rooms we had:"<<Qrooms;
			cout<<"\n\n Numbers of rooms we gave for rent"<<Srooms;
			cout<<"\n\n remaining rooms "<<Qrooms-Srooms;
			cout<<"\n\n Total rooms collections for the day"<<Total_rooms;

			
			cout<<"\n\n Numbers of pasta we had:"<<Qpasta;
			cout<<"\n\n Numbers of pasta we gave for rent"<<Spasta;
			cout<<"\n\n remaining pasta "<<Qpasta-Spasta;
			cout<<"\n\n Total pasta collections for the day"<<Total_pasta;
			
			cout<<"\n\n Numbers of burger we had:"<<Qburger;
			cout<<"\n\n Numbers of burger we gave for rent"<<Sburger;
			cout<<"\n\n remaining burger "<<Qburger-Sburger;
			cout<<"\n\n Total burger collections for the day"<<Total_burger;

			cout<<"\n\n Numbers of noodles we had:"<<Qnoodles;
			cout<<"\n\n Numbers of  noodles we gave for rent"<<Snoodles;
			cout<<"\n\n remaining rooms "<<Qnoodles-Snoodles;
			cout<<"\n\n Total rooms collections for the day"<<Total_noodles;

			cout<<"\n\n Numbers of shake we had:"<<Qshake;
			cout<<"\n\n Numbers of  shake we gave for rent"<<Sshake;
			cout<<"\n\n remaining shake "<<Qshake-Sshake;
			cout<<"\n\n Total  shake collections for the day"<<Total_shake;

			cout<<"\n\n Numbers of chicken  we had:"<<Qchicken;
			cout<<"\n\n Numbers of  chicken we gave for rent"<<Schicken;
			cout<<"\n\n remaining chicken "<<Qchicken-Schicken;
			cout<<"\n\n Total chicken collections for the day"<<Total_chicken;

			cout<<"\n\n\n total collections for the day:"<<Total_rooms+Total_pasta+Total_burger+Total_noodles+Total_shake+Total_chicken;
			break;

		case 8:
			exit(0);
		default:
			cout<<"\n Please select the number mentoined above...!";

	}
	goto m;
	return 0;
}
