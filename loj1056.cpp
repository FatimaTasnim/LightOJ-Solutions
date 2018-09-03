#include<bits/stdc++.h>
using namespace std;

int main()
{
    int c, k=0;
    double r,s,a,angle,b,x;
    scanf("%d",&c);
    while(c--){
        scanf("%lf : %lf",&a,&b);
        r= sqrt(b*b + a*a)/2.0;
        angle = acos((r*r+r*r- b*b)/(2.0 *r*r));
        s = r*angle;
        x = 400.0/ (2.0*a + 2.0*s);
        printf("Case %d: %.10lf %.10lf\n", ++k, x*a, x*b);
    }
}

///Tutorial: http://shahidul-brur.blogspot.com/2017/04/tutorial-lightoj-1056-olympics.html
