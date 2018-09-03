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
int nod,n;
int digit[11],arr[11];
int dp[11][11];
int DP(int pos,int prev){
      if(nod==pos) {
           /// for(int i=0;i<nod;i++)printf("%d",arr[i]);
           /// cout << endl;
            return 1;
      }
      if(dp[pos][prev]!=-1)return dp[pos][prev];
      dp[pos][prev]=0;
      int &ret= dp[pos][prev];
      for(int i=1;i<=n;i++){
            if(pos==1){
                       /// cout << " here "  << endl;
                        digit[prev]=digit[i];
            }
            if(abs(digit[prev]-digit[i]) <= 2 ){
                  arr[pos]=digit[i],ret+=  DP(pos+1,i);
            }
            //else break;
      }
      return dp[pos][prev];
}
int main()
{
      int c,k=0;
      fs(c);
      while(c--){
            fs(n),fs(nod);
            nod++;
            for(int i=1;i<=n;i++)fs(digit[i]);
            memset(dp,-1,sizeof dp);
            printf("Case %d: %d\n",++k,DP(1,0));
      }
}
