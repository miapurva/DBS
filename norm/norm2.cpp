#include <iostream>
#include <stdlib.h>
#define size 100
using namespace std;
int primeKey[100], relations[100][100];
int  r = 1, countKeys = 0, index = 0, temp = 0, count;
int numberofAttributes, numberofFD, numberofCandidates;

void Display()
{
	cout <<" The FD's are : \n"; 
	
	for(int i = 0; i < numberofFD; i++)
	{
	 	for(int j = 0; j < numberofAttributes; j++)
	 	{
	 		cout<<array[i][j]<<"\t";
	 	}
	 	cout<<endl;
	}
	cout<<endl;	
	
}

int main(void)
{
	
	cout<<"Enter the number of attributes\n";
	cin>>numberofAttributes;
	
	cout<<"Enter the number of FD's\n";
	cin>>numberofFD;
	
	cout<<"Enter the number of Candidate Keys\n";
	cin>>numberofCandidates;

	int array[numberofFD][numberofAttributes];
	int allprimekeys=0;
		for(int i = 0; i < numberofAttributes; i++)
		{
			cout<<"Is "<<i + 1<<" a part of the PRIME key ?\n";
			cout<<"Press 1 if YES o/w 0"<<endl;
			cin>>primeKey[i];
			if(primeKey[i] == 1)
				++allprimekeys;
		}
		//if(temp != 0)
		//++countKeys;
	cout<<endl;
	
	//Initializing all to 0 
	
	for(int i = 0; i < numberofAttributes; i++)
	{
			primeKey[i] = 0;
	}
	cout<<endl;
	
	for(int i = 0; i < numberofFD; i++)
	{
		for(int j  = 0; j < numberofAttributes; j++)
		{
			array[i][j] = 0;
		}
	}
	cout<<endl;	
	
	//Enter the FD's
	
	cout<<"\t\t\tEnter the FDs \n";
	//cout<<"Enter 1 for the left hand attributes\n";
	//cout<<"Enter 2 for the right hand attributes\n";

	int a,b;
	for(int i = 0; i < numberofFD; i++)
	{
		if(i==0)
			cout<<"Enter the "<<i + 1<<"st FD\n";
		else if(i==1)
			cout<<"Enter the "<<i + 1<<"nd FD\n";
		else if(i==2)
			cout<<"Enter the "<<i + 1<<"rd FD\n";
		else
			cout<<"Enter the "<<i + 1<<"th FD\n";
	 	for(int j = 0; j < numberofAttributes; j++)
	 	{
	 		cin>>a>>b;
	 		array[i][j]=1;
	 	}
	}
	cout<<endl;
		
	//Display
	Display();
		
	
	int flag=0;
	int countKeys=0;
	for (int i = 0; i < numberofFD; ++i)
	{
		for (int j = 0; j < numberofAttributes; ++j)
		{
			if(array[i][j]==1)
				{
					countKeys++;
				}
		}
		if(countKeys==allprimekeys)
		{
			for (int k = 0; k < numberofAttributes; k++)
			{
				if(primeKey[k]==1 && array[i][k]!=1)
				{
					flag=3;
					cout<<"Violates the 3NF ";
					cout<<"Place the attributes ";
					for(int l=0; l< numberofAttributes; l++)
					{
						if(array[i][l]==1 && primeKey[l] != 1)
						{
						cout<<l+1<<" and";
						}
						if (array[i][l]==2)
						{
							cout<<l+1<<" ";
						}

					}
					cout<<"separately"<<endl;
					break;
				}
				if(primeKey[k]!=1 && array[i][k]==1)
				{
					flag = 3;
					cout<<"Violates BCNF: "<<endl;
					cout<<"Place the attributes ";
					for (int l = 0; l < numberofAttributes; ++l)
					{
				
						if(fdArr[i][l]==1 && keys[l] != 1)
						{
						cout<<l+1<<" ";
						}
						if (fdArr[i][l]==2)
						{
							cout<<l+1<<" ";
						}

					}
					cout<<" separately."<<endl;
				}
			}
		}
		else if(countKeys!=allprimekeys)
		{
			/*flag = 1;
			cout<<"Is 3rd Normal form "<<endl;
			cout<<"Place attributes ";*/
			for (int k = 0; k < numberofAttributes; ++k)
			{	
				if(keys[k]!=1 && fdArr[i][k]==1)
				{
					flag = 3;
					cout<<"Violates BCNF: "<<endl;
					cout<<"Take attributes ";
					for (int l = 0; l < numberofAttributes; ++l)
					{
						if(array[i][k]==1 && primeKey[k] != 1)
						{
							cout<<k+1<<" and";
						}
						if (array[i][k]==2)
						{
							cout<<k+1<<" and";
						}

					}			
				
				}
				cout<<" separately."<<endl;
			}
		
		if(flag!=4)
		{
			cout<<"Violates 2NF:"<<endl;
			cout<<"Place attributes ";
			for (int k = 0; k < numberofAttributes; ++k)
				{
					
					if(array[i][k]==1)
					{
						cout<<k+1<<" ";
					}
					if (array[i][k]==2)
					{
						cout<<k+1<<" ";
					}

				}
				cout<<"separately. ";
		}
	}
		countKeys=0;
	}
	if (flag==0)
	{
			cout<<"It is 2NF "<<endl;
	}

	for (int i = 0; i < numberofFD; ++i)
	{
		for (int j = 0; j < numberofAttributes; ++j)
		{
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}
	return(0);	
}
