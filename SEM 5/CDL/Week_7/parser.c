#include "la.c"

struct token cur;
FILE *f;

void declarations();
void dataTypes();
void identifierList();
void assignStat();

void valid()
{
    printf("-----------------------SUCCESS-----------------------");
    exit(EXIT_SUCCESS);
}

void invalid()
{
    printf("-----------------------ERROR-----------------------");
    exit(EXIT_FAILURE);
}

void declarations()
{
    dataTypes();
    identifierList();
    if(strcmp(cur.lexeme,";")==0)
    {
        cur=getNextToken(f);
        if(isDataType(cur.lexeme)==0)
        {
            return ;
        }
        declarations();
    }
    else
    {
        printf("Missing \";\" at Row : %d and Column : %d\n",cur.row,cur.col);
        exit(EXIT_FAILURE);
    }
}

void dataTypes()
{
    if(isDataType(cur.lexeme))
    {
        cur=getNextToken(f);
        return;
    }
    else
    {
        printf("Missing Data Type at Row : %d and Column : %d\n",cur.row,cur.col);
        exit(EXIT_FAILURE);
    }
}

void identifierList()
{
    if(strcmp(cur.type,"Identifier")==0)
    {
        cur=getNextToken(f);
        if(strcmp(cur.lexeme,",")==0)
        {
            cur=getNextToken(f);
            identifierList();
        }
        else if(strcmp(cur.type,"Identifier")==0)
        {
            printf("Missing \",\" at Row : %d and Column : %d\n",cur.row,cur.col);
            exit(EXIT_FAILURE);
        }
        else
        {
            return;
        }
    }
    else
    {
        printf("Missing Identifier at Row : %d and Column : %d\n",cur.row,cur.col);
        exit(EXIT_FAILURE);
    }
}

void assignStat()
{
    if(strcmp(cur.type,"Identifier")==0)
    {
        cur=getNextToken(f);
        if(strcmp(cur.lexeme,"=")==0)
        {
            cur=getNextToken(f);
            if(strcmp(cur.type,"Identifier")==0)
            {
                cur=getNextToken(f);
                if(strcmp(cur.lexeme,";")==0)
                {
                    cur=getNextToken(f);
                    return;
                }
                else
                {
                    printf("Missing \";\" at Row : %d and Column : %d\n",cur.row,cur.col);
                    exit(EXIT_FAILURE);
                }
            }
            else if(strcmp(cur.type,"Number")==0)
            {
                cur=getNextToken(f);
                if(strcmp(cur.lexeme,";")==0)
                {
                    cur=getNextToken(f);
                    return;
                }
                else
                {
                    printf("Missing \";\" at Row : %d and Column : %d\n",cur.row,cur.col);
                    exit(EXIT_FAILURE);
                }
            }
            else
            {
                printf("Missing Identifier at Row : %d and Column : %d\n",cur.row,cur.col);
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            printf("Missing \"=\" at Row : %d and Column : %d\n",cur.row,cur.col);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        printf("Missing Identifier at Row : %d and Column : %d\n",cur.row,cur.col);
        exit(EXIT_FAILURE);
    }
}

void program()
{
    cur=getNextToken(f);
    if(strcmp(cur.lexeme,"main")==0)
    {
        cur=getNextToken(f);
        if(strcmp(cur.lexeme,"(")==0)
        {
            cur=getNextToken(f);
            if(strcmp(cur.lexeme,")")==0)
            {
                cur=getNextToken(f);
                if(strcmp(cur.lexeme,"{")==0)
                {
                    cur=getNextToken(f);
                    declarations();
                    assignStat();
                    if(strcmp(cur.lexeme,"}")==0)
                    {
                        return;
                    }
                    else 
                    {
                    printf("Missing \"}\" at Row : %d and Column : %d\n",cur.row,cur.col);
                    exit(EXIT_FAILURE);
                    }
                }
                else 
                {
                    printf("Missing \"{\" at Row : %d and Column : %d\n",cur.row,cur.col);
                    exit(EXIT_FAILURE);
                }
            }
            else 
            {
                printf("Missing \"(\" at Row : %d and Column : %d\n",cur.row,cur.col);
                exit(EXIT_FAILURE);
            }
        }
        else 
        {
            printf("Missing \"(\" at Row : %d and Column : %d\n",cur.row,cur.col);
            exit(EXIT_FAILURE);
        }
    }
    else 
    {
        printf("\nMissing main function\n\n");
        exit(EXIT_FAILURE);
    }
}

void main(int argc,char** argv)
{
    if(argc<2)
    {
        perror("Insufficient Arguments\n");
        exit(EXIT_FAILURE);
    }
    if(argc>2)
    {
        perror("Extra Arguments\n");
        exit(EXIT_FAILURE);
    }
    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("ERROR\n");
        exit(EXIT_FAILURE);
    }
    program();
    printf("-----------------------COMPILED-----------------------\n");
    exit(EXIT_SUCCESS);
}
