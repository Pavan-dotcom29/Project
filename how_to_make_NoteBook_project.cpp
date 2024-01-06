#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
using namespace std;
class Notebook
{
	private:
		vector<string> notes;
	public:
		void addnote()
		{
			string newNote;
			cout << "Enter your note:";
			getline(cin,newNote);
			notes.push_back(newNote);
			cout<< "Note added Successfully!.."<<endl;
		}
		void deletenote()
		{
			if(notes.empty())
			{
				cout <<"No notes to delete."<<endl;
				return ;
			}
		int index;
	        cout<<"Enter the index of the note you want to delete (0-"<< notes.size() -1<<endl;	
		cin>>index;
		cin.ignore();
		if(index>=0 && index < notes.size())
		     {
			notes.erase(notes.begin() + index);
			cout<<"Note Deleted succesfully...!"<<endl;
		     }
		else
		     {
			cout <<"Invalid index entered"<< endl;
		     }
		}
		void displaynote()
		{

			if(notes.empty())
			{
				cout <<"No notes avaiable "<<endl;
				return ;
			}
                cout <<" Your Note"<<endl;
		for(size_t i=0;i< notes.size();++i)
		    {
			cout<< i<< " : "<< notes[i]<<endl;
		    }
		}

};
int main()
{
	Notebook notebook;
	int choice;
	do
	{
        
	     cout<< "\033[1;31m NOTEBOOK MENU:\033[0m" <<endl;
	     cout<< "1. Add note :" <<endl;
	     cout<< "2. Delete note:"<<endl;
	     cout<< "3. Display notes:" <<endl;
	     cout<< "4. Exit:"<<endl;
	     cout<< "Enter your choice :";
	     cin >> choice;
	     cin.ignore();
	     switch(choice)
	     {
		     case 1:
			     notebook.addnote();
			     break;
		     case 2:
			     notebook.deletenote();
			     break;
		     case 3:
			     notebook.displaynote();
			     break;
		     case 4:
			     cout << "Existing..."<<endl;
			     break;
		     default:
			     cout<<"Invalid choice .Please enter a valid option";
	     }
	}
	while(choice !=4);
	return 0;
}
