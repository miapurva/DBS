#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define BUBBLE 7
int main(void)
{
	int myArray[BUBBLE];
	int i, j;
	int temp = 0;
	int num;
    
	srand(time(NULL));
    
	//fill array
	for (i = 0; i < BUBBLE; i ++)
	{    
		   num = rand() % BUBBLE + 1;
		   myArray[i] = num;
	}
   
	
	//sort array
	for(i = 0; i < BUBBLE; i++)
	{

		for (j = 0; j < BUBBLE-1; j++)
        {
            if (myArray[j] > myArray[j+1])
			{
				temp = myArray[j];
				myArray[j] = myArray[j+1];
				myArray[j+1] = temp;
			}
        }/*End inner for loop*/
	}/*End outer for loop*/
  
	
	//print array
	for (i = 0; i < BUBBLE; i++)
	{
		cout<<myArray[i]<<endl;
	}
	
	system("PAUSE");	
	return 0;
}/*End of main*/
