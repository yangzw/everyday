#include<stdio.h>
#define MAXLENG 1000

int my_getline(char line[]);
void save_max(char line[],char longest[]);
void my_reverse(char line[]);

int main()
{
    int len = 0;
    int max = 0;
    char line[MAXLENG];
    char longest[MAXLENG];
    while((len = my_getline(line)) > 0)
    {
        if(len > max)
        {
            max = len;
            save_max(line,longest);
        }
    }
    int i;
    if(max > 0)
    {
        printf("Longest:\n");
        printf("%s\n",longest);
        my_reverse(longest);
        printf("Reverse:\n%s\n",longest);
    }
    return 0;
}

int my_getline(char line[])
{
    int len = 0;
    char c;
    while(((c = getchar()) != EOF) && c != '\n')
    {
        line[len++] = c;
        if(len >= MAXLENG - 1)
            break;
    }
    line[len] = '\0';
    return len;
}

void save_max(char line[],char longest[])
{
    int i = 0;
    while((longest[i] = line[i++]) != '\0');
}

void my_reverse(char line[])
{
    int i,j;
    i = -1;
    char tmp;
    while(line[++i] != '\0');
    i = i - 1;
    if(line[i] == '\n')
        i = i - 1;
    for(j=0;i>j;i--,j++)
    {
        tmp = line[i];
        line[i] = line[j];
        line[j] = tmp;
    }
}
