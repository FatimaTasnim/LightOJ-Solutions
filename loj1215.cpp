#include<bits/stdc++.h>
#define MAX 1000005
#define mod 1000000007
using namespace std;

int length;
bool mark[MAX+5];
long long divisor[MAX+5];
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

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt","w",stdout);

    Sieve();

    int c, k=0,i;
    long long cntL,cnta,cntb,ans,a,b,L;
    scanf("%d",&c);
    while(c--){
        scanf("%lld%lld%lld",&a,&b,&L);
        if(L%a or L%b){
            printf("Case %d: impossible\n",++k);
            continue;
        }
        ans=1;
        for(i=0;i<length and prime[i]<=L;i++){
            cntL=cnta=cntb=0;
            while(L%prime[i]==0)L/= prime[i],cntL++;
            while(a%prime[i]==0)a/= prime[i],cnta++;
            while(b%prime[i]==0)b/= prime[i],cntb++;
            cnta= max(cnta,cntb);
            //cout << prime[i] << " " << cntL << " " << cnta << " " << cntb << endl;
            if(cntL>cnta)
            while(cntL--){
                ans *= prime[i];
            }
        }
        ans*= L;
        printf("Case %d: %lld\n",++k, ans);
    }
}
