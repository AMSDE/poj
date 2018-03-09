#include<cmath>
#include<cstdio>
#include<algorithm>
#define add 12500000
#define Rep(i) for(int i=-50;i<=50;i++)
using namespace std;
int a[6],Ans;
short hsh[25000005];
int main()
{
	for (int i=1;i<=5;i++) scanf("%d",&a[i]);
	Rep(b){
		if (b==0) continue;
		Rep(c){
			if (c==0) continue;
			int p=b*b*b*a[4]+c*c*c*a[5];p=-p;p+=add;
			hsh[p]++;
		}
	}
	Rep(b){
		if (b==0) continue;
		Rep(c){
			if (c==0) continue;
			Rep(d){
				if (d==0) continue;
				int p=b*b*b*a[1]+c*c*c*a[2]+d*d*d*a[3];
				if (p>add||p<-add) continue;p+=add;
				Ans+=hsh[p];
			}
		}
	}
	printf("%d\n",Ans);
	return 0;
}
