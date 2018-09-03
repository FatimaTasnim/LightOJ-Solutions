#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c,k=0;
    double a,b,d, h, area, tarea,x,s,e;
    scanf("%d",&c);
    while(c--){
        scanf("%lf%lf%lf%lf", &a,&b,&d,&e);
        x= fabs(a-d);
        s= (x+b+e); s*=0.5;
        tarea = sqrt(s*(s-x)*(s-b)*(s-e));
        h = tarea*2.0;
        h/=x;
        area = 0.5*(a+d)*h;
        printf("Case %d: %.10lf\n", ++k, area);
    }
}
