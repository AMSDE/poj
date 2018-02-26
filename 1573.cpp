#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int fl[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int N,M,D;
int vis[1005][1005],Map[1005][1005];
int main()
{
	while (1){
		scanf("%d%d%d",&N,&M,&D);
		if (N==0&&M==0&&D==0) return 0;
		for (int i=1;i<=N;i++){
			getchar();
			for (int j=1;j<=M;j++){
				vis[i][j]=0;char ch=getchar();
				Map[i][j]=(ch=='N')+2*(ch=='S')+3*(ch=='E')+4*(ch=='W')-1;
			}
		}
		int Nx=1,Ny=D;vis[1][D]=1;
		while (1){
			int p=Map[Nx][Ny],e=vis[Nx][Ny];
			Nx+=fl[p][0];Ny+=fl[p][1];
			if (Nx==0||Ny==0||Nx==N+1||Ny==M+1) {printf("%d step(s) to exit\n",e);break;}
			if (vis[Nx][Ny]!=0) {printf("%d step(s) before a loop of %d step(s)\n",vis[Nx][Ny]-1,e-vis[Nx][Ny]+1);break;}
			vis[Nx][Ny]=e+1;
		}
	}
	return 0;
}
