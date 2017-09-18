#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
  char ssn[10];
  char name[20];
  char branch[20];
  char dob[20];
};

int main(int argc,char *argv[])
{ 
    struct student s;
  int i=0,n,j;
   FILE *fp;
   fp=fopen("studentclg.txt","r+");
   if(strcmp(argv[3],"ssn")==0)
    {
      while(fread(&s,sizeof(struct student),1,fp))
         { 
             if(strcmp(argv[4],s.ssn)==0)
              printf("->%s\n%s\n%s\n%s\n",s.ssn,s.name,s.branch,s.dob);
         }
     }
    else if(strcmp(argv[3],"name")==0)
        {
           while(fread(&s,sizeof(struct student),1,fp))
         { if(strcmp(argv[4],s.name)==0)
              printf("->%s\n%s\n%s\n%s\n",s.ssn,s.name,s.branch,s.dob);
         }
     }
   else if(strcmp(argv[3],"branch")==0)
         {
           while(fread(&s,sizeof(struct student),1,fp))
         {
             if(strcmp(argv[4],s.branch)==0)
              printf("->%s\n%s\n%s\n%s\n",s.ssn,s.name,s.branch,s.dob);
         }
     }
   else if(strcmp(argv[3],"dob")==0)
         {
           while(fread(&s,sizeof(struct student),1,fp))
         {    if(strcmp(argv[4],s.dob)==0)
              printf("->%s\n%s\n%s\n%s\n",s.ssn,s.name,s.branch,s.dob);
         }
     }
    fclose(fp);
return 0;
}