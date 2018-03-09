#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct ad{
	int x,s;
}que[10005];
int N,A,B,Ans;
bool vis[10000],boo[10000];
int work(int A,int sp,int wz){
	int a[4]={A/1000,(A/100)%10,(A/10)%10,A%10};
	a[wz-1]=sp;
	return (a[0]*1000+a[1]*100+a[2]*10+a[3]);
}
void dfs(int Now,int s){
	if (Now==B){Ans=min(s,Ans);return ;}
	if (s>=Ans) return ;
	for (int i=1;i<=4;i++){
		int Nxt=work(Now,0,i);
		if (i!=1&&!vis[Nxt]&&!boo[Nxt]) boo[Nxt]=1,dfs(Nxt,s+1),boo[Nxt]=0;
		for (int j=1;j<=9;j++){
			Nxt=work(Now,j,i);
			if (vis[Nxt]||boo[Nxt]) continue;
			boo[Nxt]=1;dfs(Nxt,s+1);boo[Nxt]=0;
		}
	}
}
void get(){
	vis[1]=1;
	for (int i=2;i<=9999;i++){
		if (vis[i]) continue;
		for (int j=2;i*j<=9999;j++) vis[i*j]=1;
	}
}
int main()
{
	get();
	scanf("%d",&N);
	for (int i=1;i<=N;i++){
		memset(boo,0,sizeof boo);
		memset(que,0,sizeof que);
		scanf("%d%d",&A,&B);
		if (A==B){
			printf("0\n");continue;
		}
		que[1].x=A;boo[A]=1;
		int h=0,t=1;Ans=2e9;
		while (h<=t){
			int p=que[++h].x;
			for (int i=1;i<=4;i++){
				for (int j=0;j<=9;j++){
					int Nxt=work(p,j,i);
					if (vis[Nxt]||boo[Nxt]||Nxt<1000) continue;
					boo[Nxt]=1;que[++t].x=Nxt;que[t].s=que[h].s+1;
					if (Nxt==B){
						Ans=que[t].s;
						break;
					}
				}
				if (Ans!=2e9) break;
			}
			if (Ans!=2e9) break;
		}
		if (Ans!=2e9) printf("%d\n",Ans);else printf("Impossible\n");
	}
	return 0;
}
