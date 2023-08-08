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
    char c;
    while(entry=readdir(dp))
    {
        lstat(entry->d_name,&statbuf);
        if(!S_ISDIR(statbuf.st_mode))
        {
            printf("Do you want to remove the file (Y|N) : %s\n",entry->d_name);
            scanf(" %c",&c);
            if(c=='Y'||c=='y')
            {
                remove(entry->d_name);
            }
        }
    }
    chdir("..");
}

void main()
{
    char dir[256];
    printf("Enter Directory Name : \t");
    scanf("%s",dir);
    printFiles(dir);
}