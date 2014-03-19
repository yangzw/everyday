/* fopen,_fillbuf,_flushbuf,fclose,fflush,fseek的实现
 */
#include"my_io.h"

FILE _myiob[OPEN_MAX] = { /*stdin,stdout and stderr*/
    { 0,(char *) 0, (char *) 0, _READ, 0},
    { 0,(char *) 0, (char *) 0, _WRITE, 1},
    { 0,(char *) 0, (char *) 0, _WRITE | _UNBUF, 2}
};

FILE *fopen(char *filename, char *mode)
{
    int fd;
    FILE *fp;

    if(*mode != 'r' && *mode != 'a' && *mode != 'w')
        return NULL;
    for(fp = _myiob; fp < _myiob + OPEN_MAX; fp++)/*跳过已经分配的*/
        if((fp->flag & (_READ | _WRITE)) == 0)
            break;
    if(fp > _myiob + OPEN_MAX)
        return NULL;

    if(*mode == 'w')
        fd = creat(filename,PERMS);
    else if(*mode == 'a')
    {
        if((fd = open(filename,O_WRONLY,0)) == -1)
            fd = creat(filename,PERMS);
        lseek(fd,0L,2);
    }
    else
        fd = open(filename,O_RDONLY,0);
    if(fd == -1)
        return NULL;
    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    fp->flag = (*mode == 'r') ? _READ : _WRITE;
    return fp;
}

int _fillbuf(FILE *fp)
{
    int bufsize;

    if((fp->flag & (_READ | _EOF | _ERR)) != _READ)
        return EOF;
    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
    if(fp->base == NULL)
        if((fp->base = (char *)malloc(bufsize)) == NULL)
            return EOF;
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd,fp->ptr,bufsize);
    if(--fp->cnt < 0)
    {
        if(fp->cnt == -1)
            fp->flag |= _EOF;
        else
            fp->flag |= _ERR;
        fp->cnt = 0;
        return EOF;
    }
    return (unsigned char) *fp->ptr++;
}

int _flushbuf(int x, FILE *fp)
{
    unsigned nc;
    int bufsize;

    if(fp < _myiob || fp > _myiob + OPEN_MAX)
        return EOF;
    if((fp->flag & (_EOF | _ERR | _WRITE)) != _WRITE)
        return EOF;
    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
    if(fp->base == NULL)
    {
        if((fp->base = (char *)malloc(bufsize)) == NULL)
        {
            fp->flag != _ERR;
            return EOF;
        }
    }
    else
    {
        nc = fp->ptr - fp->base;
        if(write(fp->fd,fp->base,nc) != nc)
        {
            fp->flag |= _ERR;
            return EOF;
        }
    }
    fp->ptr = fp->base;
    *fp->ptr++ = (char)x;
    fp->cnt = bufsize - 1;
    return x;
}


int fflush(FILE *);

int fclose(FILE *fp)
{
    int rc;

    if((rc = fflush(fp)) != EOF)
    {
        free(fp->base);
        fp->ptr = NULL;
        fp->base = NULL;
        fp->cnt = 0;
        fp->flag &= ~(_READ | _WRITE);
    }
    return rc;
}

int fflush(FILE *fp)
{
    int rc = 0;

    if(fp < _myiob || fp > _myiob + OPEN_MAX)
        return EOF;
    if(fp->flag & _WRITE)
        rc = _flushbuf(0,fp);
    fp->ptr = fp->base;
    fp->cnt = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
    return rc;
}

int fseek(FILE *fp, long offset, int origin)
{
    unsigned nc;
    long rc = 0;

    if(fp->flag & _READ)
    {
        if(origin == 1)/*考虑缓冲区*/
            offset -= fp->cnt;
        rc = lseek(fp->fd,offset,origin);
        fp->cnt = 0;
    }
    else if(fp->flag & _WRITE)
    {
        if((nc = fp->ptr - fp->base) > 0)/*先把缓冲区的写入文件*/
            if(write(fp->fd,fp->base,nc) != nc)
                rc = -1;
        if(rc != -1)
            rc = lseek(fp->fd,offset,origin);
    }
    return (rc == -1) ? -1 : 0;
}
