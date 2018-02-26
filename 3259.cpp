#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn = 510;
const int maxw = 2500*2+200+10;
const int INF = 10000;
int d[maxn];
int n,m;

struct Edge{
    int u,v;
    int t;
}edge[maxw];

bool bellman_ford()
{
    for(int i = 1; i <= n; i++) d[i] = INF; //初始化从起点到 i 时间为最值
    d[1] = 0; //起点为 0

    for(int i = 1; i < n; i++)
    {
        bool flag = true; //判断这轮是否能够松弛
        for(int j = 0; j < m; j++)
        {
            int u = edge[j].u;
            int v = edge[j].v;
            int t = edge[j].t;

            if(d[v] > d[u]+t) //松弛操作
            {
                d[v] = d[u]+t;
                flag = false;
            }
        }
        if(flag) return false; //如果当前轮不能松弛,直接判断没有负数环
    }

    for(int i = 0; i < m; i++)
    {
        if(d[edge[i].v] > d[edge[i].u]+edge[i].t)
            return true;//如果仍然能够松弛则存在负环
    }
    return false;
}

int main()
{
    int T;
    int M,W;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &n,&M,&W);
        m = 0;

        int u,v,t;
        for(int i = 1; i <= M; i++) //田地间的大路,加双边
        {
            scanf("%d%d%d", &u,&v,&t);
            edge[m].u = u;
            edge[m].v = v;
            edge[m++].t = t;

            edge[m].u = v;
            edge[m].v = u;
            edge[m++].t = t;
        }

        for(int i = 1; i <= W; i++) //孔洞,加单边
        {
            scanf("%d%d%d", &u,&v,&t);
            edge[m].u = u;
            edge[m].v = v;
            edge[m++].t = -t;
        }

        if(bellman_ford()) printf("YES\n"); //存在负数环
        else printf("NO\n");
    }
}
