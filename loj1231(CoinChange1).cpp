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

int k;
int coins[51],noc[51];
int dp[51][1001],mark[51][1001];
int rec(int pos,int wt,int n){
      if(n ==pos ) return wt==0;
      if(mark[pos][wt]==k)return dp[pos][wt];
      mark[pos][wt]=k;
      dp[pos][wt]=0;
      for(int j=0;j<=noc[pos];j++){
            if(j*coins[pos]<=wt){
                  dp[pos][wt]+= rec(pos+1,wt-(j*coins[pos]),n);
                  dp[pos][wt]%=100000007;
            }
      }
      return dp[pos][wt];
}
int main()
{
      int n,i,m,j,c,r;
      fs(c);
      while(c--){
            ++k;
            fs(n);fs(m);
            for(i=0;i<n;i++)fs(coins[i]);
            for(i=0;i<n;i++)fs(noc[i]);
            printf("Case %d: %d\n",k,rec(0,m,n));
      }
}

