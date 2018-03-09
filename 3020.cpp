#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int fl[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
int N,M,T,Ans,Sum;
int tot,lnk[405],nxt[2505],son[2505],use[2505],Mp[405];
bool vis[405];
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
	for (scanf("%d",&T);T;T--){
		Ans=0;Sum=0;
		memset(use,0,sizeof use);
		memset(Mp,0,sizeof Mp);
		memset(lnk,0,sizeof lnk);
		tot=0;
		scanf("%d%d",&N,&M);getchar();
		for (int i=1;i<=N;i++){
			for (int j=1;j<=M;j++) Mp[(i-1)*M+j]=getchar()=='*',Sum+=Mp[(i-1)*M+j];
			getchar();
		}
		for (int i=1;i<=N;i++){
			for (int j=1;j<=M;j++){
				if (!Mp[(i-1)*M+j]) continue; 
				for (int k=0;k<4;k++){
					int x=i+fl[k][0],y=j+fl[k][1];
					if (x<1||y<1||x>N||y>M||!Mp[(x-1)*M+y]) continue;
					add((i-1)*M+j,(x-1)*M+y);
				}
			}
		}
		for (int i=1;i<=N;i++){
			for (int j=1;j<=M;j++){
				if (Mp[(i-1)*M+j]) {memset(vis,0,sizeof vis);Ans+=match((i-1)*M+j);}
			}
		}
		printf("%d\n",Sum-Ans/2);
	}
	return 0;
}
