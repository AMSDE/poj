#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N,M,Ans,Mp[9][9],vis[9],boo[9];
void dfs(int p,int s){
	if (s==M+1){
		Ans++;return ;
	}
	for (int i=p;i<=N;i++){
		if (vis[i]) continue;
		vis[i]=1;
		for (int j=1;j<=N;j++) if (!boo[j]&&!Mp[i][j]) boo[j]=1,dfs(i+1,s+1),boo[j]=0;
		vis[i]=0;
	}
}
int main()
{
	while (1){
		Ans=0;
		scanf("%d%d",&N,&M);getchar();
		if (N==-1&&M==-1) return 0;
		for (int i=1;i<=N;i++){
			for (int j=1;j<=N;j++) {
				Mp[i][j]=0;
				Mp[i][j]=getchar()=='.';
			}
			getchar();
		}
		dfs(1,1);
		printf("%d\n",Ans);
	}
	return 0;
}
