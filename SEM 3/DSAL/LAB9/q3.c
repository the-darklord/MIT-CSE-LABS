#include <stdio.h>
#include "CLL.c"

void main()
{
    Nodeptr first=NULL;
    first=InsertLast(first,'h');
    first=InsertLast(first,'c');
    first=InsertLast(first,'m');
    Display(first);
}