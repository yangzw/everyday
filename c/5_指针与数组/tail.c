/*tail -n 输出输入最后的ｎ行*/
/*bug 会出现后面的字符串将前面的覆盖的问题*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXN    50      /* max lines */
#define DEFAULTN   10
#define MAXLINE 100     /*max word in every line*/

void error(char *);
int my_getline(char *, int);

main(int argc, char* argv[])
{
    char *p;
    char *buf;
    char * bufend;
    char line[MAXLINE];
    char* lineptr[MAXN];
    int first,last,i,len,nlines;
    int n = -1;
    if(argc == 1)
        n = DEFAULTN;
    else if(argc == 2 && (*++argv)[0] == '-')
        n = atoi(argv[0] + 1);
    else
        error("Usage: tail [-n]");
    if(n <= 0 || n > MAXN)
        n = MAXN;
    for(i = 0; i < MAXN; i++)
        lineptr[i] = NULL;
    if((p = buf = malloc(MAXN * MAXLINE)) == NULL)
        error("tail:cannot alloc buf");
    bufend = buf + MAXN * MAXLINE;
    last = 0;
    nlines = 0;
    while((len = my_getline(line,MAXLINE)) > 0)
    {
        if(p + len + 1 >= bufend)
            p = buf;
        lineptr[last] = p;
        strcpy(lineptr[last],line);
        if(++last >= MAXN)
            last = 0;
        p += len + 1;
        nlines++;
    }
    if(n > nlines)
        n = nlines;
    first = last - n;
    if(first < 0)
        first += MAXN;
    for(i = first;n-->0;i = (i+1)%MAXN)
        printf("%s\n",lineptr[i]);
    return 0;
}

void error(char *s)
{
    printf("%s\n",s);
    exit(1);
}

int my_getline(char *s,int maxlen)
{
    char c;
    int i = 0;
    for(;(i < maxlen) && ((c = getchar()) != EOF) && (c != '\n');i++)
        *s++ = c;
    *s = '\0';
    return i;
}
