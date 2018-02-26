#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N,Ans,dis[105][105];
int low[105];
bool vis[105];
void Mst(){
	int Min=2e9,k=0;vis[1]=1;
	for (int i=1;i<=N;i++) low[i]=dis[1][i];
	for (int i=1;i<N;i++){
		Min=2e9;
		for (int j=1;j<=N;j++) if (!vis[j]&&low[j]<Min) Min=low[j],k=j;
		vis[k]=1;Ans+=Min;
		for (int j=1;j<=N;j++) if (!vis[j]&&low[j]>dis[j][k]) low[j]=dis[j][k];
	}
}
int main()
{
	while (~scanf("%d",&N)){
		memset(vis,0,sizeof vis);
		for (int i=1;i<=N;i++) for (int j=1;j<=N;j++) scanf("%d",&dis[i][j]);
		Ans=0;Mst();
		printf("%d\n",Ans);
	}
	return 0;
}
