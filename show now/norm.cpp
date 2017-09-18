#include <iostream>
using namespace std;
#define MAX_FD 10

int main(int argc, char const *argv[])
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

	int lhs,rhs,terms,term2,fdcount;
	int occured_in_lhs[attrs],occured_in_rhs[attrs];

	for (int i = 0; i < attrs; ++i)
	{
		occured_in_lhs[i] = -1;
		occured_in_rhs[i] = -1;
	}
	fdcount = 0;
	for (int i = 0; i < fds; ++i)
	{
		cout<<"FD "<<i+1<<" :"<<endl;

		cout<<"\tNumber of LHS terms:";
		cin>>terms;
		cout<<"\tNumber of RHS terms:";
		cin>>term2;

		
		if (terms == 1 & term2==1)
		{		
				cout<<"\n\tLHS: ";
				cin>>lhs;
				//cin>>rhs;
				if (occured_in_lhs[lhs-1]!= -1)
				{
					fdArr[ occured_in_lhs[lhs-1]][lhs-1] = 1;
					cout<<"\n\tRHS: ";
					cin>>rhs;
					fdArr[occured_in_lhs[lhs-1]][rhs-1] = 2;
				}
				else{
					fdArr[fdcount][lhs-1] = 1;
					cout<<"\n\tRHS: ";
					cin>>rhs;
					fdArr[fdcount][rhs-1] = 2;
					occured_in_lhs[lhs-1] = fdcount;
					fdcount++;
				}
		}
		else if(terms>1 && term2==1)
		{
			cout<<"\n\t LHS: ";
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
		else if(terms > 1 && term2 > 1)
		{
			cout<<"\n\t LHS:";
			for (int i = 0; i < terms; ++i)
			{
				cin>>lhs;
				fdArr[fdcount][lhs-1] = 1;					
			}			
			//fdcount++;
			cout<<"\n\tRHS: ";
			for (int i = 0; i < term2; ++i)
			{
				cin>>rhs;
				fdArr[fdcount][rhs-1] = 2;					
			}
			//fdArr[fdcount][rhs-1] = 2;
			fdcount++;
		}
		else if(terms == 1 && term2 > 1)
		{
			cout<<"\n\tLHS: ";
			cin>>lhs;
				//cin>>rhs;
				if (occured_in_lhs[lhs-1]!= -1)
				{
					fdArr[ occured_in_lhs[lhs-1]][lhs-1] = 1;
					cout<<"\n\tRHS: ";
					for(int i=0;i < term2;i++)
					{
					cin>>rhs;
					fdArr[fdcount][rhs-1] = 2;
					}
					//fdArr[occured_in_lhs[lhs-1]][rhs-1] = 2;
					fdcount++;
				}
				else{
					fdArr[fdcount][lhs-1] = 1;
					cout<<"\n\tRHS: ";
					for(int i=0;i<term2;i++)
					{
					cin>>rhs;
					fdArr[fdcount][rhs-1] = 2;
					}
					occured_in_lhs[lhs-1] = fdcount;
					occured_in_rhs[rhs-1] = fdcount;
					fdcount++;
				}
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
				if(keys[i]==1 && fdArr[i][k]==1)
				{
					flag = 1;
					//cout<<"Violates 3rd normal form: "<<endl;
					/*cout<<"Take attributes ";
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
					cout<<" and place them in a seperate table."<<endl;
					*/
				}
				if(keys[k]!=1 && fdArr[i][k]==1)
				{
					flag = 2;
					
					/*cout<<"Take attributes ";
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
					cout<<" and place them in a seperate table."<<endl;*/
				}
			}
		}
		else if (keyCount!=allkeys)
		{
			for (int k = 0; k < attrs; ++k)
			{
				if((keys[k]!=1 && fdArr[i][k]==1) || (keys[k]!=1 && fdArr[i][k]==2))
				{
					flag = 3;
					/*cout<<"Take attributes ";
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
					cout<<" and place them in a seperate table."<<endl;*/
				}
			}
		}
		keyCount=0;	
	}
	if (flag==0)
	{
			cout<<"Violates 2nf "<<endl;
	}
	if(flag==1)
		cout<<"It is 2NF: "<<endl;
	if(flag==2)
		cout<<"Violates BCNF: "<<endl;
	if(flag==3)
		cout<<"Violates 3NF: "<<endl;

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