#include"my_io.h"

int main()
{
    FILE *fp = fopen("out_io_test.txt","w");
    putc('a',fp);
    putc('\n',fp);
    fclose(fp);
    return 0;
}
