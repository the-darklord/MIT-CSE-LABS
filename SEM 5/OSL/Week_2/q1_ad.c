#include "include.h"
//Incomplete
void Sort(char** fnames,int k)
{
    for(i=0;i<n;i++)
    {
      for(j=i+1;j<n;j++)
      {
        if(strcmp(str[i],str[j])>0)
        {
            strcpy(s,str[i]);
            strcpy(str[i],str[j]);
            strcpy(str[j],s);
        }
      }
   }
}

void printFiles(char* dir)
{
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    dp=opendir(dir);
    char fnames[100][100];
    int k=0;
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
            strcpy(fnames[k++],entry->d_name);
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