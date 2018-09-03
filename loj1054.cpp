#include<bits/stdc++.h>
#define MAX 100005
#define mod 1000000007
using namespace std;

int length;
bool mark[MAX+MAX];
long long divisor[MAX+MAX];
vector<long long>prime;

void Sieve(){
    for(int i=4; i<MAX; i+=2)mark[i]=1;
    prime.push_back(2);
    int x;
    for(long long i=3;i<=MAX; i+=2){
        if(!mark[i]){
            prime.push_back(i);
            x= i*2;
            for(long long j=i*i; j<=MAX; j+=x)mark[j]=1;
        }
    }
    length = prime.size();
   // cout << length << endl;
}

long long MODPow(long long a, long long b, long long m){
    long long res = 1;
    while(b){
        if(b & 1)res = ( (res % m) * (a % m) ) %m ;
        a= ((a%m) * (a%m)) %m;
        b >>= 1;
    }
    return res;
}

long long SumofDiv(long long n, long long pw){
    int k=0,cnt;
    long long res =1,ret1,ret2,ret;
    while(n!=1){
        if(length == k || prime[k]>n) break ;
        cnt = 0;
        while(n%prime[k]==0){
            n /= prime[k];
            cnt++;
        }
        if(cnt){
               ret1 =  MODPow(prime[k] ,(cnt*pw) + 1, mod) - 1;
               ret2 =  MODPow((prime[k]-1),mod-2,mod);
               ret=((ret1+mod)%mod * (ret2+mod)%mod )%mod;
               res=(res%mod * ret%mod)%mod ;
        }
        k++;
    }
    if(n!=1){
        ret1 =  MODPow(n ,(pw + 1) , mod) - 1;
        ret2 =  MODPow((n-1),mod-2,mod);
        ret=((ret1+mod)%mod * (ret2+mod)%mod )%mod;
        res=(res%mod * ret%mod)%mod ;
    }
    return res %mod;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    Sieve();
    int c, k=0;
    long long n,m;
    scanf("%d",&c);
    while(c--){
        scanf("%lld%lld",&n,&m);
        printf("Case %d: %lld\n", ++k,SumofDiv(n,m));
    }
}
