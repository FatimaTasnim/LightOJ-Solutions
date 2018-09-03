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
int m,n;
int coins[103];
int coin[103][10003];
int coinChangeWay(int m)
{
      for(int i=0;i<=n;i++)coin[i][0]=1;
      for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                  if(j>=coins[i-1]){
                        coin[i][j]= (coin[i-1][j]+coin[i][j-coins[i-1]])%100000007;
                  }
                  else{
                        coin[i][j]= coin[i-1][j]%100000007;
                  }
            }
      }
      return coin[n][m];
}
int main()
{
       int i,j,c,k=0;
      fs(c);
      while(c--){
            ++k;
            fs(n);fs(m);
            for(i=0;i<n;i++)fs(coins[i]);
            printf("Case %d: %d\n",k,coinChangeWay(m));
      }
}
