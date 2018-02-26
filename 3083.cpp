#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int fl[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
struct xy{int x,y;}S,E;
struct ad{int x,y,s;}que[1605];
int T,M,N,F,Map[45][45];
bool vis=0,boo[45][45],flg=0;
void check(xy &a,int dis,int &Cd){
	if (vis) return ;
	int x=a.x+fl[dis][0],y=a.y+fl[dis][1];
	if (x<1||x>N||y<1||y>M||Map[x][y]!=0) return ;
	a.x=x;a.y=y;vis=1;Cd=dis;
}
int main()
{
	for (scanf("%d",&T);T;T--){
		scanf("%d%d",&M,&N);flg=0;
		memset(que,0,sizeof que);
		memset(boo,0,sizeof boo);
		memset(Map,63,sizeof Map);
		for (int i=1;i<=N;i++){
			getchar();
			for (int j=1;j<=M;j++){
				char ch=getchar();Map[i][j]=0;
				if (ch=='S') S.x=i,S.y=j;
				if (ch=='E') E.x=i,E.y=j;
				if (ch=='#') Map[i][j]=1;
			}
		}
		for (int i=0;i<4;i++) if (Map[S.x+fl[i][0]][S.y+fl[i][1]]==0) F=i;
		xy Now=S;Now.x+=fl[F][0];Now.y+=fl[F][1];int U=1,Nowf=F;
		while (1){
			int Fi=(Nowf+1)%4,Se=Nowf,Th=(Nowf+3)%4,La=(Nowf+2)%4;
			vis=0;check(Now,Fi,Nowf);check(Now,Se,Nowf);check(Now,Th,Nowf);check(Now,La,Nowf);
			U++;if (Now.x==E.x&&Now.y==E.y) {printf("%d ",U+1);break;}
		}
		Now=S;Now.x+=fl[F][0];Now.y+=fl[F][1];U=1,Nowf=F;
		while (1){
			int Fi=(Nowf+3)%4,Se=Nowf,Th=(Nowf+1)%4,La=(Nowf+2)%4;
			vis=0;check(Now,Fi,Nowf);check(Now,Se,Nowf);check(Now,Th,Nowf);check(Now,La,Nowf);
			U++;if (Now.x==E.x&&Now.y==E.y) {printf("%d ",U+1);break;}
		}
		int h=0,t=1;que[1].x=S.x;que[1].y=S.y;boo[S.x][S.y]=1;
		while (h<=t){
			++h;ad p=que[h];
			for (int i=0;i<4;i++){
				int x=p.x+fl[i][0],y=p.y+fl[i][1];
				if (x<1||x>N||y<1||y>M||Map[x][y]!=0||boo[x][y]!=0) continue;
				que[++t].x=x;que[t].y=y;que[t].s=p.s+1;boo[x][y]=1;
				if (que[t].x==E.x&&que[t].y==E.y) {
					printf("%d\n",que[t].s+1);
					flg=1;break;
				}
			}
			if (flg) break;
		}
	}
	return 0;
}
