#include<cstdio>
#include<algorithm>
using namespace std;
int N,Up[30005],Do[30005],fa[30005];
inline int getfa(int x){if (x==fa[x]) return x;int f=fa[x];fa[x]=getfa(fa[x]);Do[x]+=Do[f];return fa[x];}
inline void merge(int x,int y){
	x=getfa(x);y=getfa(y);
	if (x==y) return ;
	Do[x]=Up[y];Up[y]+=Up[x];fa[x]=y;
}
int main()
{
	scanf("%d",&N);getchar();
	for (int i=1;i<=30000;i++) fa[i]=i,Up[i]=1,Do[i]=0;
	for (int i=1;i<=N;i++){
		char ch=getchar();
		if (ch=='M'){
			int x,y;
			scanf("%d%d",&x,&y);
			merge(x,y);
		}
		else {
			int x;scanf("%d",&x);
			getfa(x);printf("%d\n",Do[x]);
		}
		getchar();
	}
	return 0;
}
