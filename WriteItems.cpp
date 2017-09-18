#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#define File_name "Items"

using namespace std;
int serial;

//Class Items declaration
class Items
{
	private :
		//data Members
		char Item_Id[10];
		char Item_Name[20];
		char Item_Type[20];
		char Brand[20];
	public :
		void Set_Item_Details(int &serial)
		{
			cout<<++serial<<". Enter the Item details:\n";
			cout<<"Item Id: ";cin.getline(Item_Id,10);
			cout<<"Item Name: ";cin.getline(Item_Name,20);
			cout<<"Item Type: ";cin.getline(Item_Type,20);
			cout<<"Brand: ";cin.getline(Brand,20);
		}

		void Get_Item_Details(int &serial,int ifID,int ifName,int ifType,int ifBrand)
		{
			cout<<setw(5)<<++serial;
			if(ifID)
				cout<<setw(15)<<Item_Id;
			if(ifName)
				cout<<setw(25)<<Item_Name;
			if(ifType)
				cout<<setw(25)<<Item_Type;
			if(ifBrand)
				cout<<setw(25)<<Brand;
			cout<<endl;
		}
};

//write file function definition
void Write_to_File()
{
	Items item;
	char choice;
	fstream file;
	file.open(File_name,ios::app|ios::binary);
	if(!file)
		{
			cout<<"Error in creating file...\n";
			return;
		}
	do
	{
		item.Set_Item_Details(serial);
		file.write((char*)&item,sizeof(item));
		cout<<"\n\t\tPress 'y' to preceed entering more item details... ";
		cin>>choice;
		cin.get();
	}while(choice=='y');
	
	file.close();
	cout<<"Date saved into file the file.\n\n";
}

//display file function definition
void Display_File()
{
	Items item;
	fstream file;
	file.open(File_name,ios::in|ios::binary);
	if(!file)
		{
			cout<<"Error in creating file...\n";
			return;
		}
	while(file.read((char*)&item,sizeof(item)))
	{
		item.Get_Item_Details(serial,1,1,1,1);
	}
	
	file.close();
	cout<<"Date extracted file the file.\n\n";
}

//main module
int main()
{
	cout<<"\n\t\tDo you wish to enter new details? (y/N) ";
	
	//object of item class
	Items item;

	if(cin.get()=='y')
	{
		//to avoid the extra Enter accepted to interrupt the data
		cin.get();
		//writing details into file
		serial=0;
		Write_to_File();
	}

	//reading details from file
	serial=0;
	Display_File();	
	
	return 0;
}