#include<cstdio>
#include<algorithm>
using namespace std;
int N,Ans,A[355][355],F[355][355];
int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++){
		for (int j=1;j<=i;j++) scanf("%d",&A[i][j]);
	}
	F[1][1]=A[1][1];
	for (int i=1;i<N;i++){
		for (int j=1;j<=i;j++) F[i+1][j]=max(F[i+1][j],F[i][j]+A[i+1][j]),F[i+1][j+1]=max(F[i+1][j+1],F[i][j]+A[i+1][j+1]);
	}
	for (int i=1;i<=N;i++) Ans=max(Ans,F[N][i]);
	printf("%d\n",Ans);
	return 0;
}
