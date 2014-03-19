#include<ctype.h>
#include<string.h>
#include"calculator.h"

#define BUFSIZE 100

int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i,c;
    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    i = 0;
    s[1] = '\0';
    if(islower(c))
    {
        while(islower(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if(c != EOF)
            ungetch(c);
        if(strlen(s) > 1)
            return MATH;
        else
            return s[0];
    }
    if(!isdigit(c) && c != '.' && c != '-')
        return c;
    if(c == '-')
    {
        if(isdigit(c = getch()) || c == '.')
            s[++i] = c;
        else
        {
            if(c != EOF)
                ungetch(c);
            return '-';
        }
    }
    if(isdigit(c))
        while(isdigit(s[++i] = c = getch()))
            ;
    if(c == '.')
        while(isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}
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
