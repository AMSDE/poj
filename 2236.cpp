#include<cstdio>
#include<algorithm>
using namespace std;
int N,D,x[1005],y[1005],fa[1005];
bool vis[1005];
inline int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
inline void merge(int x,int y){x=getfa(x);y=getfa(y);if (x!=y) fa[x]=y;}
int main()
{
	scanf("%d%d",&N,&D);
	for (int i=1;i<=N;i++) scanf("%d%d",&x[i],&y[i]),fa[i]=i;
	while (getchar()!=EOF){
		char ch=getchar();
		int p,q;
		scanf("%d",&p);
		if (ch=='S'){scanf("%d",&q);p=getfa(p);q=getfa(q);printf(p==q?"SUCCESS\n":"FAIL\n");}
		if (ch=='O') {
			vis[p]=1;
			for (int i=1;i<=N;i++){
				if (i==p||!vis[i]) continue;
				int a=x[i]-x[p],b=y[i]-y[p];
				if (a*a+b*b<=D*D) merge(i,p);
			}
		}
	}
	return 0;
}
