//求出每个岛屿对应的雷达区间
//化成最少的点数能出现在每个区间的问题
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct
{
    double left;
    double right;
}island;

island isl[1001];
int n,d,sum;

//根据右端点排序
int cmp(const void *a, const void *b)
{
    return (*(island*)a).right >= (*(island*)b).right ? 1 : -1;
}

void solve()
{
    int i;
    double std;
    qsort(isl,n,sizeof(island),cmp);
    sum = 1;
    std = isl[0].right;//最小的右端点
    for(i=1;i<n;i++)
    {
        if(isl[i].left > std)
        {
            std = isl[i].right;
            sum++;
        }
    }
}

int main()
{
    int x,y,i,count,fail;
    double l;
    count = 1;
    while(1)
    {
        fail = 0;
        scanf("%d%d",&n,&d);
        if(n+d == 0)
            break;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            if(y > d)
                fail = 1;
            else
            {
                l = sqrt((double)(d*d - y*y));
                isl[i].left = x - l;
                isl[i].right = x + l;
            }
        }
        if(fail)
        {
            sum = -1;
            printf("Case %d: %d\n",count++,sum);
        }
        else
        {
            solve();
            printf("Case %d: %d\n",count++,sum);
        }
    }
    return 0;
}
