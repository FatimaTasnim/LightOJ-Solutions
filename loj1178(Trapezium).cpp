#include<bits/stdc++.h>
using namespace std;
int main()
{
    int p,k=0;
    double a,b,c,d,area,s;
    scanf("%d",&p);
    while(p--){
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        s= (a+b+c+d)/2;
        area=sqrt((s-a)*(s-b)*(s-c)*(s-d)-(a*b*c*d*pow(cos(90),2)));
        printf("Case %d: %lg\n",++k,area);
    }
}
