#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE *ptr1,*ptr2;
	char c,fname[100];
	printf("Enter Filename to Read : \t");
	scanf("%s",fname);
	ptr1=fopen(fname,"r");
	if(!ptr1)
	{
		printf("Cannot open file %s \n", fname);
		exit(0);
	}
	printf("Enter Filename to Write to : \t");
	scanf("%s",fname);
	ptr2=fopen(fname,"w+");
	fseek(ptr1, 0, SEEK_END);
	long fileSize = ftell(ptr1);
	fseek(ptr1, 0, SEEK_SET);
	long pos = fileSize - 1;
	printf("Size of File : %ld\n",fileSize);
	while (pos >= 0)
	{
	    fseek(ptr1, pos, SEEK_SET);
	    c = fgetc(ptr1);
	    fputc(c,ptr2);
	    pos--;
	}
	fclose(ptr1);
	fclose(ptr2);
}