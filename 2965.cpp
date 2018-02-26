#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int map[5][5];
int x[20]; // ��ʱ·��
int y[20];

int ansX[20]; // ����·��
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
    int x1 = s/4; // ��
    int y1 = s%4; // ��

    for(int i = 0; i < 4; i++)
    {
        map[i][y1] = !map[i][y1];
        map[x1][i] = !map[x1][i];
    }
    map[x1][y1] = !map[x1][y1];
}

bool complete() // �ж��Ƿ�ﵽĿ��
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
            if(map[i][j] == 0) return false;
    }
    return true;
}

void dfs(int s, int b) // �������� s ��, ��ת�� 0��
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

    dfs(s+1, b); //���ܵ� s ����ֱ��������

    flip(s); //��ת�� s ������������
    x[b+1] = s/4+1; //��ʱ��¼·����ע�⡿
    y[b+1] = s%4+1;

    dfs(s+1, b+1); //��ת�� s ����������һ��

    flip(s); //����
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

