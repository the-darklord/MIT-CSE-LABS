#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE *ptr;
	char c,fname[100];
	printf("Enter Filename to Read : \t");
	scanf("%s",fname);
	ptr=fopen(fname,"r");
	int lines=0,chars=0;
	if(!ptr)
	{
		printf("Cannot open file %s \n", fname);
		exit(0);
	}
	c=fgetc(ptr);
	while(c!=EOF)
	{
		if(c=='\n')
		{
			lines++;
		}
		else
		{
			chars++;
		}
		c=fgetc(ptr);
	}
	fclose(ptr);
	lines++;
	printf("No. of lines : %d\nNo. of Characters : %d\n",lines,chars);
}