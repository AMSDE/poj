#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
priority_queue<int,vector<int>,greater<int> >hep;
int N;
long long Ans;
int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++){
		int x;scanf("%d",&x);
		hep.push(x);
	}
	while (--N){
		int a=hep.top();hep.pop();int b=hep.top();Ans+=a+b;
		hep.push(a+b);hep.pop();
	}
	printf("%lld\n",Ans);
	return 0;
}
