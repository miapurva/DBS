#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student 
{
  char name[15];
  char sid[10];
  char branch[5];
  char dob[10];
  char gender[2];
}s;

int main(int argc,char *argv[])
{
	FILE *fp;
	fp=fopen("student.txt","r");
	int c;
	if(strcmp(argv[1],"project")==0)
	{
		if(strcmp(argv[2],"name")==0)
		{
			printf("\nNAME:\n");
			while(fread(&s,sizeof(struct student),1,fp))
			{ 
				printf("%s",s.name);
				printf("\n");
			}
		}
		if(strcmp(argv[2],"sid")==0)
		{
			printf("\nSID:");
			while(fread(&s,sizeof(struct student),1,fp))
			{ 
				printf("%s",s.sid);
				printf("\n");
			}
		}
		if(strcmp(argv[2],"branch")==0)
		{
			printf("\nBRANCH:");
			while(fread(&s,sizeof(struct student),1,fp))
			{ 
				printf("%s",s.branch);
				printf("\n");
			}
		}
		if(strcmp(argv[2],"dob")==0)
		{
			printf("\nDOB:");
			while(fread(&s,sizeof(struct student),1,fp))
			{ 
				printf("%s",s.dob);
				printf("\n");
			}
		}
		if(strcmp(argv[2],"gender")==0)
		{
			printf("\nGENDER:");
			while(fread(&s,sizeof(struct student),1,fp))
			{ 
				printf("%s",s.gender);
				printf("\n");
			}
		}
	}
	fclose(fp);
	return 0;
}
