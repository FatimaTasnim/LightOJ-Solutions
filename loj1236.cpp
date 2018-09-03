#include<bits/stdc++.h>
using namespace std;

template<class T>
inline bool fs(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())
        x=x*10+c-'0';
    x*=sgn;
    return ~c;
}
int MOD = 10056;
int horse[1003];
int dp[1003][1003];
int ncr(int n, int r){
      if(r==1)return n;
      if(n==r)return 1;
      if(dp[n][r]!=-1)return dp[n][r];
      return dp[n][r]= (ncr(n-1,r-1)%MOD+ ncr(n-1,r) % MOD) % MOD;
}
int race(int n){
      if(n==0) return 1;
      if(horse[n]!=-1)return horse[n];
      horse [n]=0;
      for(int i=1;i<=n;i++){
            horse[n]= (horse[n]+(ncr(n,i)*race(n-i))%MOD)%MOD;
      }
      return horse[n];
}
int main()
{
      int c,k=0,n;
      fs(c);
      memset(dp,-1,sizeof dp);
      memset(horse,-1,sizeof horse);
      while(c--){
            fs(n);

            printf("Case %d: %d\n",++k,race(n));
      }
}
