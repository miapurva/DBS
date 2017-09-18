#include <stdio.h>
#include <string.h>

struct stud{
	char name[20];
	char rollno[20];
	char deg[20];
	char branch[20];
	
};

struct course{
	char cname[20];
	char cno[20];
	int cred;
	char offdep[20];
};

struct sec{
	char sid[20];
	char cno[20];
	int sem;
	int year;
	char fac[20];
	
};

struct prereq{
	char cno[20];
	char preno[20];
};

struct graderep{
	char rollno[20];
	char sid[20];
	float cgpa;
	char grade;
	char cno[20];
};
int change(char c)
{
if(c=='S')
	return 10;
else if(c=='A')
	return 9;
else if(c=='B')
	return 8;
else if(c=='C')
	return 7;
else if(c=='D')
	return 6;
else if(c=='E')
	return 5;
else
return 0;
}
 void  main()
{
	int i=0,result,coe;
	FILE *fp1;
	fp1=fopen("b.txt","w+");
	
	struct stud s;
	
	for(i=0;i<5;i++)
	{
		printf("Enter name\n");
		scanf("%s", s.name);
		printf("Enter roll no.\n");
		scanf("%s", s.rollno);
		printf("Enter degree\n");
		scanf("%s", s.deg);
		printf("Enter branch\n");
		scanf("%s", s.branch);
		//fseek(fp1,sizeof(struct stud)+i,SEEK_SET);
		fwrite(&s,sizeof(struct stud),1,fp1);
	}
	rewind(fp1);
	while(fread(&s,sizeof(struct stud),1,fp1))
{
	printf("%s,%s,%s,%s\n",s.name,s.rollno,s.deg,s.branch);
}
 fclose(fp1);
	
	FILE *fp2;
	fp2=fopen("c.txt","w+");
	struct course c;
	for(i=0;i<5;i++)
	{
		printf("Enter course name\n");
		scanf("%s", c.cname);
		printf("Enter course no.\n");
		scanf("%s", c.cno);
		printf("Enter credits\n");
		scanf("%d", &c.cred);
		printf("Enter offering department\n");
		scanf("%s", c.offdep);
		//fseek(fp2,sizeof(struct course)+i,SEEK_SET);
		fwrite(&c,sizeof(struct course),1,fp2);
	}
	
	rewind(fp2);
	while(fread(&c,sizeof(struct course),1,fp2))
{
	printf("%s,%s,%d,%s\n",c.cname,c.cno,c.cred,c.offdep);
}
 fclose(fp2);
 
	FILE *fp3;
	fp3=fopen("e.txt","w+");
		struct sec sc;
	for(i=0;i<5;i++)
	{
		printf("Enter section identifier\n");
		scanf("%s", sc.sid);
		printf("Enter course no.\n");
		scanf("%s", sc.cno);
		printf("Enter sem\n");
		scanf("%d", &sc.sem);
		printf("Enter year\n");
		scanf("%d", &sc.year);
		printf("Enter faculty\n");
		scanf("%s", sc.fac);
		fwrite(&sc,sizeof(struct sec),1,fp3);
	}
	rewind(fp3);
	while(fread(&sc,sizeof(struct sec),1,fp3))
{
	printf("%s,%s,%d,%d,%s\n",sc.sid,sc.cno,sc.sem,sc.year,sc.fac);
}
 fclose(fp3);
	
	FILE *fp4;
	fp4=fopen("a.txt","w+");
	struct prereq p;
	for(i=0;i<5;i++)
	{
		printf("Enter course no.\n");
		scanf("%s",p.cno);
		printf("Enter prerequisite\n");
		scanf("%s",p.preno);
		
		fwrite(&p,sizeof(struct prereq),1,fp4);
	}
	rewind(fp4);
	while(fread(&p,sizeof(struct prereq),1,fp4))
{
//result=fread(&p,sizeof(struct prereq),1,fp4);
	printf("%s,%s\n",p.cno,p.preno);
}
 fclose(fp4);
 
 FILE *fp5;
	fp5=fopen("d.txt","w+");
	int d;
	struct graderep g;
	do
	{
		printf("Enter roll no.\n");
		scanf("%s", g.rollno);
		printf("Enter course no.\n");
		scanf("%s", g.cno);
		printf("Enter the grade\n");
		scanf(" %c", &g.grade);
		printf("Press 1 to continue\n");
		scanf("%d", &d);
		//fseek(fp5,sizeof(struct graderep)+i,SEEK_SET);
		fwrite(&g,sizeof(struct graderep),1,fp5);
	}while(d==1);
	
	rewind(fp5);
	while(fread(&g,sizeof(struct graderep),1,fp5))
{
	printf("%s,%s, %c\n",g.rollno,g.cno,g.grade);
}
 fclose(fp5);
 
 		//1.COE DISCIPLINE
fp1=fopen("b.txt","r");
printf("\n");
printf("\n");
printf("\t\t\t\t\t COE DISCIPLINE\n");

while(fread(&s,sizeof(struct stud),1,fp1))
{
	if(strcmp(s.branch,"coe")==0)
	{
		printf("%s,%s,%s,%s\n",s.name,s.rollno,s.deg,s.branch);
	}
}
fclose(fp1);

					//3.prerequisite for hci
printf("\n");
printf("\n");
printf("\t\t\t\t\t PREREQUISITE FOR HCI \n");
char x[20];

fp2=fopen("c.txt","r");
fp4=fopen("a.txt","r");
while(fread(&c,sizeof(struct course),1,fp2))
	{
	if(strcmp(c.cname,"hci")==0)
	{
		strcpy(x,c.cno);
	}
}

while(fread(&p,sizeof(struct prereq),1,fp4))
{
	if(strcmp(p.cno,x)==0)
	{
		//strcpy(y,p.preno);
		rewind(fp2);
		while(fread(&c,sizeof(struct course),1,fp2))
		{
			if(strcmp(p.preno,c.cno)==0)
				printf("%s\n", c.cname);
		}
	}
}

//2.DISPLAY COURSE NO. AND COURSE NAME OFFERED IN A GIVEN YEAR(2015)

printf("\n");
printf("\n");
printf("\t\t\t\t\t COURSE NAME AND COURSE NO. FOR 2015 BATCH \n\n");
char y[20];
fp2=fopen("c.txt","r");
fp3=fopen("e.txt","r");

while(fread(&sc,sizeof(struct sec),1,fp3))
{
	if(sc.year==2015)
	{
		strcpy(y,sc.cno);
	rewind(fp2);
while(fread(&c,sizeof(struct course),1,fp2))
 {
 	if(strcmp(c.cno,y)==0)
 		{
 		
		printf("%s %s\n", c.cname, c.cno);
		}
}
}
}

		//4.COURSES OFFERED BY GIVEN SPECIFIC FACULTY

printf("\n");
printf("\n");
printf("\t\t\t\t\t COURSES OFFERED BY GIVEN SPECIFIC FACULTY(UMARANI MA'M) \n\n");
char z[20];

fp2=fopen("c.txt","r");
fp3=fopen("e.txt","r");

while(fread(&sc,sizeof(struct sec),1,fp3))
{
	if(strcmp(sc.fac,"umarani")==0)
	{
		strcpy(z,sc.cno);
	rewind(fp2);
while(fread(&c,sizeof(struct course),1,fp2))
 {
 	if(strcmp(c.cno,z)==0)
 		{
		printf("%s \n", c.cname);
		}
}
}
}

		//5.CGPA
		
printf("\n");
printf("\n");
printf("\t\t\t\t\t CGPA \n\n");
int l;
fp2=fopen("c.txt","r");
fp5=fopen("d.txt","r");
fp1=fopen("b.txt","r");
float s_total;
float s_grade;

while(fread(&s,sizeof(struct stud),1,fp1))
{
   s_total=0;
   s_grade=0;
	rewind(fp5);
while(fread(&g,sizeof(struct graderep),1,fp5))
{
	if(strcmp(s.rollno,g.rollno)==0)
	{	//strcpy(k,g.cno);
		rewind(fp2);
		while(fread(&c,sizeof(struct course),1,fp2))
		{
			if(strcmp(g.cno,c.cno)==0)
			{
				l=c.cred;
				s_grade=s_grade+(c.cred)*(change(g.grade));
				s_total=s_total+c.cred;
			}	
							
		}
	}
}
g.cgpa=(s_grade/s_total);
	printf(" %f", g.cgpa);
}
}