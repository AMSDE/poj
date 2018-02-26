#include<cstdio>
#include<algorithm>
using namespace std;
const int fl[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int Ans,N,M,sx,sy,tx,ty,Map[25][25];
void dfs(int s,int x,int y){
	if (s>10) return ;
	if (x==tx&&y==ty) {
		Ans=min(Ans,s);
		return ;
	}
	for (int i=0;i<4;i++){
		int xx=x,yy=y,p=0;
		while (Map[xx][yy]!=1){
			xx+=fl[i][0],yy+=fl[i][1];p++;
			if (xx==tx&&yy==ty){
				Ans=min(Ans,s+1);
				break;
			}
			if (xx<1||yy<1||xx>N||yy>M) break;
		}
		if (xx==tx&&yy==ty) continue;
		if (xx<1||yy<1||xx>N||yy>M) continue;
		if (Map[xx][yy]==1&&p>1){
			Map[xx][yy]=0;
			dfs(s+1,xx-fl[i][0],yy-fl[i][1]);
			Map[xx][yy]=1;
		}
	}
}
int main()
{
	while (1){
		scanf("%d%d",&M,&N);Ans=2e9;
		if (N==M&&M==0) return 0;
		for (int i=1;i<=N;i++){
			for (int j=1;j<=M;j++){
				scanf("%d",&Map[i][j]);
				if (Map[i][j]==2) sx=i,sy=j;
				if (Map[i][j]==3) tx=i,ty=j;
			}
		}
		dfs(0,sx,sy);
		printf("%d\n",Ans>10?-1:Ans);
	}
	return 0;
}
