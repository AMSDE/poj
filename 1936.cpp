#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char A[100005],B[100005];
int main()
{
	while(~scanf("%s%s",A+1,B+1)){
		int LA=strlen(A+1),LB=strlen(B+1);bool fl=0;
		for (int i=1,j=1;j<=LB;i++,j++){
			if (A[i]!=B[j]) i--;
			if (i==LA) {fl=1;printf("Yes\n");break;}
		}
		if (!fl) printf("No\n");
	}
	return 0;
}
