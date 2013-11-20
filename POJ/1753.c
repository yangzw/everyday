//暴力DFS
#include<stdio.h>
void flip(int s[], int pos, int step, int *ans);

int main()
{
    int s[16];
    int i,j,ans = 17;
    char t[5];
    for(i = 0;i < 4;i++)
    {
        scanf("%s",t);
        for(j = 0;j < 4;j++)
        {
            if(t[j] == 'b')
                s[i*4+j] = 1;
            else
                s[i*4+j] = 0;
        }
    }
    flip(s,0,0,&ans);
    if(ans == 17)
        printf("Impossible");
    else
        printf("%d",ans);
    return 0;
}

int finish(int s[])
{
    int i;
    for(i = 1;i < 16;i++)
        if(s[i] != s[0])
            return 0;
    return 1;
}

void change(int s[],int pos)
{
    if(s[pos] == 0)
        s[pos] = 1;
    else
        s[pos] = 0;
    if((pos+1<16) && (pos % 4 != 3))
        if(s[pos+1] == 0)
            s[pos+1] = 1;
        else
            s[pos+1] = 0;
    if((pos - 1 >= 0) && (pos % 4 != 0))
        if(s[pos-1] == 0)
            s[pos-1] = 1;
        else
            s[pos-1] = 0;
    if(pos + 4 < 16)
        if(s[pos+4] == 0)
            s[pos+4] = 1;
        else
            s[pos+4] = 0;
    if(pos-4 >= 0)
        if(s[pos-4] == 0)
            s[pos-4] = 1;
        else
            s[pos-4] = 0;
}


void flip(int s[], int pos, int step, int *ans)
{
    if(finish(s))
    {
        if(step < *ans)
            *ans = step;
        return;
    }
    if(pos > 15)
        return;
    //翻转pos的
    change(s,pos);
    flip(s,pos+1,step+1,ans);
    //不翻转
    change(s,pos);
    flip(s,pos+1,step,ans);
}
