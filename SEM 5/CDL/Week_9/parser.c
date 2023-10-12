#include "la.c"

struct token cur;
FILE *f;

void program();
void declarations();
void statementList();
void identifierList();
void statement();
void dataTypes();
void assignStat();
void expn();
void simpleExpn();
void ePrime();
void relOp();
void sePrime();
void addOp();
void term();
void tPrime();
void factor();
void mulOp();
void decisionStat();
void dPrime();
void loopingStat();


void valid()
{
    printf("-----------------------SUCCESS-----------------------\n");
    exit(EXIT_SUCCESS);
}

void invalid(char* str)
{
    printf("Missing %s at Row : %d and Column : %d\n",str,cur.row,cur.col);
    exit(EXIT_FAILURE);
}

void match()
{
    cur=getNextToken(f);
}

void declarations()
{
    dataTypes();
    identifierList();
    if(strcmp(cur.lexeme,";")==0)
    {
        match();
        if(isDataType(cur.lexeme))
        {
            declarations();
        }
        else
        {
            return;
        }
        
    }
    else
    {
        invalid("\";\"");
    }
}

void dataTypes()
{
    if(isDataType(cur.lexeme))
    {
        match();
        return;
    }
    else
    {
        invalid("Data Type");
    }
}

void identifierList()
{
    if(strcmp(cur.type,"Identifier")==0)
    {
        match();
        if(strcmp(cur.lexeme,",")==0)
        {
            match();
            identifierList();
        }
        else if(strcmp(cur.type,"[")==0)
        {
            match();
            if(strcmp(cur.type,"Number")==0)
            {
                match();
                if(strcmp(cur.type,"]")==0)
                {
                    match();
                    if(strcmp(cur.lexeme,",")==0)
                    {
                        match();
                        identifierList();
                    }
                    else
                    {
                        return;
                    }
                }
                else
                {
                    invalid("\"]\"");
                }
            }
            else
            {
                invalid("Number");
            }
        }
        else if(strcmp(cur.type,"Identifier")==0)
        {
            invalid("\",\"");
        }
        else
        {
            return;
        }
    }
    else
    {
        invalid("Identifier");
    }
}

void statementList()
{
    if(strcmp(cur.type,"Identifier")==0||strcmp(cur.type,"Keyword")==0)
    {
        statement();
        statementList();
    }
    else
    {
        return;
    }
}

void statement()
{
    if(strcmp(cur.type,"Identifier")==0)
    {
        assignStat();
        if(strcmp(cur.lexeme,";")==0)
        {
            match();
            return;
        }
        else
        {
            invalid("\";\"");
        }
    }
    else if(strcmp(cur.lexeme,"if")==0)
    {
        decisionStat();
    }
    else if(strcmp(cur.lexeme,"while")==0||strcmp(cur.lexeme,"for")==0)
    {
        loopingStat();
    }
    else
    {
        return;
    }
}

void expn()
{
    simpleExpn();
    ePrime();
}

int isRelOp(const char* str)
{
    if(strcmp(str,"==")==0)
    {
        return 1;
    }
    else if(strcmp(str,"!=")==0)
    {
        return 1;
    }
    else if(strcmp(str,"<=")==0)
    {
        return 1;
    }
    else if(strcmp(str,">=")==0)
    {
        return 1;
    }
    else if(strcmp(str,">")==0)
    {
        return 1;
    }
    else if(strcmp(str,"<")==0)
    {
        return 1;
    }
    return 0;
}

void ePrime()
{
    if(isRelOp(cur.lexeme))
    {
        relOp();
        simpleExpn();
    }
    else
    {
        return;
    }
}

void simpleExpn()
{
    term();
    sePrime();
}

int isAddOp(const char* str)
{
    if(strcmp(str,"+")==0)
    {
        return 1;
    }
    else if(strcmp(str,"-")==0)
    {
        return 1;
    }
    return 0;
}

void sePrime()
{
    if(isAddOp(cur.lexeme))
    {
        addOp();
        term();
        sePrime();
    }
    else
    {
        return;
    }
}

void term()
{
    factor();
    tPrime();
}

int isMulOp(const char* str)
{
    if(strcmp(str,"*")==0)
    {
        return 1;
    }
    else if(strcmp(str,"/")==0)
    {
        return 1;
    }
    else if(strcmp(str,"%")==0)
    {
        return 1;
    }
    return 0;
}

void tPrime()
{
    if(isMulOp(cur.lexeme))
    {
        mulOp();
        factor();
        tPrime();
    }
    else
    {
        return;
    }
}

void factor()
{
    if(strcmp(cur.type,"Identifier")==0)
    {
        match();
    }
    else if(strcmp(cur.type,"Number")==0)
    {
        match();
    }
    else
    {
        invalid("Identifier / Number");
    }

}

void relOp()
{
    if(strcmp(cur.lexeme,"==")==0)
    {
        match();
    }
    else if(strcmp(cur.lexeme,"!=")==0)
    {
        match();
    }
    else if(strcmp(cur.lexeme,"<=")==0)
    {
        match();
    }
    else if(strcmp(cur.lexeme,">=")==0)
    {
        match();
    }
    else if(strcmp(cur.lexeme,">")==0)
    {
        match();
    }
    else if(strcmp(cur.lexeme,"<")==0)
    {
        match();
    }
    else
    {
        invalid("Relational Operator");
    }
}

