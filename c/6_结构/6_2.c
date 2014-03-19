/*分组打印输入的变量名
 * 同一组的前6(默认)个字符相同
 */
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include "6.h"

/*节点*/
struct tnode{
    char *word;
    int match;
    struct tnode *left;
    struct tnode *right;
};

#define MAXWORD 100
#define YES 1
#define NO  0

struct tnode *addtree(struct tnode*, char *, int, int *);
void treeprint(struct tnode*);
int getword(char *, int);

int main(int argc, char *argv[])
{
    struct tnode* root;
    char word[MAXWORD];
    int found = 0;
    int num = 6;    /*前num个字符相同,默认为6*/
    if(--argc > 0 && (*++argv)[0] == '-')
        num = atoi(argv[0]+1);
    root = NULL;
    while((getword(word,MAXWORD)) != EOF)
    {
        if(isalpha(word[0]) && strlen(word) >= num)
            root = addtree(root,word,num,&found);
        found = NO;
    }
    treeprint(root);
    return 0;
}

struct tnode* talloc(void);
int compare(char*,struct tnode*,int,int*);

struct tnode* addtree(struct tnode* p, char* w, int num, int *found)
{
    int cond;

    if(p == NULL)
    {
        p = talloc();
        p->word = strdup(w);
        p->match = *found;
        p->left = p->right = NULL;
    }
    else if((cond = compare(w,p,num,found)) < 0)
        p->left = addtree(p->left,w,num,found);
    else if(cond > 0)
        p->right = addtree(p->right,w,num,found);
    return p;
}

int compare(char* s, struct tnode* p, int num, int* found)
{
    int i;
    char *t = p->word;
    for(i = 0; *s == *t;i++,s++,t++)
        if(*s == '\0')
            return 0;
    if(i >= num)
    {
        *found = YES;
        p->match = YES;
    }
    return *s - *t;
}

void treeprint(struct tnode* p)
{
    if(p != NULL)
    {
        treeprint(p->left);
//        printf("%s\n",p->word);
        if(p->match)
            printf("%s\n",p->word);
        treeprint(p->right);
    }
}

struct tnode* talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}
/*
char *strdup(char *s)
{
    char *p;

    p = (char *)malloc(strlen(s) + 1);
    if(p != NULL)
        strcpy(p,s);
    return p;
}
*/
