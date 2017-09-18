#include <iostream>
#include <stdlib.h>

using namespace std;
int array[numberofFD][numberofAttributes], candidateKey[numberofAttributes][numberofAttributes], relations[numberofFD][numberofAttributes];
int  r = 1, countKeys = 0, index = 0, temp = 0, count;

int main()
{
	int numberofAttributes, numberofFD, numberofCandidates;
	
	cout<<"Enter the number of attributes\n";
	cin>>numberofAttributes;
	
	cout<<"Enter the number of FD's\n";
	cin>>numberofFD;
	
	cout<<"Enter the number of Candidate Keys\n";
	cin>>numberofCandidates;
	
	
	
	//Initializing all to 0 
	
	for(int i = 0; i < numberofAttributes; i++)
	{
		for(int j  = 0; j < numberofAttributes; j++)
		{
			candidateKey[i][j] = 0;
		}
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
	
	cout<<"Enter the FD's\n";
	cout<<"Enter 1 for the left hand attributes\n";
	cout<<"Enter 2 for the right hand attributes\n";
	
	for(int i = 0; i < numberofFD; i++)
	{
		cout<<"Enter the "<<i<<" FD\n";
	 	for(int j = 0; j < numberofAttributes; j++)
	 	{
	 		cin>>array[i][j];
	 	}
	}
	cout<<endl;
	
		
	//Enter the candidate keys
	
	for(int i = 0; i < numberofCandidates; i++)
	{
		temp = 0;
		cout<<"Enter the "<<i + 1<<" candidate key\n";
		for(int j = 0; j < numberofAttributes; j++)
		{
			cout<<"Is "<<j<<" a part of the candidate key?\n";
			cin>>candidateKey[i][j];
			if(candidateKey[i][j] == 1)
			++temp;
		}
		if(temp != 0)
		++countKeys;
		
	}
	cout<<endl;
	
	//Display
	
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
	
	cout<<"The candidate keys are : \n";
	
	for(int i = 0; i < numberofCandidates; i++)
	{
		for(int j = 0; j < numberofAttributes; j++)
		{
			if(candidateKey[i][j] == 1)
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
	cout<<endl;	
	
	//2NF
	
	for(int i  = 0; i < numberofFD; i++)
	{
		int count = 0;
		for(int j = 0; j < numberofAttributes; j++)
		{
			if(array[i][j] == 1) 
			{
				for(int k = 0; k < numberofFD; ++k)
				{
					if(candidateKey[k][j] == 1)
					{
						count++;
						break;
					}
				}
			}	
		}
		if(count < countKeys && count > 0)
		{
			++r;
			++index;
			for(int k = 0; k < numberofAttributes; ++k)
			{
				if(array[i][k] == 1 || array[i][k] == 2)
				{
					relations[index][k] = r;
					count = 0;
					for(int l = 0; l < numberofFD; ++l)
					{ 
						if(candidateKey[l][k] == 1)
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
	
	cout<<"The relations are : \n";
	
	for(int i = 0; i < numberofFD; i++)
	{
	 	for(int j = 0; j < numberofAttributes; j++)
	 	{
	 		cout<<relations[i][j]<<"\t";
	 	}
	 	cout<<endl;
	}
	cout<<endl;	

	// 3NF
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
				for(int k = 0; k < numberofFD; ++k)
				{
					if(candidateKey[k][j] == 1)
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
						candidateKey[numberofCandidates][k] = 1;			
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
	
	cout<<"After 3NF : \n";
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
	
	cout<<"The relations are : \n";
	
	for(int i = 0; i < numberofFD; i++)
	{
	 	for(int j = 0; j < numberofAttributes; j++)
	 	{
	 		cout<<relations[i][j]<<"\t";
	 	}
	 	cout<<endl;
	}
	cout<<endl;	
	
	cout<<"The candidate keys are : \n";
	
	for(int i = 0; i < numberofCandidates; i++)
	{
		for(int j = 0; j < numberofAttributes; j++)
		{
			if(candidateKey[i][j] == 1)
			cout<<j<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;	
	
	return(0);	
}
