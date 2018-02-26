#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int map[5][5];
int x[20]; // 临时路径
int y[20];

int ansX[20]; // 最终路径
int ansY[20];
int ans = 33;

void build()
{
    char c;
    memset(map, 0, sizeof(map));
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cin>>c;
            if(c == '-') map[i][j] = 1; //open
            else map[i][j] = 0;
        }
    }
}

void flip(int s)
{
    int x1 = s/4; // 行
    int y1 = s%4; // 列

    for(int i = 0; i < 4; i++)
    {
        map[i][y1] = !map[i][y1];
        map[x1][i] = !map[x1][i];
    }
    map[x1][y1] = !map[x1][y1];
}

bool complete() // 判断是否达到目标
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
            if(map[i][j] == 0) return false;
    }
    return true;
}

void dfs(int s, int b) // 遍历到第 s 个, 翻转了 0个
{
    if(complete())
    {
        if(ans > b)
        {
            ans = b;
            for(int i = 1; i <= ans; i++)
            {
                ansX[i] = x[i];
                ansY[i] = y[i];
            }
        }
        return;
    }

    if(s >= 16) return;

    dfs(s+1, b); //不管第 s 个，直接往下找

    flip(s); //翻转第 s 个了再往下找
    x[b+1] = s/4+1; //临时记录路径【注意】
    y[b+1] = s%4+1;

    dfs(s+1, b+1); //翻转第 s 个了再找下一个

    flip(s); //回溯
}

int main()
{
//		freopen("a.in","r",stdin);
//	freopen("a1.out","w",stdout);
    build();
    dfs(0, 0);
    printf("%d\n", ans);
    for(int i = 1; i <= ans; i++)
    {
        printf("%d %d\n", ansX[i], ansY[i]);
    }
    return 0;
}

