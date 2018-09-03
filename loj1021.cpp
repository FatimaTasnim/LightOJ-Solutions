#include<bits/stdc++.h>
using namespace std;
int n,base,divi;
int arr[21];
long long dp[21][(1<<17)];
long long PainfulBases(int val,int mask){
      if( mask == (1<<n)-1) return val==0;
      if(dp[val][mask]!=-1) return dp[val][mask];
      dp[val][mask]=0;
      for(int i=0;i<=n;i++){
            if(!(mask & (1<<i))){
                 dp[val][mask]+= PainfulBases((val*base + arr[i])%divi, (mask | (1<<i))) ;
            }
      }
      return dp[val][mask];
}
int main()
{
      int c,k=0,i;
      string str;
      scanf("%d",&c);
      while(c--){
            scanf("%d%d",&base, &divi);
            cin>> str;
            for(i=0;str[i];i++){
                  if(str[i]>= '0' && str[i]<= '9')arr[i]= str[i]-'0';
                  else arr[i] = str[i]- 'A' + 10;
            }
            n=i;
            memset(dp,-1,sizeof dp);
            printf("Case %d: %lld\n",++k,PainfulBases(0,0));
      }
}
