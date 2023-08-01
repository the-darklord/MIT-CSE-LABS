#include "include.h"

void main(int argc,char* argv[])
{
  if(argc != 3)
  {
    printf("Insufficient Arguments\n");
    exit(1);
  }
  int fd=open(argv[1],O_RDONLY);
  int fl=open(argv[2],O_CREAT|O_WRONLY,S_IRUSR|S_IWUSR);
  if(fd==-1)
  {
    printf("File Not Found\n");
    exit(1);
  }
  char c;
  while(read(fd,&c,1)==1)
  {
    write(fl,&c,1);
  }
}