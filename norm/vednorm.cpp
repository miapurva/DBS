#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

	int fds,attrs;

	cout<<"Enter number of attributes: ";
	cin>>attrs;
	cout<<"\nEnter number of FDs: ";
	cin>>fds;

	int fdArr[fds][attrs];

	cout<<"\nEnter all fds in '1 0 0 2' (A -> D) form"<<endl;

	for (int i = 0; i < fds; ++i)
	{
		cout<<"FD "<<i+1<<" :";
		for (int j = 0; j < attrs; ++j)
		{
			cin>>fdArr[i][j];
		}
	}

	int keys[attrs];
	int allkeys = 0;

	for (int i = 0; i < attrs; ++i)
	{
		cout<<"Is "<<i+1<<" a key :";
		cin>>keys[i];
		if (keys[i]==1)
		{
			allkeys++;
		}
	}

	int flag =0;

	int keyCount = 0;


	for (int i = 0; i < fds; ++i)
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
					cout<<"Violates 2nd normal form: "<<endl;
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
					cout<<" and place them in a seperate table."<<endl;
					break;
				}
			}
		}
		else if (keyCount!=allkeys)
		{
			flag = 1;
			cout<<"Violates 2nd normal form: "<<endl;
			cout<<"Take attributes ";
			for (int k = 0; k < attrs; ++k)
			{
				
				if(fdArr[i][k]==1 && keys[k] == 1)
				{
					cout<<k+1<<" ";
				}
				if (fdArr[i][k]==2)
				{
					cout<<k+1<<" ";
				}

			}
			cout<<" and place them in a seperate table."<<endl;
			break;
		}
		keyCount=0;
		if (flag==1)
		{
			break;
		}
	}

	if (flag==0)
	{
			cout<<"It is 2nf"<<endl;
	}


	return 0;
}
