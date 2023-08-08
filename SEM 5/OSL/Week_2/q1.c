#include "include.h"

void main()
{
    char dir[256];
    printf("Enter Directory Name : \t");
    scanf("%s",dir);
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    dp=opendir(dir);
    if(!dp)
    {
        fprintf(stderr,"Cannot open directory : %s\n",dir);
        exit(0);
    }
    while(entry=readdir(dp))
    {
        lstat(entry->d_name,&statbuf);
        if(strcmp(entry->d_name,".")==0 || strcmp(entry->d_name,"..")==0)
        {
            continue;
        }
        printf("%s\t\t\t",entry->d_name);
        if(S_ISDIR(statbuf.st_mode))
        {
            printf(S_ISDIR(statbuf.st_mode)  ? "d" : "-");
        }
        printf(statbuf.st_mode & S_IRUSR ? "r" : "-");
        printf(statbuf.st_mode & S_IWUSR ? "w" : "-");
        printf(statbuf.st_mode & S_IXUSR ? "x" : "-");
        printf(statbuf.st_mode & S_IRGRP ? "r" : "-");
        printf(statbuf.st_mode & S_IWGRP ? "w" : "-");
        printf(statbuf.st_mode & S_IXGRP ? "x" : "-");
        printf(statbuf.st_mode & S_IROTH ? "r" : "-");
        printf(statbuf.st_mode & S_IWOTH ? "w" : "-");
        printf(statbuf.st_mode & S_IXOTH ? "x" : "-");
        printf("\n");
    }
    closedir(dp);
}