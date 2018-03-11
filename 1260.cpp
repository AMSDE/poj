#include<cstdio>
#include<algorithm>
using namespace std;
int T,N,F[105],A[105],P[105],Sum[105];
int main()
{
	for (scanf("%d",&T);T;T--){
		scanf("%d",&N);
		for (int i=1;i<=N;i++) scanf("%d%d",&A[i],&P[i]),Sum[i]=Sum[i-1]+A[i];
		F[1]=(A[1]+10)*P[1];
		for (int i=2;i<=N;i++){
			F[i]=F[i-1]+(A[i]+10)*P[i];
			for (int j=i-1;j;j--) F[i]=min(F[i],F[j-1]+(Sum[i]-Sum[j-1]+10)*P[i]); 
		}
		printf("%d\n",F[N]);
	}
	return 0;
}
