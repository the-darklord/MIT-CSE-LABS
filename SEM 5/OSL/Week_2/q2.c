#include "include.h"

void printFiles(char* dir)
{
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    dp=opendir(dir);
    if(!dp)
    {
        printf("Cannot open directory : %s\n",dir);
        exit(0);
    }
    chdir(dir);
    while(entry=readdir(dp))
    {
        lstat(entry->d_name,&statbuf);
        if(S_ISDIR(statbuf.st_mode))
        {
            if(strcmp(entry->d_name,".")==0 || strcmp(entry->d_name,"..")==0)
            {
                continue;
            }
            printf("%s\n",entry->d_name);
            printf("\n");
            printFiles(entry->d_name);
        }
        else
        {
            printf("%s\n",entry->d_name);
        }
    }
    printf("\n");
    chdir("..");
}

void main()
{
    char dir[256];
    printf("Enter Directory Name : \t");
    scanf("%s",dir);
    printFiles(dir);
}