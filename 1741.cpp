#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N,K,Ans,dis[10005];
int tot,nxt[20005],lnk[10005],son[20005],w[20005];
int Root,Sum,Num,Size[10005],F[10005],Sort[10005];
bool vis[10005];
inline void add(int x,int y,int z){son[++tot]=y;w[tot]=z;nxt[tot]=lnk[x];lnk[x]=tot;}
inline void getrt(int x,int fa){
	F[x]=0;Size[x]=1;
	for (int i=lnk[x];i;i=nxt[i]){
		if (vis[son[i]]||son[i]==fa) continue;
		getrt(son[i],x);
		Size[x]+=Size[son[i]];
		F[x]=max(F[x],Size[son[i]]);
	}
	F[x]=max(F[x],Sum-Size[x]);
	if (F[x]<F[Root]) Root=x;
}
inline void dfs(int x,int fa){
	for (int i=lnk[x];i;i=nxt[i]){
		if (son[i]==fa||vis[son[i]]) continue;
		dis[son[i]]=dis[x]+w[i];
		Sort[++Num]=dis[son[i]];
		dfs(son[i],x);
	}
}
inline int Get(int x,int v){
	dis[x]=v;Sort[Num=1]=dis[x];
	dfs(x,0);int S=0;
	sort(Sort+1,Sort+1+Num);
	for (int i=1,j=Num;i<j;) if (Sort[i]+Sort[j]<=K) S+=j-i,i++;else j--;
	return S;
}
inline void Solve(int x){
	Ans+=Get(x,0);
	vis[x]=1;
	for (int i=lnk[x];i;i=nxt[i]){
		if (vis[son[i]]) continue;
		Ans-=Get(son[i],w[i]);
		Root=0;Sum=Size[son[i]];
		getrt(son[i],0);
		Solve(Root);
	}
}
int main()
{
	while (1){
		scanf("%d%d",&N,&K);
		if (N==K&&N==0) return 0;
		tot=0;
		memset(vis,0,sizeof vis);
		memset(lnk,0,sizeof lnk);
		for (int i=1;i<N;i++){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z);add(y,x,z);
		}
		Root=0;Ans=0;
		F[0]=2e9;Sum=N;
		getrt(1,0);
		Solve(Root);
		printf("%d\n",Ans);
	}
	return 0;
}
