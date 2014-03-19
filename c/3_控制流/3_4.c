#include<stdio.h>
#define abs(x) (((x)>0) ? (x) : -(x))
void my_reverse(char line[]);
void itoa(int n,char s[],int w);
void itob(int n,char s[],int b);

int main()
{
    int n = -30948;
    char a[20] = "";
    itoa(n,a,12);
    printf("%d\n%s\n",n,a);
    itob(n,a,4);
    printf("%s\n",a);
    return 0;
}

void itoa(int n,char s[],int w)
{
    int i,sign;

    sign = n;
    i = 0;
    do{
        s[i++] = abs(n%10) + '0';
    }while((n/=10) != 0);
    if(sign < 0)
        s[i++] = '-';
    while(i<w)
        s[i++] = ' ';
    s[i++] = '\0';
    my_reverse(s);
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

void itob(int n,char s[],int b)
{
    if(b <= 0)
        return;
    int i,sign,j;
    sign = n;
    i = 0;
    do{
        j = abs(n%b);
        s[i++] = (j <= 9) ? j+'0' : j-10+'a';
    }while((n/=b) != 0);
    if(sign < 0)
        s[i++] = '-';
    s[i++] = '\0';
    my_reverse(s);
}
