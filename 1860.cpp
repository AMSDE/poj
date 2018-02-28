#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define fst first
#define sec second
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
typedef long long LL;
#define pi pair < int ,int >
#define MP make_pair
 
using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=1E2+7;
int n,m,s;
double v;
double d[N];
bool inq[N];
vector <pair<int,pair<double,double> > > edge[N];
 
int dblcmp(double d)
{
    return d<-eps?-1:d>eps;
}
bool spfa(int s,double amt)
{
    ms(d,0);
    ms(inq,false);
    queue<int>q;
    q.push(s);
    inq[s] = true;
    d[s] = amt;
 
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        inq[u] = false;
 
        int siz = edge[u].size();
        for  ( int i = 0 ; i  < siz; i ++)
        {
            int v = edge[u][i].fst;
            double r = edge[u][i].sec.fst;
            double c = edge[u][i].sec.sec;
            double tmp = (d[u]-c)*r;
            if (dblcmp(d[v]-tmp)<0)
            {
                d[v] = tmp;
                if (inq[v]) continue;
                inq[v] = true;
                q.push(v);
            }
        }
    }
    return d[s]>amt;
}
int main()
{
//        freopen("a.in","r",stdin);
//        freopen("a1.out","w",stdout);
        cin>>n>>m>>s>>v;
        for ( int i = 1 ; i <= m ; i++)
        {
            int u,v;
            double r1,c1,r2,c2;
            cin>>u>>v>>r1>>c1>>r2>>c2;
            edge[u].push_back(MP(v,MP(r1,c1)));
            edge[v].push_back(MP(u,MP(r2,c2)));
        }
 
        if (spfa(s,v)) 
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
    return 0;
}
 
 
 
 