#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,N;
char S[15][65],Ans[65];
void cut(int x,int y){
	if (strlen(Ans+1)<(y-x+1)) {for (int i=x;i<=y;i++) Ans[i-x+1]=S[1][i];return ;}
	for (int i=x;i<=y;i++){
		if (S[1][i]>Ans[i-x+1]) return ;
		if (S[1][i]<Ans[i-x+1]) break;
	}
	for (int i=x;i<=y;i++) Ans[i-x+1]=S[1][i];
}
bool check(int x,int y){
	for (int i=2;i<=N;i++){
		bool fl=0;
		for (int j=1;j<=60-y+x;j++){
			for (int k=x;k<=y;k++){
				if (S[i][j+k-x]!=S[1][k]) break;
				if (k==y) {fl=1;break;}
			}
			if (fl) break; 
		}
		if (!fl) return 0;
	}
	return 1;
}
int main()
{
	for (scanf("%d",&T);T;T--){
		scanf("%d",&N);
		memset(S,0,sizeof S);memset(Ans,0,sizeof Ans);
		for (int i=1;i<=N;i++) scanf("%s",S[i]+1);
		for (int i=1;i<=60;i++){
			for (int j=max(2,(int)strlen(Ans+1)-1);j<=60-i;j++){
				if (check(i,i+j)) cut(i,i+j);
			}
		}
		if (strlen(Ans+1)>2) printf("%s\n",Ans+1);else printf("no significant commonalities\n");
	}
	return 0;
}
