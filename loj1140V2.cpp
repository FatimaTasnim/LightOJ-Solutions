#include<bits/stdc++.h>
int lim;
long long dp[2][2][33];
using namespace std;
vector <long long> store;
long long DP(int pos,bool isSml,bool isStr,int value){
    if(pos==lim)return value;
    if(dp[isSml][isStr][pos]!=-1)return dp[isSml][isStr][pos];
long long ret=0,v=0;

int lmt=isSml?9:store[pos];
int i;
if(!isStr){
    for(i=0;i<=lmt;i++){
        ret+= DP(pos+1,isSml|i<store[pos],0,(i==0)+value);
    }
}
else{
    for(i=1;i<=lmt;i++){
        ret+= DP(pos+1,isSml|i<store[pos],0,(i==0)+value);
    }
    ret+= DP(pos+1,1,1,0);
}
return dp[isSml][isStr][pos]=ret;
}

bool convert(long long n){
    store.clear();
    while(n){
        store.push_back(n%10);
        n/=10;
    }
    reverse(store.begin(),store.end());
    lim= store.size();
}
long long Call_DP(long long n){
    if(n<0)return 0;
    if(n<=9)return 1;
    convert(n);
    return DP(0,0,1,0)+1;
}
int main()
{
    int c,k=0;
    long long n,m,a,b;
    scanf("%d",&c);
    while(c--){
        memset(dp,-1,sizeof dp);
        scanf("%lld%lld",&n,&m);
        a=Call_DP(m);
        memset(dp,-1,sizeof dp);
        b=Call_DP(n-1);
        printf("Case %d: %lld\n",++k,a-b);
    }
}





