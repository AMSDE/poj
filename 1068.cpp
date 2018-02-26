#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,N,Now,P[25],Wz[25];
char S[45];
int main()
{
	for (scanf("%d",&T);T;T--){
		scanf("%d",&N);memset(S,0,sizeof S);Now=0;
		for (int i=1;i<=N;i++) scanf("%d",&P[i]);
		for (int i=1;i<=P[1];i++) S[++Now]='(';S[++Now]=')';Wz[1]=Now;
		for (int i=2;i<=N;i++){
			for (int j=1;j<=P[i]-P[i-1];j++) S[++Now]='(';S[++Now]=')';Wz[i]=Now;
		}
		for (int i=1;i<=N;i++){
			int Res=0,L=0;
			for (int j=Wz[i];j;j--){
				if (S[j]==')') L++,Res++;
				else L--;
				if (L==0) break;
			}
			printf("%d%c",Res,i==N?'\n':' ');
		}
	}
	return 0;
}
