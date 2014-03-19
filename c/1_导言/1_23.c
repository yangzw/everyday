#include<stdio.h>

void in_com();
void in_q(char a);
void handle(char a);
int main()
{
    char c;
    while((c = getchar()) != EOF)
    {
        handle(c);
    }
    return 0;
}

void handle(char a)
{
    char next;
    if(a == '\'' || a == '"')
        in_q(a);
    else if(a == '/')
    {
        if((next = getchar()) == '*')
                in_com();
        else if(next == '/')
        {
            putchar(a);
            handle(next);
        }
        else
        {
            putchar(a);
            putchar(next);
        }
    }
    else
        putchar(a);
}

void in_q(char a)
{
    char next;
    putchar(a);
    while((next = getchar()) != a)
    {
        putchar(next);
        if(next == '\\')
            putchar(getchar());
    }
    putchar(next);
}

void in_com()
{
    char current = getchar();
    char next = getchar();
    while(current != '*' || next != '/')
    {
        current = next;
        next = getchar();
    }
}
