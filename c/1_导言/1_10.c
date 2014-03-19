#include<stdio.h>

int main()
{
    char c;
    while((c = getchar()) != EOF)
    {
        if(c == '\b')
            printf("\\b");
        else if(c == '\t')
            printf("\\t");
        else if(c == '\\')
            printf("\\\\");
        else
            printf("%c",c);
    }
    return 0;
}
