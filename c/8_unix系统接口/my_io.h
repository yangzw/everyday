/*自己实现类stdio.h提供的功能
 */
#include<fcntl.h>
#include<syscall.h>
#define PERMS   0666

#define NULL    0
#define EOF     (-1)
#define BUFSIZ  1024
#define OPEN_MAX    20

typedef struct _iobuf{
    int cnt;    /*剩余字符数*/
    char *ptr;  /*下一个字符的位置*/
    char *base; /*缓冲区的位置*/
    int flag;   /*访问模式*/
    int fd;     /*文件描述符*/
}FILE;
extern FILE _myiob[OPEN_MAX];

#define stdin   &_myiob[0]
#define stdout  &_myiob[1]
#define stderr  &_myiob[2]

enum _flags{
    _READ   = 01,
    _WRITE  = 02,
    _UNBUF  = 04,   /*不对文件进行缓冲*/
    _EOF    = 010,
    _ERR    = 020   /*该文件发生错误*/
};

int _fillbuf(FILE *);
int _flushbuf(int, FILE *);

#define feof(p)     (((p)->flag & _EOF) != 0)
#define ferror(p)   (((p)->flag & _ERR) != 0)
#define fileno(p)   ((p)->fd)

#define getc(p)     (--(p)->cnt >= 0 ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(x,p)     (--(p)->cnt >= 0 ?  *(p)->ptr++ = x : _flushbuf(x,p))

#define getchar()   getc(stdin)
#define putchar(x)   putc((x),stdout)


FILE *fopen(char *filename, char *mode);
int fclose(FILE *fp);
int fseek(FILE *fp, long offset, int origin);
