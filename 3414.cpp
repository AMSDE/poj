#include<vector>
#include<cstdio>
#include<bitset>
#include<cstdlib>
#include<algorithm>
using namespace std;
vector<bitset<3> >::iterator p;
struct ad{
	int a,b,s;
	vector<bitset<3> >path;
}que[100005];
int A,B,C,h=0,t=1;
bool vis[105][105];
void pt(int x){
	if (x==1||x==2) printf("FILL(%d)\n",x);
	if (x==3||x==4) printf("DROP(%d)\n",x-2);
	if (x==5||x==6) printf("POUR(%d,%d)\n",x-4,7-x); 
}
void add(int a,int b,int id){
	que[++t]=que[h];
	que[t].a=a;que[t].b=b;que[t].s++;
	(que[t].path.push_back)(id);vis[a][b]=1;
	if (a==C||b==C){
		printf("%d\n",que[t].s);
		for (p=que[t].path.begin();p!=que[t].path.end();p++) pt((*p).to_ulong());
		exit(0);
	}
}
int main()
{
	scanf("%d%d%d",&A,&B,&C);vis[0][0]=1;
	while (h<=t){
		ad x=que[++h];
		if (!vis[A][x.b]) add(A,x.b,1);
		if (!vis[x.a][B]) add(x.a,B,2);
		if (!vis[0][x.b]) add(0,x.b,3);
		if (!vis[x.a][0]) add(x.a,0,4);
		if (!vis[max(0,x.b+x.a-B)][min(B,x.b+x.a)]) add(max(0,x.b+x.a-B),min(B,x.b+x.a),5);
		if (!vis[min(A,x.a+x.b)][max(0,x.a+x.b-A)]) add(min(A,x.a+x.b),max(0,x.a+x.b-A),6);
	}
	printf("impossible\n");
	return 0;
}
