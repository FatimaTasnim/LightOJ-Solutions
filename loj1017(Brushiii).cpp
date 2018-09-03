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
int n,m;
int x,y[101],nxt[101],cnt[101];
int dp[101][101];

int DP(int pos,int moves){
      if(moves==m || pos==n)return 0;
      if(dp[pos][moves]!=-1)return dp[pos][moves];
      return dp[pos][moves]= max(DP(nxt[pos], moves+1)+cnt[pos], DP(pos+1,moves));
}
int main()
{
      int w,c,k=0,j;
      fs(c);
      while(c--){
         memset(dp,-1,sizeof dp);
         memset(cnt,-1,sizeof cnt);
        fs(n);fs(w);fs(m);
        for(int i=0; i<n; i++){
            fs(x);fs(y[i]);
        }
        sort(y,y+n);
        for(int i=0; i<n; i++){
            for(j=i; j<n && (y[j]-y[i]<=w) ; j++);
            nxt[i]=j;
            cnt[i]=j-i;
        }
        printf("Case %d: %d\n",++k,DP(0,0));
      }
}
