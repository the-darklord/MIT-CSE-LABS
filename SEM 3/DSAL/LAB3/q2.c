#include <stdio.h>
#include <stdlib.h>

struct Student
{
	char name[100];
	long int rollno;
	float cgpa;
};
void read(int n,struct Student *p)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter name,rollno,cgpa of student %d \n",i+1);
		scanf("%s %ld %f",p->name,&p->rollno,&p->cgpa);
		p++;
	}
}
void display(int n,struct Student *ptr)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\nDetails of Student %d are \n",i+1);
		printf("Name : %s \n",ptr->name);
		printf("Roll Number : %ld \n",ptr->rollno);
		printf("CGPA : %f \n",ptr->cgpa);
		ptr++;
	}
}
void sort(int n,struct Student *ptr)
{
	int i,j;
	struct Student temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(ptr[j].rollno > ptr[j+1].rollno)
			{
				temp = ptr[j];
				ptr[j] = ptr[j+1];
				ptr[j+1] = temp;
			}
		}
	}
}
void main()
{
	int n;
	printf("Enter no of students : \t");
	scanf("%d",&n);
	struct Student s[n],*ptr;
	ptr=(struct Student*)malloc(n*sizeof(struct Student));
	read(n,ptr);
	display(n,ptr);
	sort(n,ptr);
	printf("\nSorted according to Roll Number \n");
	display(n,ptr);
}