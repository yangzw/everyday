#include<stdio.h>

int htoi(char s[])
{
    int i = 0;
    if(s[i] == '0')
    {
        i++;
        if(s[i] == 'x' || s[i] == 'X')
            i++;
    }
    int i_num = 0;
    int wrong = 0;
    int digit = 0;
    while(!wrong)
    {
        if(s[i] >= '0' && s[i] <= '9')
            digit = s[i] - '0';
        else if(s[i] >= 'a' && s[i] <= 'f')
            digit = s[i] - 'a' + 10;
        else if(s[i] >= 'A' && s[i] <= 'F')
            digit = s[i] - 'A' + 10;
        else
            wrong = 1;
        if(!wrong)
            i_num = 16*i_num + digit;
        i++;
    }
    return i_num;
}

int main()
{
    char s[] = "0X113";
    int a = htoi(s);
    printf("%s:%d\n",s,a);
    return 0;
}
