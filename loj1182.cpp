#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c,k=0;
    long long n;
    scanf("%d",&c);
    while(c--){
        scanf("%lld",&n);
        if(__builtin_popcount(n)%2==0)
            printf("Case %d: even\n",++k);
        else printf("Case %d: odd\n",++k);
    }
}
