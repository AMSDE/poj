#include<map>
#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
map<string,int>sp;
int N,M,Max,id;
double f[35][35];
int main()
{
	id=1;
	while (1){
		scanf("%d",&N);
		if (N==0) return 0;
		sp.clear();Max=0;
		for (int i=1;i<=N;i++){
			string s;
			cin>>s;
			sp[s]=++Max;
		}
		scanf("%d",&M);
		memset(f,0,sizeof f);
		for (int i=1;i<=M;i++){
			string s,s1;double L=0;
			cin>>s;
			scanf("%lf",&L);
			cin>>s1;
			f[sp[s]][sp[s1]]=L;
		}
		for (int k=1;k<=N;k++){
			for (int i=1;i<=N;i++){
				for (int j=1;j<=N;j++) f[i][j]=max(f[i][j],f[i][k]*f[k][j]);
			}
		}
		for (int i=1;i<=N;i++){if (f[i][i]>1) {printf("Case %d: Yes\n",id);break;}if (i==N) printf("Case %d: No\n",id);}
		id++;
	}
    return 0;
}
