#include<bits/stdc++.h>
using namespace std;
int arr[1005][5],dp[1005][5];
int DP(int n,int rng,int clr){
    if(n<rng)return 0;
    if (dp[n][clr]!=-1)return dp[n][clr];
    int ans= INT_MAX;
        for(int i=0;i<3;i++){
            if(i!=clr)ans= min(DP(n-1,rng,i)+arr[n][i],ans);
        }
    return dp[n][clr]=ans;
}
int main()
{
    int c,k=0,ans1,ans2,i,j,n;
    cin>> c;
    while(c--){
        cin>> n;
        memset(dp,-1,sizeof dp);
        for(i=1;i<=n;i++){
            for(j=0;j<3;j++)cin>>arr[i][j];
        }
        ans1= min(DP(n,1,2),min(DP(n,1,0),DP(n,1,1)));
        printf("Case %d: %d\n",++k,ans1);
    }
}

