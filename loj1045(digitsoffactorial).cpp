#include<bits/stdc++.h>
using namespace std;
double fact[1000005];
int main()
{
    long long i,k=1,ans,a,b,c;
    for(i=1;i<=1000000;i++)
        fact[i]=fact[i-1]+ log(i);
    scanf("%lld",&c);
    while(c--){
        scanf("%lld%lld",&a,&b);
        ans= (fact[a]/(fact[b]-fact[b-1]))+1;
        printf("Case %lld: %lld\n",k++,ans);
    }
}
