#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE *ptr1,*ptr2,*ptr3;
	char c1,c2,fname[100];
	printf("Enter First Filename to Read : \t");
	scanf("%s",fname);
	ptr1=fopen(fname,"r");
	printf("Enter Second Filename to Read : \t");
	scanf("%s",fname);
	ptr2=fopen(fname,"r");
	if(!ptr1||!ptr2)
	{
		printf("Cannot open a file \n");
		exit(0);
	}
	printf("Enter Filename to Write to : \t");
	scanf("%s",fname);
	ptr3=fopen(fname,"w+");
	c1=fgetc(ptr1);
	c2=fgetc(ptr2);
	while(c1!=EOF||c2!=EOF)
	{
		while(c1!='\n'&&c1!=EOF)
		{
			fputc(c1,ptr3);
			c1=fgetc(ptr1);
		}
		if(c1=='\n')
		{
			fputc('\n',ptr3);
		}
		while(c2!='\n'&&c2!=EOF)
		{
			fputc(c2,ptr3);
			c2=fgetc(ptr2);
		}
		if(c2=='\n')
		{
			fputc('\n',ptr3);
		}
		c1=fgetc(ptr1);
		c2=fgetc(ptr2);
	}
	fclose(ptr1);
	fclose(ptr2);
	fclose(ptr3);
}