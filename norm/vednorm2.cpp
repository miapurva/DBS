#include <iostream>

using namespace std;

#define MAX_FD 10

int main()
{

	int fds,attrs;
	int allkeys = 0;

	cout<<"Enter number of attributes: ";
	cin>>attrs;
	cout<<"\nEnter number of prime keys: ";
	cin>>allkeys;
	int keys[attrs];
	

	for (int i = 0; i < attrs; ++i)
	{
		cout<<"Is "<<i+1<<" a prime key (1/0):";
		cin>>keys[i];
	}

	cout<<"\nEnter number of FDs: ";
	cin>>fds;

	int fdArr[MAX_FD][attrs];

	for (int i = 0; i < MAX_FD; ++i)
	{
		for (int j = 0; j < attrs; ++j)
		{
			fdArr[i][j] = 0;
		}
	}

	cout<<"\nEnter the FDs :"<<endl;

	int lhs,rhs,terms,fdcount=0;

	int occured_in_lhs[attrs];

	for (int i = 0; i < attrs; ++i)
	{
		occured_in_lhs[i] = -1;
	}


	for (int i = 0; i < fds; ++i)
	{
		cout<<"FD "<<i+1<<" :"<<endl;

		cout<<"\tNumber of LHS terms:";
		cin>>terms;

		cout<<"\n\tLHS: ";
		
		if (terms == 1)											//A-->B
		{			
				cin>>lhs;
				if (occured_in_lhs[lhs-1]!= -1)					//already existing
				{
					fdArr[ occured_in_lhs[lhs-1]][lhs-1] = 1;
					cout<<"\n\tRHS: ";
					cin>>rhs;
					fdArr[occured_in_lhs[lhs-1]][rhs-1] = 2;
				}
				else{
					fdArr[fdcount][lhs-1] = 1;				//new
					cout<<"\n\tRHS: ";
					cin>>rhs;
					fdArr[fdcount][rhs-1] = 2;
					occured_in_lhs[lhs-1] = fdcount;
					fdcount++;
				}
		}
		else
		{													//AB-->C
				for (int i = 0; i < terms; ++i)
				{
					cin>>lhs;
					fdArr[fdcount][lhs-1] = 1;					
				}
					cout<<"\n\tRHS: ";
					cin>>rhs;
					fdArr[fdcount][rhs-1] = 2;
					fdcount++;
		}

		
	}


	int flag =0;

	int keyCount = 0;


	for (int i = 0; i < fdcount; ++i)
	{
		for (int j = 0; j < attrs; ++j)
		{
			if (fdArr[i][j] == 1)
			{
				/*if(keys[j]!=1)
				{
					cout<<"Not in 2nd normal form: "<<endl;
					flag = 1;
				}	*/
				keyCount++;

			}
		}
		if (keyCount == allkeys)
		{
			for (int k = 0; k < attrs; ++k)
			{
				if(keys[k]==1 && fdArr[i][k]!=1)
				{
					flag = 1;
					cout<<"Violates 3rd normal form: "<<endl;
					cout<<"Take attributes ";
					for (int uu = 0; uu < attrs; ++uu)
					{
				
						if(fdArr[i][uu]==1 && keys[uu] != 1)
						{
						cout<<uu+1<<" ";
						}
						if (fdArr[i][uu]==2)
						{
							cout<<uu+1<<" ";
						}

					}
					cout<<" and place them in a separate table."<<endl;
				}
				if(keys[k]!=1 && fdArr[i][k]==1)
				{
					flag = 1;
					cout<<"Violates BCNF: "<<endl;
					cout<<"Take attributes ";
					for (int uu = 0; uu < attrs; ++uu)
					{
				
						if(fdArr[i][uu]==1 && keys[uu] != 1)
						{
						cout<<uu+1<<" ";
						}
						if (fdArr[i][uu]==2)
						{
							cout<<uu+1<<" ";
						}

					}
					cout<<" and place them in a separate table."<<endl;
				}
			}
		}
		else if (keyCount!=allkeys)
		{
			for (int k = 0; k < attrs; ++k)
			{
				if(keys[k]!=1 && fdArr[i][k]==1)
				{
					flag =1;
					cout<<"Violates 2NF: "<<endl;
					cout<<"Take attributes ";
					for (int uu = 0; uu < attrs; ++uu)
					{	
				
						if(fdArr[i][uu]==1 && keys[uu] != 1)
						{
						cout<<uu+1<<" and ";
						}
						if (fdArr[i][uu]==2)
						{
							cout<<uu+1<<"";
						}

					}
					cout<<" and place them in a separate table."<<endl;
				}

			}
			/*if(keys[k]==1 && fdArr[i][k]!=1)
			{
				cout<<"Violates 2nd normal form: "<<endl;
				cout<<"Take attributes ";
				for (int k = 0; k < attrs; ++k)
				{
					
					if(fdArr[i][k]==1)
					{
						cout<<k+1<<" ";
					}
					if (fdArr[i][k]==2)
					{
						cout<<k+1<<" ";
					}

				}
				cout<<" and place them in a seperate table."<<endl;
			}*/

		}
		keyCount=0;
		
	}

	if (flag==0)
	{
			cout<<"It is 2nf "<<endl;
	}

	for (int i = 0; i < fdcount; ++i)
	{
		for (int j = 0; j < attrs; ++j)
		{
			cout<<fdArr[i][j]<<" ";
		}
		cout<<endl;
	}


	return 0;
}
