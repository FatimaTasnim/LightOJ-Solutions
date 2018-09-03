#include<bits/stdc++.h>
#define MAX 2000000
#define mod 1000000007
using namespace std;

long long fact[MAX+3];

int arr[101];
//long long m =100007;
long long Mod(long long a, long long b){
    long long res = a,c=b,i=0,extra= 1;
    int flag=0;
    if(b%2)flag=1;
    while(c!=1){
        if(c%2 && !(flag && !i)) arr[i]=1;
        i++;
        c/=2;
    }
    for(int j=i-1;j>=0;j--){
        res = (res * res)%mod;
        if(arr[j]==1) res = (res * a)%mod;
    }
   if(flag)res = (res *a)%mod;
    return res%mod;
}

int  main()
{
    fact[0]=1;
    for(long long i=1;i<=MAX;i++){
        fact[i]= (i*fact[i-1])%mod;
    }

    int c,k=0,n,o;
    long long x,y,xy;

    scanf("%d",&c);
    while(c--){
        scanf("%d%d",&n,&o);
        x = fact[n+o-1]; y = (fact[n] * fact[o-1])%mod;
        xy = (x * Mod(y, mod-2))%mod;
        printf("Case %d: %lld\n",++k, xy);
    }

}