void addOp()
{
    if(strcmp(cur.lexeme,"+")==0)
    {
        match();
    }
    else if(strcmp(cur.lexeme,"-")==0)
    {
        match();
    }
    else
    {
        invalid("Relational Operator");
    }
}

void mulOp()
{
    if(strcmp(cur.lexeme,"*")==0)
    {
        match();
    }
    else if(strcmp(cur.lexeme,"/")==0)
    {
        match();
    }
    else if(strcmp(cur.lexeme,"%")==0)
    {
        match();
    }
    else
    {
        invalid("Relational Operator");
    }
}

void assignStat()
{
    if(strcmp(cur.type,"Identifier")==0)
    {
        match();
        if(strcmp(cur.lexeme,"=")==0)
        {
            match();
            expn();
        }
        else
        {
            invalid("\"=\"");
        }
    }
    else
    {
        invalid("Identifier");
    }
}

void program()
{
    match();
    if(strcmp(cur.lexeme,"main")==0)
    {
        match();
        if(strcmp(cur.lexeme,"(")==0)
        {
            match();
            if(strcmp(cur.lexeme,")")==0)
            {
                match();
                if(strcmp(cur.lexeme,"{")==0)
                {
                    match();
                    declarations();
                    statementList();
                    if(strcmp(cur.lexeme,"}")==0)
                    {
                        return;
                    }
                    else 
                    {
                        invalid("\"}\"");
                    }
                }
                else 
                {
                    invalid("\"{\"");
                }
            }
            else 
            {
                invalid("\")\"");
            }
        }
        else 
        {
            invalid("\"(\"");
        }
    }
    else 
    {
        invalid("Main Function");
    }
}

void decisionStat()
{
    if(strcmp(cur.lexeme,"if")==0)
    {
        match();
        if(strcmp(cur.lexeme,"(")==0)
        {
            match();
            expn();
            if(strcmp(cur.lexeme,")")==0)
            {
                match();
                if(strcmp(cur.lexeme,"{")==0)
                {
                    match();
                    statementList();
                    if(strcmp(cur.lexeme,"}")==0)
                    {
                        match();
                        dPrime();
                    }
                    else
                    {
                        invalid("\"}\"");
                    }
                }
                else
                {
                    invalid("\"{\"");
                }
            }
            else
            {
                invalid("\")\"");
            }
        }
        else
        {
            invalid("\"(\"");
        }
    }
    else
    {
        invalid("if");
    }
}

void dPrime()
{
    if(strcmp(cur.lexeme,"else")==0)
    {
        match();
        if(strcmp(cur.lexeme,"{")==0)
        {
            match();
            statementList();
            if(strcmp(cur.lexeme,"}")==0)
            {
                match();
                if(strcmp(cur.lexeme,"else")==0)
                {
                    match();
                    dPrime();
                }
                else
                {
                    return;
                }
            }
            else
            {
                invalid("\"}\"");
            }
        }
        else
        {
            invalid("\"{\"");
        }
    }
    else
    {
        invalid("else");
    }
}

void loopingStat()
{
    if(strcmp(cur.lexeme,"while")==0)
    {
        match();
        if(strcmp(cur.lexeme,"(")==0)
        {
            match();
            expn();
            if(strcmp(cur.lexeme,")")==0)
            {
                match();
                if(strcmp(cur.lexeme,"{")==0)
                {
                    match();
                    statementList();
                    if(strcmp(cur.lexeme,"}")==0)
                    {
                        match();
                    }
                    else
                    {
                        invalid("\"}\"");
                    }
                }
                else
                {
                    invalid("\"{\"");
                }
            }
            else
            {
                invalid("\")\"");
            }
        }
        else
        {
            invalid("\"(\"");
        }
    }
    else if(strcmp(cur.lexeme,"for")==0)
    {
        match();
        if(strcmp(cur.lexeme,"(")==0)
        {
            match();
            assignStat();
            if(strcmp(cur.lexeme,";")==0)
            {
                match();
                expn();
                if(strcmp(cur.lexeme,";")==0)
                {
                    match();
                    assignStat();
                    if(strcmp(cur.lexeme,")")==0)
                    {
                        match();
                        if(strcmp(cur.lexeme,"{")==0)
                        {
                            match();
                            statementList();
                            if(strcmp(cur.lexeme,"}")==0)
                            {
                                match();
                            }
                            else
                            {
                                invalid("\"}\"");
                            }
                        }
                        else
                        {
                            invalid("\"{\"");
                        }
                    }
                    else
                    {
                        invalid("\")\"");
                    }
                }
                else
                {
                    invalid("\";\"");
                }
            }
            else
            {
                invalid("\";\"");
            }
        }
        else
        {
            invalid("\"(\"");
        }
    }
    else
    {
        invalid("Looping Statement");
    }
}

void main(int argc,char** argv)
{
    assert(argc==2);
    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        perror("ERROR\n");
        exit(EXIT_FAILURE);
    }
    program();
    valid();
}