#include<stdio.h>

int result[16] = {0};
void change(int s[][4],int pos)
{
    int i,j,k;
    i = pos / 4;
    j = pos % 4;
    for(k=0;k < 4;k++)
    {
        s[k][j] = 1 - s[k][j];
        s[i][k] = 1 - s[i][k];
    }
    s[i][j] = 1 - s[i][j];
}

int finish(int s[][4])
{
    int i,j;
    for(i = 0;i < 4;i++)
        for(j = 0;j < 4;j++)
            if(s[i][j] != 1)
                return 0;
    return 1;
}

void flip(int s[][4], int pos, int step, int *ans, int mark[])
{
    if(finish(s))
    {
        if(step < *ans)
            *ans = step;
        int i;
        for(i=0;i<16;i++)
            result[i] = mark[i];
        return;
    }
    if(pos > 15)
        return;
    change(s,pos);
    mark[pos] = 1;
    flip(s,pos+1,step+1,ans,mark);
    change(s,pos);
    mark[pos] = 0;
    flip(s,pos+1,step,ans,mark);
}

int main()
{
    int s[4][4];
    int mark[16] = {0};
    int i,j,ans = 17;
    char t[5];
    for(i = 0;i<4;i++)
    {
        scanf("%s",t);
        for(j = 0;j < 4;j++)
        {
            if(t[j] == '-')
                s[i][j] = 1;
            else
                s[i][j] = 0;
        }
    }
    flip(s,0,0,&ans,mark);
    if(ans == 17)
        printf("Impossible");
    else
        printf("%d\n",ans);
    for(i=0;i<16;i++)
    {
        //printf("\n%d",result[i]);
        if(result[i] == 1)
            printf("%d %d\n",i/4+1,i%4+1);
   }
    return 0;
}
