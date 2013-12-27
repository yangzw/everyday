#include<stdio.h>
#define MAXCOL  10
#define TABINC  8

char line[MAXCOL];

int exptab(int pos);
int findblk(int pos);
int newpos(int pos);
void printl(int pos);

int main()
{
    char c;
    int pos = 0;
    while((c = getchar()) != EOF)
    {
        line[pos] = c;
        if(c == '\t')
            pos = exptab(pos);
        else if(c == '\n')
        {
            printl(pos);
            pos = 0;
        }
        else if(++pos >= MAXCOL)
        {
            pos = findblk(pos);
            printl(pos);
            pos = newpos(pos);
        }
    }
}

//expand tab into blanks
int exptab(int pos)
{
    line[pos] = ' ';
    for(++pos;pos < MAXCOL && (pos % TABINC);++pos)
        line[pos] = ' ';
    if(pos < MAXCOL)
        return pos;
    else
    {
        printl(pos);
        pos = 0;
    }
}

int findblk(int pos)
{
    while(--pos > 0 && line[pos] != ' ');
    if(pos == 0)
        return MAXCOL;
    else
        return pos+1;
}
void printl(int pos)
{
    int i = 0;
    while(line[i] == ' ')
        i++;
    int tmp = i;
    for(;i<pos;i++)
        printf("%c",line[i]);
    if(pos > tmp)
        printf("\n");
}

int newpos(int pos)
{
    if(pos <= 0 || pos >= MAXCOL)
        return 0;
    else
    {
        int i = 0,j;
        for(j = pos;j < MAXCOL;j++)
            line[i++] = line[j];
        return i;
    }
}
