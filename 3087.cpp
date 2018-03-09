#include<map>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int T,N,id;
char ch[105],ch1[105],s[205],s1[205];
map<string,bool>boo;
int main()
{
	for (scanf("%d",&T);T;T--){
		bool vis=0;boo.clear();int p=0;
		scanf("%d",&N);getchar();
		for (int i=1;i<=N;i++) ch[i-1]=getchar();getchar();
		for (int i=1;i<=N;i++) ch1[i-1]=getchar();getchar();
		for (int i=1;i<=2*N;i++) s[i-1]=getchar();
		while (1){
			p++;
			for (int j=1;j<=N;j++) s1[2*j-2]=ch1[j-1],s1[2*j-1]=ch[j-1];
			for (int j=1;j<=2*N;j++){if (s[j-1]!=s1[j-1]) break;if (j==2*N) printf("%d %d\n",++id,p),vis=1;}
			if (vis||boo[s1]) break;
			for (int j=1;j<=N;j++) ch[j-1]=s1[j-1];
			for (int j=1;j<=N;j++) ch1[j-1]=s1[j-1+N];
			boo[s1]=1;
		}
		if (vis) continue;
		printf("%d %d\n",++id,-1);
	}
	return 0;
}
