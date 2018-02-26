#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
const int fl[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
struct ad{
	int x,y,s;
}que[2505];
int T,N,M,Ans,dis[105][105],idx[105],idy[105],Num;
int low[105],boo[105][105];
bool vis[105],f[55][55];
inline int _abs(int x){return x<0?-x:x;}
void bfs(int id,int x,int y){
	memset(que,0,sizeof que);
	memset(f,0,sizeof f);
	int h=0,t=1;que[1].x=x;que[1].y=y;f[x][y]=1;
	while (h<=t){
		++h;ad p=que[h];
		for (int i=0;i<4;i++){
			int nx=p.x+fl[i][0],ny=p.y+fl[i][1];
			if (nx<1||ny<1||nx>N||ny>M||boo[nx][ny]==-1||f[nx][ny]) continue;
			que[++t].x=nx;que[t].y=ny;que[t].s=p.s+1;f[nx][ny]=1;
			if (boo[nx][ny]!=0) dis[boo[nx][ny]][id]=dis[id][boo[nx][ny]]=que[t].s;
		}
	}
}
void Mst(){
	int Min=2e9,k=0;vis[1]=1;
	for (int i=1;i<=Num;i++) low[i]=dis[1][i];
	for (int i=1;i<Num;i++){
		Min=2e9;
		for (int j=1;j<=Num;j++) if (!vis[j]&&low[j]<Min) Min=low[j],k=j;
		vis[k]=1;Ans+=Min;
		for (int j=1;j<=Num;j++) if (!vis[j]&&low[j]>dis[j][k]) low[j]=dis[j][k];
	}
}
int main()
{
	for (scanf("%d",&T);T;T--){
		scanf("%d%d",&M,&N);Num=1;
		memset(vis,0,sizeof vis);
		char ch[55];gets(ch);
		for (int i=1;i<=N;i++){
			for (int j=1;j<=M;j++){
				char ch=getchar();boo[i][j]=0;
				if (ch=='A') idx[++Num]=i,idy[Num]=j,boo[i][j]=Num;
				if (ch=='S') idx[1]=i,idy[1]=j,boo[i][j]=1;
				if (ch=='#') boo[i][j]=-1;
			}
			getchar();
		}
		for (int i=1;i<=N;i++){
			for (int j=1;j<=M;j++) if (boo[i][j]>0) bfs(boo[i][j],i,j);
		}
		Ans=0;Mst();
		printf("%d\n",Ans);
	}
	return 0;
}
