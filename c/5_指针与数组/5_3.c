#include<stdio.h>

void my_strcat(char *s, char *t);
int my_strend(char *s,char *t);

int main()
{
    char s[20] = "hi ";
    char t[10] = "there!";
    my_strcat(s,t);
    printf("%s\n%d\n",s,my_strend(s,t));
    return 0;
}

void my_strcat(char *s, char *t)
{
    while(*s++);
    s--;
    while(*s++ = *t++);
}

int my_strend(char *s,char *t)
{
    char *sb = s;
    char *tb = t;
    while(*s++);
    while(*t++);
    for(;*s == *t;s--,t--)
        if(s == sb || t == tb)
            break;
    if(t == tb && *s == *t && *s != '\0')
        return 1;
    else
        return 0;
}
