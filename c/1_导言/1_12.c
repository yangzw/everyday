#include<stdio.h>
#define IN  1
#define OUT 0

int main()
{
    int state = IN;
    char c;
    while((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\t' || c == '\n')
        {
            if(state == IN)
            {
                printf("\n");
                state = OUT;
            }
        }
        else if(state == OUT)
        {
            state = IN;
            printf("%c",c);
        }
        else
            printf("%c",c);
    }
    return 0;
}
