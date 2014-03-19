/*疑问:在输出%s后再输出别的东西而不是\n会出现段错误*/
#include"my_malloc.h"
#include<stdio.h>

void* calloc(unsigned n,unsigned size);

int main()
{
    char *a;
    putchar('b');
    a = (char *) malloc(3*sizeof(char));
    putchar('a');
    a[0] = 'c';
    a[1] = 'd';
    a[2] = '\0';
    printf("%s\n",a);
    free(a);

    char *b = (char *)calloc(5,sizeof(char));
    printf("%s\n",b);
    free(b);
    return 0;
}

void* calloc(unsigned n,unsigned size)
{
    unsigned i,nb;
    char *p,*q;

    nb = n * size;
    if((p = q = malloc(nb)) != NULL)
        for(i = 0; i < nb; i++)
            *p++ = 0;
    return q;
}
