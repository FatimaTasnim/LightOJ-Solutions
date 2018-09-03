#include<bits/stdc++.h>
using namespace std;
int n,k;
int dp[16][(1<<16)+2];
int arr[16][16];
int do_mask(int pos,int mask){
    return mask= mask | (1<<pos);
}
bool check(int pos,int mask){
    return mask & (1<<pos);
}
int ans1;
int bitmask_DP(int pos,int mask){
    if(pos>=n)return 0;
    if(dp[pos][mask]!=-1)return dp[pos][mask];
    for(int i=0;i<n;i++){
        if(!check(i,mask)){
               dp[pos][mask] = max(dp[pos][mask], arr[pos][i] + bitmask_DP(pos+1,do_mask(i,mask)));
        }
    }
    return dp[pos][mask];
}
int main()
{
    int c,i,j;
    scanf("%d",&c);
    while(c--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf("%d",&arr[i][j]);
            }
        }
        memset(dp,-1,sizeof dp);
        printf("Case %d: %d\n",++k,bitmask_DP(0,0));
    }
}
