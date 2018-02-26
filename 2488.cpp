#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int fl[8][2]={{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};
int N,p,q,pa[30][2];
bool fg=0,vis[30][30];
void dfs(int s,int x,int y){
	if (s==p*q){
		for (int i=1;i<=s;i++) printf("%c%d",pa[i][1]+'A'-1,pa[i][0]);
		printf("\n");fg=1;return ;
	}
	if (fg) return ;
	for (int i=0;i<8;i++){
		int xx=x+fl[i][0],yy=y+fl[i][1];
		if (xx<1||yy<1||xx>p||yy>q||vis[xx][yy]) continue;
		vis[xx][yy]=1;pa[s+1][0]=xx;pa[s+1][1]=yy;
		dfs(s+1,xx,yy);
		vis[xx][yy]=0;pa[s+1][0]=0;pa[s+1][1]=0;
		if (fg) return ;
	}
}
int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++){
		scanf("%d%d",&p,&q);fg=0;
		printf("Scenario #%d:\n",i);
		memset(vis,0,sizeof vis);
		for (int j=1;j<=p;j++){
			for (int k=1;k<=q;k++){
				pa[1][0]=j;pa[1][1]=k;vis[j][k]=1;dfs(1,j,k);vis[j][k]=0;pa[1][0]=0;pa[1][1]=0;
				if (fg) break;
			}
			if (fg) break;
		}
		if (!fg) printf("impossible\n");
		if (i!=N) printf("\n");
	}
	return 0;
}
