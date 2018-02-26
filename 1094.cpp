#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct ad{
	int x,id;
	bool operator < (const ad b) const{
		return x<b.x;
	}
}S[30];
int N,M,map[205],dl=0;
bool dis[30][30];
int main()
{
	for (int i='A';i<='Z';i++) map[i]=i-'A'+1;
	while (1){
		scanf("%d%d",&N,&M);getchar();
		if (N==0&&M==0) return 0;
		memset(dis,0,sizeof dis);dl=M-1;
		for (int t=1;t<=M;t++,dl--){
			bool fl=0;
			char A=getchar(),B;getchar();B=getchar();getchar();
			if (dis[map[B]][map[A]]){printf("Inconsistency found after %d relations.\n",t);break;}
			dis[map[A]][map[B]]=1;
			for (int k=1;k<=N;k++){
				for (int i=1;i<=N;i++){
					for (int j=1;j<=N;j++){
						if (dis[i][k]&&dis[k][j]&&dis[j][i]) {printf("Inconsistency found after %d relations.\n",t);fl=1;break;}
						dis[i][j]|=dis[i][k]&dis[k][j];
					}
					if (fl) break;
				}
				if (fl) break;
			}
			if (fl) break;
			fl=0;
			for (int i=1;i<=N;i++){
				S[i].x=0;S[i].id=i;
				for (int j=1;j<=N;j++){
					if (i==j) continue;
					if (dis[i][j]&&dis[j][i]) {printf("Inconsistency found after %d relations.\n",t);fl=1;break;}
					S[i].x+=dis[j][i];
				}
				if (fl) break;
			}
			if (fl) break;
			sort(S+1,S+1+N);
			for (int i=1;i<=N;i++) {
				if (S[i].x!=i-1) break;
				if (i==N) {
					printf("Sorted sequence determined after %d relations: ",t);
					for (int j=1;j<=N;j++) printf("%c",S[j].id+'A'-1);
					printf(".\n");fl=1;
				}
			}
			if (fl) break;
			if (t==M) printf("Sorted sequence cannot be determined.\n");
		}
		for (int i=1;i<=4*dl;i++) getchar();
	}
	return 0;
}
