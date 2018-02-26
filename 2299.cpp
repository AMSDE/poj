#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N,A[500005],B[500005];
long long Ans;
inline int read(){
	int Res=0;char ch=getchar();
	while (ch>'9'||ch<'0') ch=getchar();
	while (ch>='0'&&ch<='9') Res=Res*10+ch-'0',ch=getchar();
	return Res;
}
void msort(int L,int R){
	if (L>=R) return ;
	int mid=((R-L)>>1)+L,i=L,j=mid+1;
	msort(i,j-1);msort(j,R);
	while (i<=mid&&j<=R){
		if (A[i]<=A[j]) i++;else j++,Ans+=mid-i+1;
	}
	sort(A+L,A+R+1);
}
int main()
{
	while (1){
		N=read();Ans=0;
		if (N==0) return 0;
		for (int i=1;i<=N;i++) A[i]=read();
		msort(1,N);
		printf("%lld\n",Ans);
	}
	return 0;
}
