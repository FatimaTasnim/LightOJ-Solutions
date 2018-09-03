#include<bits/stdc++.h>
using namespace std;

int main()
{
    int c, k=0;
    long long x,y,ax,ay,bx,by;
    scanf("%d",&c);
    while(c--){
        scanf("%lld%lld%lld%lld",&ax,&ay,&bx,&by);
        x = abs(ax-bx), y = abs(ay-by);
        if(x==0)x = y+1;
        else if(y==0)x = x+1;
        else x = __gcd(x,y)+1;
        printf("Case %d: %lld\n",++k,x);
    }
}
