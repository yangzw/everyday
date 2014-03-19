/*
 * 输入字符串，并将其排序的升级版
 * 支持命令行参数,默认字典序
 * -n 用数字序比较
 * -r 以递减方式排序
 * -f 不考虑大小写
 * -d 目录顺序
 *  [+pos1] [-pos2] 字段处理功能,即之比较pos1 - pos2 之间的字段
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXLINES 500   //maxlines
#define MAXLEN  100    //maxlen of each line
#define MAX     MAXLEN*MAXLINES
char *lineptr[MAXLINES];
char array[MAX];
int numeric = 0,reverse = 0,fold = 0,dir = 0;
int pos1 = 0, pos2 = 0;

int readlines(char *lineptr[],int nlines);
void writelines(char *lineptr[],int nlines,int reverse);
int my_getline(char *,int);

void my_qsort(void *lineptr[], int left,int right,int (*comp)(void *, void*));
int numcmp(char *, char*);
int charcmp(char *, char *);
void substr(char *, char *);
void error(char *s);


int main(int argc, char *argv[])
{
    int nlines;
    char c;
    int rc = 0;
    while(--argc > 0 && (c = (*++argv)[0]) == '-' || c == '+')
    {
        if(c == '-' && !isdigit(*(argv[0]+1)))
            while(c = *++argv[0])
                switch(c)
                {
                    case 'r':
                        reverse = 1;
                        break;
                    case 'n':
                        numeric = 1;
                        break;
                    case 'f':
                        fold = 1;
                        break;
                    case 'd':
                        dir = 1;
                        break;
                    default:
                        printf("514SortStrings:illegal option %c\n",c);
                        error("Usage: sort -dfnr [+pos1] [-pos2]\n");
                        argc = 1;
                        rc = -1;
                        break;
            }
        else if(c == '-')
            pos2 = atoi(argv[0] + 1);
        else if((pos1 = atoi(argv[0] + 1)) < 0)
            error("Usage: sort -dfnr [+pos1] [-pos2]\n");
    }
    if(argc || pos1 > pos2)
        error("Usage: sort -dfnr [+pos1] [-pos2]\n");
    if((nlines = readlines(lineptr,MAXLINES)) >= 0)
    {
        if(numeric == 1)
            my_qsort((void**)lineptr,0,nlines-1,
                    (int (*)(void *, void *)) numcmp);
        else
            my_qsort((void**)lineptr,0,nlines-1,
                    (int (*)(void *, void *)) charcmp);
        writelines(lineptr,nlines,reverse);
    }
    else
    {
        printf("error:input too big to sort\n");
        rc = -1;
    }
    return rc;
}

int readlines(char *lineptr[],int maxlines)
{
    int len,nlines;
    char *p,line[MAXLEN];
    nlines = 0;
    while((len = my_getline(line,MAXLEN)) > 0)
    {
        if(nlines >= maxlines || (p = (char*)malloc(len*sizeof(char))) == NULL)
            return -1;
        else
        {
            strcpy(p,line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
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

void writelines(char *lineptr[], int nlines,int reverse)
{
    int i;
    if(reverse)
        for(i = nlines-1;i >=0;i--)
            printf("%s\n",lineptr[i]);
    else
        for(i = 0; i < nlines;i++)
            printf("%s\n",lineptr[i]);
}

void my_qsort(void *v[], int left, int right, int (*comp)(void* , void*))
{
    int i,last;
    void swap(void *v[],int, int);

    if(left >= right)
        return;
    swap(v,left,(right-left)/2 + left);
    last = left;
    for(i = left + 1;i <= right;i++)
        if((*comp)(v[i],v[left]) < 0)
            swap(v,++last,i);
    swap(v,left,last);
    my_qsort(v,left,last - 1,comp);
    my_qsort(v,last+1,right,comp);
}

void swap(void *v[],int j, int i)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int numcmp(char *s1, char* s2)
{
    double v1,v2;
    char str[MAXLEN];
    substr(s1,str);
    v1 = atof(str);
    substr(s2,str);
    v2 = atof(str);
    if(v1 < v2)
        return -1;
    else if(v1 > v2)
        return 1;
    else
        return 0;
}

void substr(char *s, char *s2)
{
    int len = strlen(s);
    int i,j;
    if(pos2 > 0 && pos2 < len)
        len = pos2;
    else if(pos2 > 0 && pos2 > len)
        error("substr: string too short\n");
    for(j = 0,i = pos1;i < len;i++,j++)
        s2[j] = s[i];
    s[j] = '\0';
}

int charcmp(char *s1, char *s2)
{
    int i,j,endpos;
    i = j = pos1;
    char a,b;
    if(pos2 > 0)
        endpos = pos2;
    else if((endpos = strlen(s1)) > strlen(s2))
        endpos = strlen(s2);
    do
    {
        if(dir)
        {
            while(i < endpos && !isalnum(s1[i]) && s1[i] != ' ' && s1[i] != '\0')
                i++;
            while(j < endpos && !isalnum(s2[j]) && s2[j] != ' ' && s2[j] != '\0')
                j++;
        }
        if(i < endpos && j < endpos)
        {
            a = fold ? tolower(s1[i]) : s1[i++];
            b = fold ? tolower(s2[j]) : s2[j++];
            if(a == b && a == '\0')
                return 0;
        }
    }while(a == b && i < endpos && j < endpos);
    return a - b;
}

void error(char *s)
{
    printf("%s\n",s);
    exit(1);
}
