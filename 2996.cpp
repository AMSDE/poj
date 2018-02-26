#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct wz{
	int x,y;
	bool operator < (const wz b) const{
		return (x>b.x)||(x==b.x&&y<b.y);
	}
	bool operator > (const wz b) const{
		return (x<b.x)||(x==b.x&&y<b.y);
	}
	void write(char ch,int f,int id){
		if (x==0) return ;
		if (ch!='P') printf("%c",ch);
		printf("%c%d",y+'a'-1,8-x+1);
		if (f!=id) printf(",");
	}
	void pwrite(int M,int id){
		if (x==0) return ;
		printf("%c%d",y+'a'-1,8-x+1);
		if (M!=id) printf(",");
	}
};
bool cmp(wz a,wz b){return a>b;}
struct chess{
	wz K,Q,R,R1,B,B1,N,N1,P[8];
	int Max,f;
	void get(char ch,int x,int y){
		if (ch>'Z') ch='A'+ch-'a';
		wz ep;ep.x=x;ep.y=y;
		if (ch=='K') K=ep;
		if (ch=='Q') Q=ep;
		if (ch=='R') if (R.x==0) R=ep;else R1=ep;
		if (ch=='B') if (B.x==0) B=ep;else B1=ep;
		if (ch=='N') if (N.x==0) N=ep;else N1=ep;
		if (ch=='P') for (int i=0;i<8;i++) if (P[i].x==0){P[i]=ep,Max=i;break;}
	}
	void getf(){
		if (Max!=0) {f=6;return ;}
		if (N.x!=0) {f=5;return ;}
		if (B.x!=0) {f=4;return ;}
		if (R.x!=0) {f=3;return ;}
		if (Q.x!=0) {f=2;return ;}
		if (K.x!=0) {f=1;return ;}
	}
	void write(int ws){
		getf();
		if (ws==1){
			sort(P,P+Max+1);
			if (N1.x!=0&&N1<N) swap(N,N1);
			if (B1.x!=0&&B1<B) swap(B,B1);
			if (R1.x!=0&&R1<R) swap(R,R1);
		}else{
			sort(P,P+Max+1,cmp);
			if (N1.x!=0&&N1>N) swap(N,N1);
			if (B1.x!=0&&B1>B) swap(B,B1);
			if (R1.x!=0&&R1>R) swap(R,R1);
		}
		K.write('K',f,1);Q.write('Q',f,2);
		R.write('R',f,3);R1.write('R',f,3);
		B.write('B',f,4);B1.write('B',f,4);
		N.write('N',f,5);N1.write('N',f,5);
		for (int i=0;i<8;i++) P[i].pwrite(Max,i);
		printf("\n");
	}
}W,B;
void readAllline(){for (int i=1;i<=33;i++) getchar();getchar();}
void readAblock(int x,int y){
	getchar();
	char ch=getchar();
	if (ch=='.'||ch==':') {getchar();getchar();return ;}
	if (ch>'Z') B.get(ch,x,y);
	else W.get(ch,x,y);
	getchar();getchar();
}
void read(){
	readAllline();
	for (int i=1;i<=8;i++){
		getchar();
		for (int j=1;j<=8;j++) readAblock(i,j);
		getchar();readAllline();
	}
}
int main()
{
	read();
	printf("White: ");W.write(1);
	printf("Black: ");B.write(0);
	return 0;
}
