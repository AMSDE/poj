#include<cstdio>
#include<cmath>
double N,P;
int main()
{
    while (~scanf("%lf%lf",&N,&P)) printf("%.0lf\n",exp(log(P)/N));
    return 0;
}
