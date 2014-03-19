#include<stdio.h>
#include<ctype.h>
#include "6.h"

int comment(void);
int getch(void);
void ungetch(int);

int getword(char *word, int lim)
{
    int c,d;
    char *w = word;

    while(isspace(c = getch()))
        ;
    if(c != EOF)
        *w++ = c;
    if(isalpha(c) || c == '_')
    {
        for(;--lim > 0; w++)
            if(!isalnum(*w = getch()) && *w != '_')
            {
                ungetch(*w);
                break;
            }
    }
    else if(c == '\'' || c == '"')
    {
        for(;lim > 0; w++)
            if((*w = getch()) == '\\')
                *++w = getch();
            else if(*w == c)
            {
                w++;
                break;
            }
            else if(*w == EOF)
                break;
    }
    else if(c == '/')
    {
        if((d = getch()) == '*')
            c = comment();
        else
            ungetch(d);
    }
    *w = '\0';
    return c;
}

int comment(void)
{
    int c;
    while((c = getch()) != EOF)
        if(c == '*')
            if((c = getch()) == '/')
                break;
            else
                ungetch(c);
    return c;
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
