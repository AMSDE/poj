#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int fl[6][3]={{0,1,0},{0,-1,0},{1,0,0},{-1,0,0},{0,0,1},{0,0,-1}};
struct ad{
	int x,y,z,s;
	bool operator == (const ad b) const{
		return (x==b.x&&y==b.y&&z==b.z);
	}
}s,t,que[27005];
int Mp[35][35][35],H,N,M,Ans;
bool vis[35][35][35];
int main()
{
	while (1){
		scanf("%d%d%d",&H,&N,&M);
		memset(vis,0,sizeof vis);
		memset(que,0,sizeof que);
		if (H+N+M==0) return 0;
		Ans=2e9;
		for (int i=1;i<=H;i++){
			for (int j=1;j<=N;j++){
				getchar();
				for (int k=1;k<=M;k++){
					char ch=getchar();
					Mp[i][j][k]=0;
					if (ch=='#') Mp[i][j][k]=1;
					if (ch=='S') s.z=i,s.x=j,s.y=k;
					if (ch=='E') t.z=i,t.x=j,t.y=k;
				}
			}
			getchar();
		}
		int h=0,q=1;
		que[1]=s;vis[s.z][s.x][s.y]=1;
		while (h<=q){
			ad p=que[++h];
			for (int i=0;i<6;i++){
				int X=p.x+fl[i][0],Y=p.y+fl[i][1],Z=p.z+fl[i][2];
				if (Mp[Z][X][Y]||X<1||X>N||Y<1||Y>M||Z<1||Z>H||vis[Z][X][Y]) continue;
				que[++q].x=X;que[q].y=Y;que[q].z=Z;que[q].s=que[h].s+1;vis[Z][X][Y]=1;
				if (que[q]==t){
					Ans=min(Ans,que[q].s);
					break;
				}
			}
		}
		if (Ans==2e9) printf("Trapped!\n");
		else printf("Escaped in %d minute(s).\n",Ans);
	}
	return 0;
}
