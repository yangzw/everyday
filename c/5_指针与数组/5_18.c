/*
 * 处理复杂声明的dcl
 * dcl文法见书本106面
 * 以及习题解的97面
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAXTOKEN    100

enum {NAME, PARENS, BRACKETS};
enum {YES,NO};

void dcl(void);
void dirdcl(void);
void parmdcl(void);
void dclspec(void);
int typespec(void);
int typequal(void);
int compare(char**, char**);
int gettoken(void);
void error(char*);

int tokentype;
int pretoken = NO;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[100];

int main()
{
    while(gettoken() != EOF)
    {
        strcpy(datatype,token);
        out[0] = '\0';
        dcl();
        if(tokentype != '\n')
            printf("syntax error\n");
        printf("%s: %s %s\n",name,out,datatype);
    }
    return 0;
}

void dcl(void)
{
    int ns;
    for(ns = 0;gettoken() == '*';)
        ns++;
    dirdcl();
    while(ns--)
        strcat(out," pointer to");
}

void dirdcl(void)
{
    int type;

    if(tokentype == '(')
    {
        dcl();
        if(tokentype != ')')
            error("error:missing )\n");
    }
    else if(tokentype == NAME)
    {
        if(name[0] == '\0')
            strcpy(name,token);
    }
    else
        pretoken = YES;
    while((type = gettoken()) == PARENS || type == BRACKETS || type == '(')
    {
        if(type == PARENS)
            strcat(out," function returning");
        else if(type == '(')
        {
            strcat(out," function expecting");
            parmdcl();
            strcat(out," and returning");
        }
        else
        {
            strcat(out," array");
            strcat(out,token);
            strcat(out," of");
        }
    }
}

/*识别函数的参数表*/
void parmdcl(void)
{
    do
    {
        dclspec();
    }while(tokentype == ',');
    if(tokentype != ')')
        error("missing ) in parameter declaration\n");
}

void dclspec(void)
{
    char temp[MAXTOKEN];

    temp[0] = '\0';
    gettoken();
    do
    {
        if(tokentype != NAME)
        {
            pretoken = YES;
            dcl();
        }
        else if(typespec() == YES)
        {
            strcat(temp," ");
            strcat(temp,token);
            gettoken();
        }
        else if(typequal() == YES)
        {
            strcat(temp," ");
            strcat(temp,token);
            gettoken();
        }
        else
            error("unknown type in parameter list\n");
    }while(tokentype != ',' && tokentype != ')');
    strcat(out,temp);
    if(tokentype == ',')
        strcat(out,",");
}

int typespec(void)
{
    static char *types[] = {
        "char",
        "int",
        "void"
    };
    char *pt = token;
    if(bsearch(&pt,types,sizeof(types)/sizeof(char *),sizeof(char *),compare) == NULL)
        return NO;
    else
        return YES;
}

int typequal(void)
{
    static char *typeq[] = {
        "const",
        "volatile"
    };
    char *pt = token;
    if(bsearch(&pt,typeq,sizeof(typeq)/sizeof(char *),sizeof(char *),compare) == NULL)
        return NO;
    else
        return YES;
}

int compare(char **s,char **t)
{
    return strcmp(*s,*t);
}

void error(char *s)
{
    printf("%s\n",s);
    pretoken = YES;
}

int gettoken(void)
{
    int c,getch(void);
    void ungetch(int);
    char *p = token;
    if(pretoken == YES)
    {
        pretoken = NO;
        return tokentype;
    }

    while((c = getch()) == ' '|| c == '\t')
        ;
    if(c == '(')
    {
        if((c = getch()) == ')')
        {
            strcpy(token,"()");
            return tokentype = PARENS;
        }
        else
        {
            ungetch(c);
            return tokentype = '(';
        }
    }
    else if(c == '[')
    {
        for(*p++ = c;(*p++ = getch()) != ']';)
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    }
    else if(isalpha(c))
    {
        for(*p++ = c;isalnum(c = getch());)
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }
    else
        return tokentype = c;
}

#define BUFSIZE 100
int buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp > BUFSIZE)
        printf("error:too many\n");
    else
        buf[bufp++] = c;
}
