#include<map>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
char ch[15],ch2[15];
map<string,string>hash;
void p(string s){
	for (int i=0;i<s.size();i++) putchar(s[i]);
	putchar('\n');
}
int main()
{
	while (1){
		char s=getchar();int w=-1;
		while (s>'z'||s<'a') s=getchar();
		while (s>='a'&&s<='z') ch[++w]=s,s=getchar();
		if (s!=' '){
			if (hash[ch][0]==0) printf("eh\n");
			else p(hash[ch]);
			break;
		}
		scanf("%s",ch2);
		hash[ch2]=ch;
	}
	while (~scanf("%s",ch)){
		if (hash[ch][0]==0) printf("eh\n");else p(hash[ch]);
	}
	return 0;
}
