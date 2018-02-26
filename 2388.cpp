#include<cstdio>
#include<algorithm>
using namespace std;
int N,A[10005];
int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++) scanf("%d",&A[i]);
	sort(A+1,A+1+N);
	printf("%d\n",A[(N+1)/2]);
	return 0;
}
