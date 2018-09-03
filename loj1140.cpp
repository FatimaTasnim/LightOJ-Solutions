#include<bits/stdc++.h>
int lim,tt;
long long dp[2][2][33][10];
using namespace std;
vector <long long> check;
long long DP(int pos,int isSml,int isStr,int value){
    if(pos==lim)return value;
    if(dp[isSml][isStr][pos][value]!=-1)return dp[isSml][isStr][pos][value];
long long ret=0,v=0;

int lmt=isSml?9:check[pos];
int i;
if(!isStr){
    for(i=0;i<=lmt;i++){
        ret+= DP(pos+1,isSml|i<check[pos],0,(i==0)+value);
    }
}
else{
    for(i=1;i<=lmt;i++){
        ret+= DP(pos+1,isSml|i<check[pos],0,(i==0)+value);
    }
    ret+= DP(pos+1,1,1,0);
}
return dp[isSml][isStr][pos][value]=ret;
}
long long call(long long n){
    if(n<0)return 0;
    if(n<=9)return 1;
    check.clear();
    while(n){
        check.push_back(n%10);
        n/=10;
    }
    reverse(check.begin(),check.end());
    lim= check.size();
    return DP(0,0,1,0)+1;
}
int main()
{
    int c,k=0;
    long long n,m,a,b;
    cin>> c;
    while(c--){
        memset(dp,-1,sizeof dp);
        cin>> n >> m ;
        a=call(m);
        memset(dp,-1,sizeof dp);
        b=call(n-1);
        printf("Case %d: %lld\n",++k,a-b);
    }
}




