#include <mysql.h>
#include <stdio.h>

void insertRecords(MYSQL *conn);
void deleteRecord(MYSQL *conn,unsigned int Ssn);
void updateRecord(MYSQL *conn,unsigned int Ssn);
void printAllRecords(MYSQL *conn);
void viewSsnDetails(MYSQL *conn,unsigned int Ssn);
void printRecordsDno(MYSQL *conn,int Dno);

void main()
{
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;

	char *server = "localhost";
	char *user = "root";
	char *password = "qaz";
	char *database = "COMPANY";

	conn=mysql_init(NULL);

	/*Connect to database*/
	//mysql->port, mysql->unix_socket, mysql->client_flag
	if(!mysql_real_connect(conn,server,user,password,database,3306,NULL,0))
	{
		fprintf(stderr, "%s\n",mysql_error(conn));
		exit(1);
	}

	/*Defining variables for ATTRIBUTES*/


	char Fname[21],Minit,Lname[21],Bdate[11],Address[100],Sex,Mobile[11];
	int Ssn,Super_ssn,Dno;
	double Salary;

	/*Create MYSQL STATEMENT variable*/
	char statement[512];

	int choice; 
	while(1)
	{
		printf("\nEnter your choice\n"
			"1. Insert a record\n"
			"2. Delete a record\n"
			"3. Update record details\n"
			"4. View ALL records\n"
			"5. Filter records by Dno\n"
			"6. View Details by Ssn\n"
			"7. Exit\n");

		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				insertRecords(conn);
			break;

			case 2:
				printf("\nEnter Ssn to DELETE\n# ");
				scanf("%d",&Ssn);

				deleteRecord(conn,Ssn);
			break;

			case 3:
				printf("\nEnter Ssn to UPDATE DETAILS\n# ");
				scanf("%u",&Ssn);
				updateRecord(conn,Ssn);

			break;

			case 4:
				printAllRecords(conn);
			break;

			case 5:
				printf("Enter Dno to view records\n# ");
				scanf("%d",&Dno);

				printRecordsDno(conn,Dno);

			break;

			case 6:
				printf("\nEnter Ssn to get Details\n# ");
				scanf("%u",&Ssn);

				viewSsnDetails(conn,Ssn);
			break;

			case 7:
				exit(0);
			break;
		}		
	}


}

void insertRecords(MYSQL *conn)
{
	/*Defining variables for ATTRIBUTES*/
	char Fname[21],Minit,Lname[21],Bdate[11],Address[100],Sex,Mobile[11];
	unsigned int Ssn,Super_ssn;
	int Dno;
	double Salary;

	/*Create MYSQL STATEMENT variable*/
	char statement[512];

	printf("\nEnter '0' Ssn to end INSERTION\n");
	printf("Enter Ssn\n# ");
	scanf("%u",&Ssn);

	do
	{
		printf("\nEnter Fname, Minit, Lname\n# ");
		scanf("%s %c %s",Fname,&Minit,Lname);

		printf("\nEnter Super_ssn, Gender(M/F), Bdate, Dno, Salary\n# ");
		scanf("%u %c %s %d %lf",&Super_ssn,&Sex,Bdate,&Dno,&Salary);

		printf("\nEnter Address, Mobile No.\n# ");
		scanf("%s %s",Address,Mobile);

		snprintf(statement,512,"INSERT INTO EMPLOYEE values('%s','%c','%s',%d,'%s','%s','%c',%lf,%u,%d,'%s');",
			Fname,Minit,Lname,Ssn,Bdate,Address,Sex,Salary,Super_ssn,Dno,Mobile);

		//printf("%s\n",statement);
		if(mysql_query(conn,statement))
		{
			fprintf(stderr, "%s\n",mysql_error(conn));
			return;
		}

		printf("\nEnter Ssn\n# ");
		scanf("%u",&Ssn);
	}while(Ssn!=0);
	
}

void deleteRecord(MYSQL *conn,unsigned int Ssn)
{	
	char statement[100];
	snprintf(statement,100,"DELETE from EMPLOYEE where Ssn=%u;",Ssn);

	if(mysql_query(conn,statement))
	{
		fprintf(stderr, "%s\n",mysql_error(conn));
		return;
	}
}

