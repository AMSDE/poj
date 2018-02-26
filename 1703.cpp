#include<cstdio>
#include<algorithm>
using namespace std;
int T,N,M,fa[200005];
inline int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
inline void merge(int x,int y){x=getfa(x);y=getfa(y);if (x!=y) fa[x]=y;}
int main()
{
	for (scanf("%d",&T);T;T--){
		scanf("%d%d",&N,&M);getchar();
		for (int i=1;i<=2*N;i++) fa[i]=i;
		for (int i=1;i<=M;i++){
			char ch=getchar();int x,y;
			scanf("%d%d",&x,&y);
			if (ch=='D') merge(x,y+N),merge(x+N,y);
			if (ch=='A'){
				int fx=getfa(x),fy=getfa(y),Fx=getfa(x+N),Fy=getfa(y+N);
				if (fx==fy||Fx==Fy) printf("In the same gang.\n");
				else if (fx==Fy||fy==Fx) printf("In different gangs.\n");
				else printf("Not sure yet.\n");
			}
			getchar();
		}
	}
	return 0;
}
