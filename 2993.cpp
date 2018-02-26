#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int vis[9][9];
struct wz{
	int x,y;
	void read(int id){
		char ch=getchar(),ch1=getchar();
		y=ch-'a'+1;x=8-ch1+'0'+1;
		vis[x][y]=id;
	}
	void pread(char ch,int id){
		char ch1=getchar();
		y=ch-'a'+1;x=8-ch1+'0'+1;
		vis[x][y]=id;
	}
};
struct chess{
	wz K,Q,R,B,N,P;
	void read(int id){
		for (int i=1;i<=7;i++) getchar();
		while (1){
			char ch=getchar();
			if (ch>'Z') P.pread(ch,6+id);
			if (ch=='K') K.read(id+1);
			if (ch=='Q') Q.read(id+2);
			if (ch=='R') R.read(id+3);
			if (ch=='B') B.read(id+4);
			if (ch=='N') N.read(id+5);
			if (getchar()!=',') break;
		}
	}
}W,B;
bool c(int a,int b){return (a==b)||(a==b-7);}
void writeAllline(){printf("+");for (int i=1;i<=8;i++) printf("---+");printf("\n");}
void writeAblock(int x,int y){
	bool Big=1,s=0;int f=vis[x][y];
	if ((x+y)%2==1) printf(":");else printf(".");
	if (f>6) Big=0;
	int D=Big*('a'-'A');
	if (c(f,8)) putchar('k'-D),s++;
	if (c(f,9)) putchar('q'-D),s++;
	if (c(f,10)) putchar('r'-D),s++;
	if (c(f,11)) putchar('b'-D),s++;
	if (c(f,12)) putchar('n'-D),s++;
	if (c(f,13)) putchar('p'-D),s++;
	if (!s) if ((x+y)%2==1) printf(":");else printf(".");
	if ((x+y)%2==1) printf(":");else printf(".");printf("|");
}
void write(){
	writeAllline();
	for (int i=1;i<=8;i++){
		printf("|");
		for (int j=1;j<=8;j++) writeAblock(i,j);
		printf("\n");writeAllline();
	}
}
int main()
{
	W.read(0);
	B.read(7);
	write();
	return 0;
}
