#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,N,num,dis[305][305];
int low[305];
bool vis[305];
void Mst(){
	int Min=2e9,k=0;vis[1]=1;
	for (int i=1;i<=N;i++) low[i]=dis[1][i];
	for (int i=1;i<N;i++){
		Min=2e9;
		for (int j=1;j<=N;j++) if (!vis[j]&&low[j]<Min) Min=low[j],k=j;
		vis[k]=1;
		for (int j=1;j<=N;j++) if (!vis[j]&&low[j]>dis[j][k]) low[j]=dis[j][k];
	}
	sort(low+1,low+1+N);
}
int main()
{
	for (scanf("%d",&T);T;T--){
		scanf("%d",&N);
		memset(vis,0,sizeof vis);
		for (int i=1;i<=N;i++) for (int j=1;j<=N;j++) scanf("%d",&dis[i][j]);
		Mst();printf("%d\n",low[N]);
	}
	return 0;
}
