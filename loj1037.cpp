#include<bits/stdc++.h>
using namespace std;
int n,k;
int dp[(1<<16)+2];
int health[16];
int arr[16][16];
int do_mask(int pos,int mask){
    return mask= (1<<pos) | mask;
}
bool check(int pos,int mask){
    return mask & (1<<pos);
}
int ceil_in(int a,int b){
    int ans = a/b;
    if((a%b)!=0)ans++;
    return ans;
}
int bitmask_DP(int mask){
    if(mask== (1<<n)-1)return 0;
    if(dp[mask]!= -1)return dp[mask];
    int mn=INT_MAX,minima= INT_MAX;
    for(int i=0;i<n;i++){
        if(!check(i,mask)){
            for(int j=0;j<=n;j++){
                if((check(j,mask) && arr[j][i])|| j==n){
                    minima = min(minima,ceil_in(health[i], arr[j][i])+ bitmask_DP(do_mask(i,mask)));
                }
            }
        }
    }
    return dp[mask]=minima;
}
int main()
{
    int c,i,j;
    string str;
    scanf("%d",&c);
    while(c--){
        scanf("%d",&n);
        for(i=0; i<n; i++){
            scanf("%d",&health[i]);
        }
        for(i=0; i<n; i++){
            cin>> str;
            for(j=0; j<n; j++){
                arr[i][j] = str[j] - '0';
            }
            arr[n][i]=1;
        }
        memset(dp,-1,sizeof dp);
        printf("Case %d: %d\n",++k, bitmask_DP(0));
    }
}
