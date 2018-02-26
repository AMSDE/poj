#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N,idx[205],idy[205],id;
double dis[205][205],INF;
inline int sqr(int x){return x*x;}
inline double cal(int i,int j){return sqrt((double)sqr(idx[i]-idx[j])+sqr(idy[i]-idy[j]));}
int main()
{
	id=1;
	while (1){
		scanf("%d",&N);
		if (N==0) return 0;
		memset(dis,63,sizeof dis);INF=dis[0][0];
		for (int i=1;i<=N;i++) scanf("%d%d",&idx[i],&idy[i]);
		for (int i=1;i<=N;i++) for (int j=i+1;j<=N;j++) dis[i][j]=dis[j][i]=cal(i,j);
		for (int k=1;k<=N;k++){
			for (int i=1;i<=N;i++){
				for (int j=1;j<=N;j++){
					dis[i][j]=min(dis[i][j],max(dis[i][k],dis[k][j]));
				}
			}
		}
		printf("Scenario #%d\n",id);
		printf("Frog Distance = %.3lf\n\n",dis[1][2]);
		id++;
	}
	return 0;
}
