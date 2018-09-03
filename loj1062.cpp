#include<bits/stdc++.h>
using namespace std;

int main()
{
    int c, k=0;
    double x,y,low,high,mid,h1,h2,h,th;
    scanf("%d",&c);
    while(c--){
        scanf("%lf%lf%lf",&x,&y,&h);

        low= 0.0, high = max(x,y);
        for(int i=0;i<100;i++){
            mid = (low+high)/2.0;
            h2 = sqrt((y*y)-(mid*mid));
            h1 = sqrt((x*x)-(mid*mid));
            th = (1.0/h1) + (1.0/h2);
            th = 1.0/th;
            if(th >= h)low = mid;
            else high = mid;
        }

        printf("Case %d: %.10lf\n",++k,low);
    }
}

/// Tutorial : http://ojsolver.blogspot.com/2016/04/uva-10566-lightoj-1062-crossed-ladders.html
