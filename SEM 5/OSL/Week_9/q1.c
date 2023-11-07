#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int algo;

typedef struct mab Mab;
typedef Mab* MabPtr;

struct mab
{
    int offset;
    int size;
    int allocated;
    MabPtr next;
    MabPtr prev;
};

MabPtr memChk(MabPtr m,int size)
{
    MabPtr temp=m;
    MabPtr ret = NULL;
    while(temp!=NULL)
    {
        if(algo == 1)
        {
            if(temp->size - temp->allocated >= size)
            {
                if(ret==NULL)
                {
                    ret = temp;
                }
                else
                {
                    if(ret->size - ret->allocated >= temp->size - temp->allocated)
                    {
                        ret = temp;
                    }
                }
            }
        }
        else if(algo == 2)
        {
            if(temp->size - temp->allocated >= size)
            {
                ret = temp;
                break;
            }
        }
        else if(algo == 3)
        {
            if(temp->size - temp->allocated >= size)
            {
                if(ret==NULL)
                {
                    ret = temp;
                }
                else
                {
                    if(ret->size - ret->allocated <= temp->size - temp->allocated)
                    {
                        ret = temp;
                    }
                }
            }
        }
        else
        {
            printf("----------INCORRECT CHOICE----------\n");
            exit(EXIT_FAILURE);
        }
        temp = temp->next;
    }
    return ret;
}

MabPtr getNode()
{
    return (MabPtr)malloc(sizeof(Mab));
}

MabPtr takeInput()
{
    int n;
    printf("Enter No. of Blocks : \t");
    scanf("%d",&n);
    MabPtr head = NULL;
    int off=0;
    int size;
    int allocated;
    MabPtr prev=NULL;
    for(int i=0;i<n;i++)
    {
        printf("\n----------BLOCK %d----------\n",i+1);
        printf("Enter Size : \t");
        scanf("%d",&size);
        printf("Enter Allocated Size : \t");
        scanf("%d",&allocated);
        printf("---------------------------\n");
        if(allocated > size)
        {
            printf("\n----------NOT POSSIBLE----------\n");
            i--;
            continue;
        }
        head=getNode();
        head->offset = off;
        head->size = size;
        head->allocated = allocated;
        head->next = NULL;
        head->prev = prev;
        off += head->size;
        if(prev != NULL)
        {
            prev->next=head;
        }
        prev = head;
        head = head->next;
    }
    while(prev->prev)
    {
        prev = prev->prev;
    }
    return prev;
}

MabPtr memAlloc(MabPtr m,int size)
{
    m->allocated += size;
    return m;
}

MabPtr memFree(MabPtr m)
{
    m->allocated = 0;
    return m;
}

void DisplayMemoryBlocks(MabPtr m)
{
    MabPtr temp = m;
    if(!temp)
    {
        printf("----------NO MEMORY BLOCKS----------\n\n");
        return;
    }
    int i=1;
    printf("\n----------DISPLAY----------\n\n");
    while(temp)
    {
        printf("----------BLOCK %d----------\n",i);
        printf("OFFSET\t\t:\t%d\n",temp->offset);
        printf("SIZE\t\t:\t%d\n",temp->size);
        printf("ALLOCATED\t:\t%d\n",temp->allocated);
        printf("----------------------------\n\n");
        i++;
        temp = temp->next;
    }
}

void main()
{
    MabPtr head=takeInput();
    DisplayMemoryBlocks(head);
    printf("----------ALGORITHMS----------\n");
    printf("1> BEST FIT\n2> FIRST FIT\n3> WORST FIT\n");
    printf("------------------------------\n\n");
    printf("Enter Alogorithm to Implement : \t");
    scanf("%d",&algo);
    printf("Enter Size to check and allocate : \t");
    int size;
    scanf("%d",&size);
    MabPtr ptr = memChk(head,size);
    ptr = memAlloc(ptr,size);
    DisplayMemoryBlocks(head);
    ptr = memFree(ptr);
    DisplayMemoryBlocks(head);
}
