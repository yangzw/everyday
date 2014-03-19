/*
 * 输入字符串，并将其排序
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXLINES 5000   //maxlines
#define MAXLEN  1000    //maxlen of each line
#define MAX     MAXLEN*MAXLINES
char *lineptr[MAXLINES];
char array[MAX];

int readlines(char *lineptr[],int nlines);
int readlines2(char *lineptr[], int nlines,char* array);
void writelines(char *lineptr[],int nlines);
int my_getline(char *,int);

void my_qsort(char *lineptr[], int left,int right);

int main()
{
    int nlines;
    //if((nlines = readlines(lineptr,MAXLINES)) >= 0)
    if((nlines = readlines2(lineptr,MAXLINES,array)) >= 0)
    {
        my_qsort(lineptr,0,nlines-1);
        writelines(lineptr,nlines);
        return 0;
    }
    else
    {
        printf("error:input too big to sort\n");
        return 1;
    }
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

/*不是动态开辟数组*/
int readlines2(char *lineptr[],int maxlines, char array[])
{
    int len,nlines;
    char *p,line[MAXLEN];
    nlines = 0;
    p = array;
    while((len = my_getline(line,MAXLEN)) > 0)
    {
        if(nlines >= maxlines || (p + len) > array + MAX)
            return -1;
        else
        {
            strcpy(p,line);
            lineptr[nlines++] = p;
            p = p + len + 1;
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

void writelines(char *lineptr[], int nlines)
{
    int i;
    for(i = 0; i < nlines;i++)
        printf("%s\n",lineptr[i]);
}

void my_qsort(char *v[], int left, int right)
{
    int i,last;
    void swap(char *v[],int i,int j);
    if(left >= right)
        return;
    swap(v,left,left+(right-left)/2);
    last = left;
    for(i = left+1;i<= right;i++)
        if(strcmp(v[i],v[left]) < 0)
            swap(v,++last,i);
    swap(v,left,last);
    my_qsort(v,left,last-1);
    my_qsort(v,last+1,right);
}

void swap(char *v[],int i,int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
