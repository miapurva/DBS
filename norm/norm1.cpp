#include <iostream>
#include <stdlib.h>
#define size 100
using namespace std;
int array[100][100], primeKey[100], relations[100][100];
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
	
	/*cout<<"The candidate keys are : \n";
	
	for(int i = 0; i < numberofCandidates; i++)
	{
		for(int j = 0; j < numberofAttributes; j++)
		{
			if(primeKey[i] == 1)
			cout<<j<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;	
	
	// Relations
	
	cout<<"The relations are : \n";
	
	for(int i = 0; i < numberofFD; i++)
	{
	 	for(int j = 0; j < numberofAttributes; j++)
	 	{
	 		cout<<relations[i][j]<<"\t";
	 	}
	 	cout<<endl;
	}
	cout<<endl;*/
}
/*
void NF2()
{
	for(int i  = 0; i < numberofFD; i++)
	{
		int count = 0;
		for(int j = 0; j < numberofAttributes; j++)
		{
			if(array[i][j] == 1) 
			{
				for(int k = 0; k < numberofFD; k++)
				{
					if(primeKey[k] == 1)
					{
						count++;
						break;
					}
				}
			}	
		}
		if(count < countKeys && count > 0)
		{
			r++;
			index++;
			for(int k = 0; k < numberofAttributes; k++)
			{
				if(array[i][k] == 1 || array[i][k] == 2)
				{
					relations[index][k] = r;
					count = 0;
					for(int l = 0; l < numberofFD; l++)
					{ 
						if(primeKey[l] == 1)
						{
							count++;
						}
					}
					if(count == 0)
					{
						relations[0][k] = 0;
						break;					
					}
				}
			}
		}		
	}
	cout<<endl;
}*/

/*void NF3()
{
	int count1 = 0, count2 = 0;
	for(int i = 0; i < numberofAttributes; i++)
	{
		count2 = 0;
		count1 = 0;
		for(int j = 0; j < numberofAttributes; j++)
		{
			if(array[i][j] == 1) 
			{
				++count2;
				for(int k = 0; k < numberofFD; k++)
				{
					if(primeKey[k] == 1)
					{
						++count1;
						break;
					}
				}
			}
		}
		if(count1 < count2)
		{	
			++r;
			++index;
			++numberofCandidates;
			for(int k = 0; k < numberofAttributes; k++)
			{
				if(array[i][k] == 1 || array[i][k] == 2)
				{
					relations[index][k] = r;
					count = 0;
					for(int l = 0; l < numberofFD; l++)
					{ 
						if(array[l][k] == 1)
						{
							count++;
						}
					}
					if(count != 0)
					{
						primeKey[numberofCandidates][k] = 1;			
					}						
					else
					{
						for(int m = 0 ; m < r-1; ++m)
						relations[m][k] = 0;							
					}		
 				}
			}		
		}
	}
	cout<<endl;
}*/


int main()
{
	
	cout<<"Enter the number of attributes\n";
	cin>>numberofAttributes;
	
	cout<<"Enter the number of FD's\n";
	cin>>numberofFD;
	
	cout<<"Enter the number of Candidate Keys\n";
	cin>>numberofCandidates;
	
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
			if(i  == 0)
			relations[i][j] = 1;
			else
			relations[i][j] = 0;
		}
	}
	cout<<endl;	
	
	//Enter the FD's
	
	cout<<"\t\t\tEnter the FD's in the form '1 0 0 2' for 'A->D' \n";
	cout<<"Enter 1 for the left hand attributes\n";
	cout<<"Enter 2 for the right hand attributes\n";
	
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
	 		cin>>array[i][j];
	 	}
	}
	cout<<endl;
	
	int allkeys=0;
		for(int i = 0; i < numberofAttributes; i++)
		{
			cout<<"Is "<<i + 1<<" a part of the PRIME key ?\n";
			cout<<"Press 1 if YES o/w 0"<<endl;
			cin>>primeKey[i];
			if(primeKey[i] == 1)
				++allkeys;
		}
		//if(temp != 0)
		//++countKeys;
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
		if(countKeys==allkeys)
		{
			for (int k = 0; k < numberofAttributes; k++)
			{
				if(primeKey[k]==1 && array[i][k])
				{
					flag=1;
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
			}
		}
		else if(countKeys!=allkeys)
		{
			flag = 1;
			cout<<"Is 3rd Normal form "<<endl;
			cout<<"Place attributes ";
			for (int k = 0; k < numberofAttributes; ++k)
			{
				
				if(array[i][k]==1 && primeKey[k] == 1)
				{
					cout<<k+1<<" ";
				}
				if (array[i][k]==2)
				{
					cout<<k+1<<" ";
				}

			}
			cout<<" separately."<<endl;
			break;
		}
		countKeys=0;
	}
	//NF2();
	cout<<"After 2NF : \n";
	for(int i = 0; i < numberofFD; i++)
	{
	 	for(int j = 0; j < numberofAttributes; j++)
	 	{
	 		if(array[i][j] == 1)
	 		cout<<j<<"\t";
	 	}
	 	cout<<"\t->\t";
	 	for(int j = 0; j < numberofAttributes; j++)
	 	{
	 		if(array[i][j] == 2)
	 		cout<<j<<"\t";
	 	}
	 	cout<<endl;
	}
	cout<<endl;
	
	/*cout<<"The relations are : \n";
	
	for(int i = 0; i < numberofFD; i++)
	{
	 	for(int j = 0; j < numberofAttributes; j++)
	 	{
	 		cout<<relations[i][j]<<"\t";
	 	}
	 	cout<<endl;
	}
	cout<<endl;	*/

	//3NF
		
	/*cout<<"After 3NF : \n";
	for(int i = 0; i < numberofFD; i++)
	{
	 	for(int j = 0; j < numberofAttributes; j++)
	 	{
	 		if(array[i][j] == 1)
	 		cout<<j<<"\t";
	 	}
	 	cout<<"\t->\t";
	 	for(int j = 0; j < numberofAttributes; j++)
	 	{
	 		if(array[i][j] == 2)
	 		cout<<j<<"\t";
	 	}
	 	cout<<endl;
	}
	cout<<endl;*/
	
	/*cout<<"The relations are : \n";
	
	for(int i = 0; i < numberofFD; i++)
	{
	 	for(int j = 0; j < numberofAttributes; j++)
	 	{
	 		cout<<relations[i][j]<<"\t";
	 	}
	 	cout<<endl;
	}
	cout<<endl;	*/
	
	/*cout<<"The candidate keys are : \n";
	
		for(int j = 0; j < numberofAttributes; j++)
		{
			if(primeKey[j] == 1)
			cout<<j<<"\t";
		}
		cout<<endl;*/
	
	return(0);	
}
