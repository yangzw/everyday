/*比较两个文件，打印第一个不同的行
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void filecompare(FILE *, FILE *);

void main(int argc, char *argv[])
{
    FILE *fp1, *fp2;

    if(argc != 3)
    {
        fprintf(stderr,"com: need two file names\n");
        exit(1);
    }
    else if((fp1 = fopen(*++argv,"r")) == NULL)
    {
        fprintf(stderr,"com: can't open %s\n",*argv);
        exit(1);
    }
    else if((fp2 = fopen(*++argv,"r")) == NULL)
    {
        fprintf(stderr,"com: can't open %s\n",*argv);
        exit(1);
    }
    else
    {
        filecompare(fp1,fp2);
        fclose(fp1);
        fclose(fp2);
        exit(0);
    }
}

#define MAXLINE 100

void filecompare(FILE *fp1, FILE *fp2)
{
    char *fl1, *fl2;
    char line1[MAXLINE],line2[MAXLINE];

    do
    {
        fl1 = fgets(line1,MAXLINE,fp1);
        fl2 = fgets(line2,MAXLINE,fp2);
        if(fl1 == line1 && fl2 == line2)
        {
            if(strcmp(line1,line2) != 0)
            {
                printf("first different in line \n %s\n and \n%s\n",line1,line2);
                fl1 = fl2 = NULL;
            }
        }
        else if(fl1 != line1 && fl2 == line2)
            printf("end of first file at \n%s\n",line2);
        else if(fl1 == line1 && fl2 != line2)
            printf("end of seconde file at \n%s\n",line1);
    }while(fl1 == line1 && fl2 == line2);
}
