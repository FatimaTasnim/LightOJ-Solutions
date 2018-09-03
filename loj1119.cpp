#include<bits/stdc++.h>
using namespace std;
int arr[14][14];
int dp[(1<<14)+2];
int n,k;
bool check(int pos,int mask){
    return  mask & (1<<pos);
}
int do_mask(int pos,int mask){
    return mask= mask | (1<<pos);
}
int bitmask_DP(int mask){
    if(mask == pow(2,n)-1)return 0;
    if(dp[mask]!=-1)return dp[mask];
    int minima=INT_MAX;
    for(int i=0;i<n;i++){
        if(!check(i,mask)){
            int temp = arr[i][i];
            for(int j=0;j<n;j++){
                if(i!=j && !check(j,mask)){
                    temp += arr[i][j];
                }
            }
            minima= min(minima,temp+bitmask_DP(do_mask(i,mask)));
        }
    }
    return dp[mask]= minima;
}
int main()
{
    int c,ans;
    scanf("%d",&c);
    while(c--){
        scanf("%d",&n);
        memset(dp,-1,sizeof dp);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)scanf("%d",&arr[i][j]);
        }
        ans= bitmask_DP(0);
        printf("Case %d: %d\n",++k,ans );
    }
}
