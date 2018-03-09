#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N,M,Ans;
int tot,lnk[1005],nxt[20005],son[20005],use[20005];
bool vis[1005];
bool match(int x){
	for (int i=lnk[x];i;i=nxt[i]){
		if (!vis[son[i]]){
			vis[son[i]]=1;
			if (!use[son[i]]||match(use[son[i]])) {use[son[i]]=x;return 1;}
		}
	}
	return 0;
}
inline void add(int x,int y){son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;}
int main()
{
	scanf("%d%d",&N,&M);
	for (int i=1;i<=M;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	for (int i=1;i<=N;i++) {memset(vis,0,sizeof vis);Ans+=match(i);}
	printf("%d\n",Ans);
	return 0;
}
