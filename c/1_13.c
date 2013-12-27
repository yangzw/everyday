#include<stdio.h>
#define MAX 10
#define OUT 1
#define IN 0
void count();
void print_v(int max);
void print_h(int max);
int get_max();

int wdl[MAX+1];
int overflow = 0;

int main()
{
    count();
    int max = get_max();
    printf("v:\n========\n");
    print_v(max);
    printf("h:\n========\n");
    print_h(max);
    if(overflow)
        printf("OverFlow:%d\n",overflow);
}

void count()
{
    int leng = 0;
    char a;
    int state = OUT;
    while((a = getchar()) != '#')
    {
        if(a == ' ' || a == '\t' || a == '\n')
        {
            if(state == IN)
            {
                if(leng > MAX)
                {
                    overflow++;
                    continue;
                }
                state = OUT;
                wdl[leng]++;
                leng = 0;
            }
        }
        else if(state == IN)
            leng++;
        else
        {
            leng++;
            state = IN;
        }
    }
}

int get_max()
{
    int max = 0;
    int i;
    for(i=0;i<=MAX;i++)
        if(wdl[i] > max)
            max = wdl[i];
    return max;
}

void print_v(int max)
{
    int i,j;
    for(i = 0;i < max;i++)
    {
        for(j = 1;j < MAX;j++)
        {
            if(wdl[j] + i - max >= 0)
                printf("* ");
            else
                printf("  ");
        }
        if(wdl[MAX] + i - max >= 0)
            printf("*\n");
        else
            printf(" \n");
    }
    for(i = 1;i < MAX;i++)
        printf("%d ",i);
    printf("%d\n",MAX);
    for(i = 1;i < MAX;i++)
        printf("%d ",wdl[i]);
    printf("%d\n",wdl[MAX]);
}

void print_h(int max)
{
    int i,j;
    for(i = 1;i<=MAX;i++)
    {
        printf("%d %d ",i,wdl[i]);
        for(j = 0;j < max-1;j++)
        {
            if(wdl[i] - j > 0)
                printf("*");
            else
                printf(" ");
        }
        if(wdl[i] - max >= 0)
            printf("*\n");
        else
            printf(" \n");
    }
}
