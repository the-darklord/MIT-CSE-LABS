#include <stdio.h>
#include <stdlib.h>

struct Employee
{
	char name[100];
	struct DOB
	{
		int day;
		int month;
		int year;
	}dob;
	struct Address
	{
		int h_no;
		int zip_code;
		char state[100];
	}add;
};
void read(int n,struct Employee *ptr)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter name,DOB,address for Employee %d : \n",i+1);
		scanf("%s %d %d %d %d %d %s",ptr->name,&ptr->dob.day,&ptr->dob.month,&ptr->dob.year,&ptr->add.h_no,&ptr->add.zip_code,ptr->add.state);
		ptr++;
	}
}
void display(int n,struct Employee *ptr)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\nDetails of Employee %d are \n",i+1);
		printf("Name : %s \n",ptr->name);
		printf("DOB : %d/%d/%d \n",ptr->dob.day,ptr->dob.month,ptr->dob.year);
		printf("Address : %d , %d , %s \n",ptr->add.h_no,ptr->add.zip_code,ptr->add.state);
		ptr++;
	}
}
void main()
{
	int n;
	printf("Enter Number of Employees : \t");
	scanf("%d",&n);
	struct Employee *ptr;
	ptr=(struct Employee *)malloc(n*sizeof(struct Employee));
	read(n,ptr);
	display(n,ptr);
}
