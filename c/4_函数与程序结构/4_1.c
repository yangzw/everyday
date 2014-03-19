#include<stdio.h>
#include<string.h>
#include<ctype.h>

int strrindex(char s[],char t[]);
double atof(char s[]);

int main()
{
    return 0;
}

int strrindex(char s[],char t[])
{
    int i,j,k;
    for(i = strlen(s) - strlen(t);i >=0;i--)
    {
        for(j=i,k=0;t[k] != '\0' && t[k] == s[j];k++,j++);
        if(k > 0 && t[k] == '\0')
            return i;
    }
    return -1;

}

double atof(char s[])
{
    int i,sign,sign2 = 0;
    double value,b,power;
    for(i = 0;isspace(s[i]);i++);
    sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '-' || s[i] == '+')
        i++;
    for(value = 0.0;isdigit(s[i]);i++)
        value = 10.0*value + s[i] - '0';
    if(s[i] == '.')
        i++;
    for(b = 1.0;isdigit(s[i]);i++)
    {
        value = 10.0*value + s[i] - '0';
        b = 10.0*b;
    }
    value = sign*value/b;
    if(s[i] == 'e' || s[i] == 'E')
    {
        sign2 = (s[++i] == '-') ? -1 : 1;
        if(s[i] == '-' || s[i] == '+')
            i++;
        for(power = 0.0;isdigit(s[i]);i++)
            power = 10.0*power + s[i] - '0';
        if(sign2 > 0)
            while(power-- > 0)
                value*=10.0;
        else
            while(power-- > 0)
                value/=10.0;
    }
    return value;
}
