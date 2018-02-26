#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N,dis[105][105],INF,Ans,p;
int main()
{
	while (1){
		scanf("%d",&N);Ans=2e9;p=0;
		if (N==0) return 0;
		memset(dis,63,sizeof dis);INF=dis[0][0];
		for (int i=1;i<=N;i++){
			int x;scanf("%d",&x);
			for (int j=1;j<=x;j++){
				int y,z;scanf("%d%d",&y,&z);
				dis[i][y]=min(dis[x][y],z);
			}
		}
		for (int k=1;k<=N;k++){
			for (int i=1;i<=N;i++){
				for (int j=1;j<=N;j++){
					if (dis[i][k]!=INF&&dis[k][j]!=INF) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		for (int i=1;i<=N;i++){
			int Min=0;
			for (int j=1;j<=N;j++){
				if (i==j) continue;
				Min=max(Min,dis[i][j]);
			}
			if (Min<Ans) Ans=Min,p=i;
		}
		printf("%d %d\n",p,Ans);
	}
	return 0;
}
