#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void main(int argc,char* argv[100])
{
    if(argc!=2)
    {
        printf("ERROR Insufficient Arguments\n");
        return;
    }
    struct stat sbuf;
    int ret=stat(argv[1],&sbuf);
    if(ret==-1)
    {
        perror("ERROR !!!\n");
        return;
    }
    printf("Device ID containing the file : %ld\t\n",sbuf.st_dev);
    printf("Inode Number : %ld\t\n",sbuf.st_ino);
    printf("Permissions : %d\t\n",sbuf.st_mode);
    printf("No.of Hard links : %ld\t\n",sbuf.st_nlink);
    printf("Owner User ID : %d\t\n",sbuf.st_uid);
    printf("Group User ID : %d\t\n",sbuf.st_gid);
    printf("Device ID : %ld\t\n",sbuf.st_rdev);
    printf("Total Size in bytes : %ld\t\n",sbuf.st_size);
    printf("Block Size : %ld\t\n",sbuf.st_blksize);
    printf("No. of Blocks allocated : %ld\t\n",sbuf.st_blocks);
    printf("Last Access Time : %ld\t\n",sbuf.st_atime);
    printf("Last Modification Time : %ld\t\n",sbuf.st_mtime);
    printf("Last Status Change Time : %ld\t\n",sbuf.st_ctime);
}