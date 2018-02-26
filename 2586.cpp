#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
//	freopen("a.in","r",stdin);
//	freopen("a1.out","w",stdout);
	int s,d;
	int res;
	while(cin>>s && cin>>d)
	{
		if(d>4*s)res=10*s-2*d;
		else if(2*d>3*s)res=8*s-4*d;
		else if(3*d>2*s)res=6*(s-d);
		else if(4*d>s)res=3*(s-3*d);
		else res=-1;
		if(res<0)cout<<"Deficit"<<endl;
		else cout<<res<<endl;
	}
	return 0;
}
