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
    /* fp=fopen("student.txt","w+");
  int c;
  //printf("Command line arguments:");
  //printf("%s",argv[1]);
  //printf("%s",argv[2]);
  //printf("\n");
  while(1)
  {
    printf("\nEnter Name:   ");
    scanf("%s",s.name);
    printf("Enter StudentID: ");
    scanf("%s", s.sid);
    printf("Enter Branch:  ");
    scanf("%s",s.branch);
    printf("Enter gender: ");
    scanf("%s",s.gender);
    printf("Enter dob: ");
    scanf("%s", s.dob);
    fwrite(&s,sizeof(struct student),1,fp);
    printf("Enter 1 to break or 0 to continue:");
    scanf("%d",&c);
    if(c==1) break;
  }
  rewind(fp);
  while(fread(&s,sizeof(struct student),1,fp))
{
  printf("%s,%s,%s,%s,%s\n",s.name,s.sid,s.branch,s.gender,s.dob);
}
  fclose(fp);
  //printf("\nStudent Table:\n");
  */
     fp=fopen("student.txt","r");
     if(strcmp(argv[1],"select")==0)
     {
          if(strcmp(argv[2],"name")==0)
          {
               while(fread(&s,sizeof(struct student),1,fp))
               { 
               if(strcmp(s.name,argv[3])==0)
                    printf("Name:%s SID:%s Branch:%s Gender:%s DOB:%s",s.name,s.sid,s.branch,s.gender,s.dob);

               printf("\n");
               }
          }
          if(strcmp(argv[2],"sid")==0)
          {
          while(fread(&s,sizeof(struct student),1,fp))
               { 
               if(strcmp(s.sid,argv[3])==0)
                    printf("Name:%s SID:%s Branch:%s Gender:%s DOB:%s",s.name,s.sid,s.branch,s.gender,s.dob);
               printf("\n");
               }
          }
          if(strcmp(argv[2],"branch")==0)
          {
               while(fread(&s,sizeof(struct student),1,fp))
               { 
               if(strcmp(s.branch,argv[3])==0)
                    printf("Name:%s SID:%s Branch:%s Gender:%s DOB:%s",s.name,s.sid,s.branch,s.gender,s.dob);
               printf("\n");
               }
          }
          if(strcmp(argv[2],"dob")==0)
          {
               while(fread(&s,sizeof(struct student),1,fp))
               { 
                    if(strcmp(s.dob,argv[3])==0)
                         printf("Name:%s SID:%s Branch:%s Gender:%s DOB:%s",s.name,s.sid,s.branch,s.gender,s.dob);
          
                    printf("\n");
               }
          }
          if(strcmp(argv[2],"gender")==0)
          {
               while(fread(&s,sizeof(struct student),1,fp))
               { 
                    if(strcmp(s.gender,argv[3])==0)
                         printf("Name:%s SID:%s Branch:%s Gender:%s DOB:%s",s.name,s.sid,s.branch,s.gender,s.dob);
          
                    printf("\n");
               }
          }
     }
     fclose(fp);
     return 0;
}
