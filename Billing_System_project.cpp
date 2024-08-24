#include<iostream>
#include<stdlib.h>
using namespace std;
class list
{
	public:
		int id;
		string name;
		int price;
};
void display(list l[],int size,string cName,string cAddress)
{
int total=0;;
cout<<"\n\n\n";
cout<<"\t ************** \n";
cout<<"\t Pavan Store \n";
cout<<"\t ************** \n";
cout<<"\n";
cout<<"Name : "<<cName<<" \t Address : "<<cAddress<<"\n";
for(int i=0;i<size;i++)
{
	cout << "Id : "<<l[i].id<<"\t";
	cout << "ItemName : "<<l[i].name<<" \t";
	cout << "Price : "<<l[i].price<<"\n";
	cout<<"-----------------------------------------------------\n";
	total+=l[i].price;
}
cout <<"\tTotal : "<<total<<endl;
cout<<"\n\n";
cout<<"\t Thanks for Visting \n";
cout<<"\n\n";
}
int main()
{
	cout<<"hello ......."<<endl;
	string Name;
	string Address;
	int totalItems;
	cout<< "Enter your name \t";
	cin >>Name;
	cout<< "Enter your address \t";
	cin >>Address;
	cout<< "Enter your TotalItems \t";
	cin >>totalItems;
	cout <<"\n";
	list l[totalItems];
	for(int i=0;i<totalItems;i++)
	{
		l[i].id=(i+1);
		cout<<" Enter"<<(i+1)<<"Item name \t";
		cin>>l[i].name;
		cout<<" Enter the price\t";
		cin>>l[i].price;
	}
	display(l,totalItems,Name,Address); 
	return 0;
}
