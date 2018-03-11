#include<cstdio>
#include<algorithm>
using namespace std;
int N,Ans,A[1005],F[1005];
int main()
{
	scanf("%d",&N);F[1]=1;
	for (int i=1;i<=N;i++) scanf("%d",&A[i]);
	for (int i=2;i<=N;i++){
		F[i]=1;
		for (int j=i-1;j;j--) if (A[i]>A[j]) F[i]=max(F[i],F[j]+1);
	}
	for (int i=1;i<=N;i++) Ans=max(Ans,F[i]);
	printf("%d\n",Ans); 
	return 0;
} 
