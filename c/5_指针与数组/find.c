#include<stdio.h>
#include<string.h>
#define MAXLEN	1000

int my_getline(char *s,int maxlen);

main(int argc, char *argv[])
{
    char line[MAXLEN];
	long lineno = 0;
	int c,except = 0,number = 0, found = 0;
    while(--argc > 0 && (*++argv)[0] == '-')
    {
        while(c = *++argv[0])
            switch(c){
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find:illegal option %c\n",c);
                    argc = 0;
                    found = -1;
                    break;
            }
    }
    if(argc != 1)
        printf("usage: find -x -n pattern\n");
    else
        while(my_getline(line,MAXLEN) > 0)
        {
            lineno ++;
            if((strstr(line,*argv) != NULL) != except)
            {
                if(number)
                    printf("%ld:",lineno);
                printf("%s\n",line);
                found ++;
            }
        }
    return found;
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
