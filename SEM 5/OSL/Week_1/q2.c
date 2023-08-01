#include "include.h"

void main(int argc,char* argv[])
{
	if(argc != 2)
	{
		printf("Insufficient Arguments\n");
		exit(1);
	}
	int fd=open(argv[1],O_RDONLY);
	if(fd==-1)
	{
		printf("File Not Found\n");
		exit(1);
	}
	char c,temp[100];
	int i=0,k=0;
	while(read(fd,&c,1)>0)
	{
		if(c!='\n')
		{
			temp[i]=c;
			i++;
		}
		else
		{
			k++;
			temp[i]='\0';
			i=0;
			printf("Line:%d \t %s \n", k,temp);
			if(k%20==0)
			{
				char key;
				printf("\n\nPress Any Key to Continue : \t");
                scanf("%c",&key);
				printf("\n\n");
            }
		}
	}
	exit(0);
}