void updateRecord(MYSQL *conn,unsigned int Ssn)
{
	char Fname[21],Minit,Lname[21],Bdate[11],Address[100],Sex,Mobile[11];
	unsigned int Super_ssn;
	int Dno;
	double Salary;

	char statement[512];

	printf("\nEnter Fname, Minit, Lname\n# ");
	scanf("%s %c %s",Fname,&Minit,Lname);

	printf("\nEnter Super_ssn, Gender(M/F), Bdate, Dno, Salary\n# ");
	scanf("%u %c %s %d %lf",&Super_ssn,&Sex,Bdate,&Dno,&Salary);

	printf("\nEnter Address, Mobile No.\n# ");
	scanf("%s %s",Address,Mobile);

	snprintf(statement,512,"UPDATE EMPLOYEE set Fname='%s', Minit='%c', Lname='%s',"
		"Super_ssn=%u, Sex='%c', Bdate='%s', Dno=%d, Salary=%lf, Address='%s', MOBILE_NO='%s' where Ssn=%u;",
		Fname,Minit,Lname,Super_ssn,Sex,Bdate,Dno,Salary,Address,Mobile,Ssn);

	if(mysql_query(conn,statement))
	{
		fprintf(stderr, "%s\n",mysql_error(conn));
		return;
	}

}

//prints Ssn,Fname,Lname,Dno for all records
void printAllRecords(MYSQL *conn)
{
	if(mysql_query(conn,"Select Ssn, Fname, Lname, Dno from EMPLOYEE;"))
	{
		fprintf(stderr, "%s\n",mysql_error(conn));
		return;
	}

	MYSQL_RES *res;
	MYSQL_ROW row;

	//collecting result of QUERY
	res = mysql_use_result(conn);
	unsigned int num_fields = mysql_num_fields(res);
	unsigned long *lengths = mysql_fetch_lengths(res);

	int i;
	printf(" _________________________________________________________________\n");
	printf("|\t%-10s|\t%-10s|\t%-10s|\t%-10s|\n","Ssn","Fname","Lname","Dnumber");
	printf("-------------------------------------------------------------------\n|");
	while((row = mysql_fetch_row(res))!=NULL)
	{	
		for(i=0;i<num_fields;++i)
			printf("\t%-10s|",row[i]);
		printf("\n|");
	}

	printf("-----------------------------------------------------------------|\n");

	mysql_free_result(res);
}

void printRecordsDno(MYSQL *conn,int Dno)
{
	char statement[512];
	snprintf(statement,512,"Select Ssn, Fname, Lname, Dno from EMPLOYEE where Dno=%d;",Dno);

	if(mysql_query(conn,statement))
	{
		fprintf(stderr, "%s\n",mysql_error(conn));
		return;
	}

	MYSQL_RES *res;
	MYSQL_ROW row;

	//collecting result of QUERY
	res = mysql_use_result(conn);
	unsigned int num_fields = mysql_num_fields(res);
	unsigned long *lengths = mysql_fetch_lengths(res);

	int i;
	printf(" _________________________________________________________________\n");
	printf("|\t%-10s|\t%-10s|\t%-10s|\t%-10s|\n","Ssn","Fname","Lname","Dnumber");
	printf("-------------------------------------------------------------------\n|");
	while((row = mysql_fetch_row(res))!=NULL)
	{	
		for(i=0;i<num_fields;++i)
			printf("\t%-10s|",row[i]);
		printf("\n|");
	}

	printf("-----------------------------------------------------------------|\n");

	mysql_free_result(res);
}

void viewSsnDetails(MYSQL *conn,unsigned int Ssn)
{
	char statement[512];
	snprintf(statement,512,"Select * from EMPLOYEE where Ssn=%u;",Ssn);

	if(mysql_query(conn,statement))
	{
		fprintf(stderr, "%s\n",mysql_error(conn));
		return;
	}

	MYSQL_RES *res;
	MYSQL_ROW row;

	//collecting result of QUERY
	res = mysql_use_result(conn);
	unsigned int num_fields = mysql_num_fields(res);

	if((row = mysql_fetch_row(res))==NULL)
	{
		printf("The Ssn DOES NOT EXIST!!!\n");
		return;
	}

	else
	{	
		printf("Ssn       : %s\n",row[3]);
		printf("Name      : %s %s %s\n",row[0],row[1],row[2]);
		printf("Gender    : %s\n",row[6]);
		printf("Bdate     : %s\n",row[4]);
		printf("Address   : %s\n",row[5]);
		printf("Salary    : %s\n",row[7]);
		printf("Super_ssn : %s\n",row[8]);
		printf("Dno       : %s\n",row[9]);
		printf("Mobile    : %s\n",row[10]);
	}
	printf("\n");

	mysql_free_result(res);
}