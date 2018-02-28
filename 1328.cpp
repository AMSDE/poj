#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
struct
{
    int x, y;
}isl[Max];
struct data
{
    float sta, end;
}rad[Max];
bool cmp(data a, data b)
{
    if(a.end < b.end) 
		return true;
    else 
		return false;
}

int main()
{
    int n, d, t = 1;
    while(cin >> n >> d && n != 0)
	{
        int i, j, max_y = 0;
        for(i = 0; i < n; i ++)
		{
            cin >> isl[i].x >> isl[i].y;
            if(isl[i].y > max_y)
                max_y = isl[i].y;
        }
        getchar();  
		getchar();  //  PE�����Ρ�
		
        cout << "Case " << t ++ << ": ";
        if(max_y > d || d < 0)
		{
            cout << -1 << endl;
            continue;
        }
        float len;
        for(i = 0; i < n; i ++)
		{   //  ���С������Ӧ�״�Ŀ��ܸ��Ƿ�Χ��
            len = sqrt(1.0 * d * d - isl[i].y * isl[i].y);
            rad[i].sta = isl[i].x - len;
            rad[i].end = isl[i].x + len;
        }
        sort(rad, rad + n, cmp);   //  ����rad��endֵ��������
		
        int ans = 0;
        bool vis[Max];
        memset(vis, false, sizeof(vis));
        for(i = 0; i < n; i ++)
		{   //  ���ƵĻѡ��
            if(!vis[i])
			{
                vis[i] = true;
                for(j = 0; j < n; j ++)
                    if(!vis[j] && rad[j].sta <= rad[i].end)
                        vis[j] = true;
					ans ++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

