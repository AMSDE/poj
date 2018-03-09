#include<map>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define add 10000
using namespace std;
struct ad{
	int x,y;
	bool operator < (const ad b) const{
		return (x<b.x)||(x==b.x&&y<b.y);
	}
	ad operator + (const ad b) const{
		ad c;c.x=x+(b.y-y);c.y=y-(b.x-x);
		return c;
	}
}A[1005];
int N,Numx,Numy,hshx[20005],hshy[20005];
bool vis[1005][1005];
int main()
{
	while (1){
		scanf("%d",&N);int Ans=0;
		memset(vis,0,sizeof vis);
		memset(hshx,0,sizeof hshx);
		memset(hshy,0,sizeof hshy);
		if (N==0) return 0;
		Numx=Numy=0;
		for (int i=1;i<=N;i++){
			scanf("%d%d",&A[i].x,&A[i].y);
			if (!hshx[A[i].x+add]) hshx[A[i].x+add]=++Numx;
			if (!hshy[A[i].y+add]) hshy[A[i].y+add]=++Numy;
			vis[hshx[A[i].x+add]][hshy[A[i].y+add]]=1;
		}
		for (int i=1;i<=N;i++){
			for (int j=1;j<=N;j++){
				if (i==j) continue;
				ad b=A[i]+A[j];
				if (!vis[hshx[b.x+add]][hshy[b.y+add]]) continue;
				ad c=b+A[i];
				if (vis[hshx[c.x+add]][hshy[c.y+add]]) Ans++;
			}
		}
		printf("%d\n",Ans/4);
	}
	return 0;
}
