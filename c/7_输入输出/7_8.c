/*打印文件集合，每个文件从新的一页打印，并且每个文件打印标题和页数*/
#include<stdio.h>
#include<stdlib.h>

#define MAXBOT  3       /*max lines at bottom of page*/
#define MAXHDR  5       /*max lines at head of page*/
#define MAXLINE 100     /*max word of one line*/
#define MAXPAGE 66      /*max line in one page*/

void fileprint(FILE *, char *);
int heading(char *, int);

int main(int argc, char *argv[])
{
    FILE *fp;

    if(argc == 0)
        fprintf(stdin," ");
    else
    {
        while(--argc > 0)
            if((fp = fopen(*++argv,"r")) == NULL)
            {
                fprintf(stderr,"print:can't open %s\n",*argv);
                exit(1);
            }
            else
            {
                fileprint(fp,*argv);
                fclose(fp);
            }
    }
    return 0;
}

void fileprint(FILE *fp, char *filename)
{
    int lineno, pageno = 1;
    char line[MAXLINE];

    lineno = heading(filename,pageno++);
    while(fgets(line,MAXLINE,fp) != NULL)
    {
        if(lineno == 1)
        {
            fprintf(stdout,"\f");
            lineno = heading(filename,pageno++);
        }
        fputs(line,stdout);
        if(++lineno > MAXPAGE - MAXBOT)
            lineno = 1;
    }
    fprintf(stdout,"\f");
}

int heading(char *filename, int pageno)
{
    int ln = 3;
    fprintf(stdout,"\n\n");
    fprintf(stdout,"%s\tpage%d\n",filename,pageno);
    while(ln++ < MAXHDR)
        fprintf(stdout,"\n");
    return ln;
}
