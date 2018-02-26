#include<cstdio>
#include<algorithm>
using namespace std;
struct ad{
	int p,id,td,tid[105],tp[105];
}A[105];
int M,N,Ans=2e9;
void dfs(int x,int Sum,int Maxid,int Minid){
	Ans=min(Ans,Sum+A[x].p);
	if (Sum>=Ans) return ;
	for (int i=1;i<=A[x].td;i++){
		int Nid=A[A[x].tid[i]].id;
		if (Nid>Maxid&&Nid-Minid>M) continue;
		if (Nid<Minid&&Maxid-Nid>M) continue;
		dfs(A[x].tid[i],Sum+A[x].tp[i],max(Maxid,Nid),min(Minid,Nid));
	}
}
int main()
{
	scanf("%d%d",&M,&N);
	for (int i=1;i<=N;i++){
		scanf("%d%d%d",&A[i].p,&A[i].id,&A[i].td);
		for (int j=1;j<=A[i].td;j++) scanf("%d%d",&A[i].tid[j],&A[i].tp[j]);
	}
	dfs(1,0,A[1].id,A[1].id);
	printf("%d\n",Ans);
	return 0;
}
