#include<stdio.h>
#define MAXBYTES    (unsigned) 10240

typedef long Align;

union header{
    struct{
        union header* ptr;
        unsigned size;
    }s;
    Align x;
};

typedef union header Header;

static unsigned maxalloc = 0;
static Header base; /*空闲块链表的头部*/
static Header *freep = NULL;

void *malloc(unsigned nbytes);
static Header *morecore(unsigned nu);
void free(void *ap);
