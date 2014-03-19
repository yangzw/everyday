/*简化版的printf函数实现
 */
#include<stdarg.h>
#include<stdio.h>
#include<ctype.h>

#define LOCALFMT    100

void minprintf(char *fmt,...)
{
    va_list ap;
    char *p,*sval;
    char localfmt[LOCALFMT];
    int i,ival;
    unsigned uval;
    double dval;

    va_start(ap,fmt);
    for(p = fmt; *p; p++)
    {
        if(*p != '%')
        {
            putchar(*p);
            continue;
        }
        i = 0;
        localfmt[i++] = '%';
        while(*(p+1) && !isalpha(*(p+1)))
            localfmt[i++] = *++p;
        localfmt[i++] = *(p+1);
        localfmt[i] = '\0';
        switch(*++p)
        {
            case 'd':
            case 'i':
                ival = va_arg(ap,int);
                printf(localfmt,ival);
                break;
            case 'x':
            case 'X':
            case 'u':
            case 'o':
                uval = va_arg(ap,unsigned);
                printf(localfmt,uval);
                break;
            case 'f':
                dval = va_arg(ap,double);
                printf(localfmt,dval);
                break;
            case 's':
                sval = va_arg(ap,char *);
                printf(localfmt,sval);
                break;
            default:
                printf(localfmt);
                break;
        }
    }
    va_end(ap);
}

int main()
{
    int b = 1;
    double c = 3.4;
    minprintf("a%dkd%f\n",b,c);
    return 0;
}
