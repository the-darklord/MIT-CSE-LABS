#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DOB
{
	int day;
	char* month;
	int year;
};
struct STU_INFO
{
	int reg_no;
	char* name;
	char address[100];
};
struct COLLEGE
{
	char* college_name;
	char university_name[100];
};
struct STUDENT
{
	struct DOB* pdob;
	struct STU_INFO stu;
	struct COLLEGE coll;
};
void read(int n,struct STUDENT *ptr)
{
	for(int i=0;i<n;i++)
	{
		printf("\n\nEnter Details of Student %d \n",i+1);
		printf("\nEnter Name : \t");
		scanf("%s",ptr->stu.name);
		printf("Enter Date : \t");
		scanf("%d",&ptr->pdob->day);
		printf("Enter Month : \t");
		scanf("%s",ptr->pdob->month);
		printf("Enter Year : \t");
		scanf("%d",&ptr->pdob->year);
		printf("Enter Reg.Num : \t");
		scanf("%d",&ptr->stu.reg_no);
		printf("Enter Address : \t");
		scanf("%s",ptr->stu.address);
		printf("Enter College Name : \t");
		scanf("%s",ptr->coll.college_name);
		printf("Enter University Name : \t");
		scanf("%s",ptr->coll.university_name);
		ptr++;
	}
}
void display(int n,struct STUDENT *ptr)
{
	for(int i=0;i<n;i++)
	{
		printf("\nDetails of Student %d \n",i+1);
		printf("\nName : %s \n",ptr->stu.name);
		printf("DOB : %d ",ptr->pdob->day);
		printf("%s",ptr->pdob->month);
		printf(" %d \n",ptr->pdob->year);
		printf("Address : %s \n",ptr->stu.address);
		printf("Reg.Num : %d \n",ptr->stu.reg_no);
		printf("College Name : %s \n",ptr->coll.college_name);
		printf("University Name : %s \n\n",ptr->coll.university_name);
		ptr++;
	}
}
void main()
{
	int n;
	printf("Enter No of students : \t");
	scanf("%d",&n);
	struct STUDENT *ptr;
	ptr=(struct STUDENT *)malloc(n*sizeof(struct STUDENT));
	for(int i=0;i<n;i++)
	{
		(ptr+i)->pdob=(struct DOB *)malloc(n*sizeof(struct DOB));
		(ptr+i)->pdob->month = (char*)malloc(n*sizeof(char));
		(ptr+i)->stu.name=(char *)malloc(n*sizeof(char));
		(ptr+i)->coll.college_name=(char *)malloc(n*sizeof(char));
	}
	ptr->pdob = (struct DOB*)malloc(n*sizeof(struct DOB));
	ptr->pdob->month = (char*)malloc(n*sizeof(char));
	ptr->stu.name = (char *)malloc(n*sizeof(char));
	ptr->coll.college_name = (char *)malloc(n*sizeof(char));
	read(n,ptr);
	display(n,ptr);
	free(ptr->pdob);
	free(ptr->pdob->month);
	free(ptr->stu.name);
	free(ptr->coll.college_name);
	free(ptr);
}