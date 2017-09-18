#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
  char ssn[10];
  char name[20];
  char branch[20];
  char dob[20];
};

int main(int argc,char *argv[])
{
  int i=0,n,j;
   FILE *fp;
   struct student s;
 
     printf("student's %s",argv[3]);
   fp=fopen("studentclg.txt","r+");
   if(strcmp(argv[3],"ssn")==0)
    {
      while(fread(&s,sizeof(struct student),1,fp))
         {
              printf("->%s\n",s.ssn);
         }
     }
    else if(strcmp(argv[3],"name")==0)
        {
           while(fread(&s,sizeof(struct student),1,fp))
         {
              printf("->%s\n",s.name);
         }
     }
   else if(strcmp(argv[3],"branch")==0)
         {
           while(fread(&s,sizeof(struct student),1,fp))
         {
              printf("->%s\n",s.branch);
         }
     }
   else if(strcmp(argv[3],"dob")==0)
         {
           while(fread(&s,sizeof(struct student),1,fp))
         {
              printf("->%s\n",s.dob);
         }
     }
return 0;
}