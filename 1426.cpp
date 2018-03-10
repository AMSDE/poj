#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct ad{
	int x,s;
	bool pa[105];
}que[205];
int N,Num;
bool vis,boo[205];
int main()
{
	while (1){
		scanf("%d",&N);Num=0;vis=0;
		if (N==0) return 0;
		memset(boo,0,sizeof boo);
		memset(que,0,sizeof que);
		if (N==1) {printf("1\n");continue;}
		que[1].x=1;que[1].pa[que[1].s=1]=1;
		int h=0,t=1;
		while (h<=t){
			ad q=que[++h];
			for (int i=0;i<2;i++){
				int y=(q.x*10+i)%N;
				if (!boo[y]){
					que[++t]=que[h];que[t].x=y;
					que[t].pa[++que[t].s]=i;boo[y]=1;
					if (y==0){
						for (int j=1;j<=que[t].s;j++) printf("%d",que[t].pa[j]);
						printf("\n");
						vis=1;break;
					}
				}
			}
			if (vis) break;
		}
	}
	return 0;
}
