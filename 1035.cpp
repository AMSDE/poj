#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int N;
char S[10005][20];
inline int _abs(int x){return x<0?-x:x;}
inline void p(char B[20]){printf(" %s",B+1);}
void check(char A[20],char B[20]){
	int LA=strlen(A+1),LB=strlen(B+1);
	if (_abs(LA-LB)>1) return ;
	int d=0;
	for (int i=1,j=1;i<=max(LA,LB);i++,j++){
		if (A[i]!=B[j]){d++;if (LA>LB) j--;if (LA<LB) i--;}
		if (d==2) break;
	}
	if (d==1){p(B);return ;}
}
inline bool c(char A[20],char B[20]){
	if (strlen(A+1)!=strlen(B+1)) return 0;
	for (int i=1;i<=strlen(A+1);i++) if (A[i]!=B[i]) return 0;
	return 1;
}
int main()
{
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	for (int i=1;;i++){
		scanf("%s",S[i]+1);
		if (S[i][1]=='#') {N=i-1;break;}
	}
	for (int i=1;;i++){
		char ch[20];bool fl=0;
		memset(ch,0,sizeof ch);
		scanf("%s",ch+1);
		if (ch[1]=='#') break;
		for (int j=1;j<=N;j++){
			if (c(ch,S[j])){
				printf("%s is correct\n",ch+1);
				fl=1;break;
			}
		}
		if (fl) continue;
		printf("%s:",ch+1);
		for (int j=1;j<=N;j++) check(ch,S[j]);
		printf("\n");
	}
	return 0;
}
