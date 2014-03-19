#include<syscall.h>
#include"my_malloc.h"


/*存储分配程序*/
void *malloc(unsigned nbytes)
{
    Header *p,*prevp;
    unsigned nunits;

 //   printf("1in free\n");

    if(nbytes > MAXBYTES)
    {
        fprintf(stderr,"alloc: can't allocate more than %u bytes",MAXBYTES);
        return NULL;
    }
    nunits = (nbytes + sizeof(Header) - 1)/sizeof(Header) + 1;
    if((prevp = freep) == NULL)
    {
        base.s.ptr = freep = prevp = &base;
        base.s.size = 0;
    }

    for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr)
    {
        if(p->s.size >= nunits)
        {
            if(p->s.size == nunits)
                prevp->s.ptr = p->s.ptr;
            else/*分配末尾部分*/
            {
                p->s.size -= nunits;
                p += p->s.size;
                p->s.size = nunits;
            }
            freep = prevp;
            return (void *)(p+1);
        }
        if(p == freep)
            if((p = morecore(nunits)) == NULL)
                return NULL;
    }
}

#define NALLOC  1024
/*向系统申请更多的空间*/
static Header *morecore(unsigned nu)
{
    char *cp;   /*系统调用sbrk(int n)返回n字节的存储空间*/
    Header *up;

  //  printf("2in free\n");

    if(nu < NALLOC)
        nu = NALLOC;
    cp = sbrk(nu * sizeof(Header));
    if(cp == (char *) -1)/*没有空闲空间时，sbrk()返回的是-1*/
        return NULL;
    up = (Header *) cp;
    up->s.size = nu;
    maxalloc = (up->s.size > maxalloc) ? up->s.size : maxalloc;
    free((void *)(up + 1));/*free 将多余的存储空间插到空闲区域中*/
    return freep;
}

/*free函数:将ap放入空闲块链表中*/
void free(void *ap)
{
    Header *bp,*p;

//    printf("in free\n");

    bp = (Header *)ap - 1;
    if(bp->s.size == 0 || bp->s.size > maxalloc)
    {
        fprintf(stderr,"free:can't free %u unist\n",bp->s.size);
        return;
    }

    for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
        if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
            break;/*被释放的块在链表的开头或者结尾*/
    if(bp + bp->s.size == p->s.size)
    {   /*与上一相邻块合并*/
        bp->s.size += p->s.ptr->s.size;
        bp->s.ptr = p->s.ptr->s.ptr;
    }
    else
        bp->s.ptr = p->s.ptr;
    if(p + p->s.size == bp)
    {   /*与下一相邻快合并*/
        p->s.size += bp->s.size;
        p->s.ptr = bp->s.ptr;
    }
    else
        p->s.ptr = bp;
    freep = p;
}
