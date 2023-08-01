#include "include.h"

void main(int argc,char* argv[])
{
	if(argc != 3)
	{
		printf("Insufficient Arguments\n");
		exit(1);
	}
	int fd=open(argv[2],O_RDONLY);
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
			temp[i++]=c;
		}
		else
		{
			k++;
			temp[i]='\0';
			i=0;
			if(strstr(temp,argv[1]))
			{
                printf("Line:%d \t %s \n", k,temp);
            }
		}
	}
	exit(0);
}