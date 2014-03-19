/*
 * c语言中#define处理器的简单版本
 */
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include"6.h"

#define MAXWORD    100
#define HASHSIZE 101
static struct nlist *hashtable[HASHSIZE];

struct nlist{
    struct nlist *next;
    char *name;
    char *defn;         /*替代的*/
};

void error(int , char*);
int getch(void);
void ungetch(int);
void getdef(void);
void undef(char *);
int getword(char*, int);
void ungets(char *);
struct nlist *install(char *, char *);
struct nlist *lookup(char *);
void skipblanks(void);
void print_table(void);

main()
{
    char w[MAXWORD];
    struct nlist *p;
    int count = 0;

    while(getword(w,MAXWORD) != EOF)
    {
        if(strcmp(w,"#") == 0)
            getdef();
        else if(!isalpha(w[0]))
            printf("%s",w);
        else if((p = lookup(w)) == NULL)
            printf("%s",w);
        else
            ungets(p->defn);
    }
    print_table();
    return 0;
}

/*get definition and install it*/
void getdef(void)
{
    int c,i;
    char def[MAXWORD],dir[MAXWORD],name[MAXWORD];

    skipblanks();
    if(!isalpha(getword(dir,MAXWORD)))
        error(dir[0],"getdef:expecting a directive after #");
    else if(strcmp(dir,"define") == 0)
    {
        skipblanks();
        if(!isalpha(getword(name,MAXWORD)))
            error(name[0],"getdef:non-alpha -name expected");
        else
        {
            skipblanks();
            for(i = 0; i < MAXWORD - 1; i++)
                if((def[i] = getch()) == EOF || def[i] == '\n')
                    break;
            def[i] = '\0';
            if(i <= 0)
                error('\n',"getdef:incomplete define");
            else
                install(name,def);
        }
    }
    else if(strcmp(dir,"undef") == 0)
    {
        skipblanks();
        if(!isalpha(getword(name,MAXWORD)))
            error(name[0],"getdef: non-alpha in undef");
        else
            undef(name);
    }
    else
        error(dir[0],"getdef:expecting a directive after #");
}

unsigned hash(char *s)
{
    unsigned hashval;

    for(hashval = 0; *s != '\0';s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
    struct nlist *np;
    for(np = hashtable[hash(s)]; np != NULL; np = np->next)
        if(strcmp(s,np->name) == 0)
            return np;
    return NULL;
}

/*将(name,defn)加入hashtable中*/
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if((np = lookup(name)) == NULL)
    {
        np = (struct nlist *)malloc(sizeof(*np));
        if(np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtable[hashval];
        hashtable[hashval] = np;
    }
    else
        free((void *)np->defn);
    if((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

void undef(char *s)
{
    int h;
    struct nlist *pre,*np;

    pre = NULL;
    h = hash(s);
    for(np = hashtable[h]; np != NULL; np = np->next)
    {
        if(strcmp(s,np->name) == 0)
            break;
        pre = np;
    }
    if(np != NULL)
    {
        if(pre == NULL)
            hashtable[h] = np->next;
        else
            pre->next = np->next;
        free((void *)np->name);
        free((void *)np->defn);
        free((void *)np);
    }
}

/*error:print error message and skip the rest of the line*/
void error(int c, char *s)
{
    printf("error: %s\n",s);
    while(c != EOF && c != '\n')
        c = getch();
}

void skipblanks(void)
{
    int c;
    while((c = getch()) == ' ' || c == '\t')
        ;
    ungetch(c);
}

void ungets(char *s)
{
    int len = strlen(s);
    while(len > 0)
        ungetch(s[--len]);
}

void print_table(void)
{
    int i;
    struct nlist *np;
    for(i = 0; i < HASHSIZE; i++)
        if(hashtable[i] != NULL)
        {
            for(np = hashtable[i]; np != NULL; np = np->next)
                printf("%s:%s\n",np->name,np->defn);
        }
}
