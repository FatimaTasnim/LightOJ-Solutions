#include<bits/stdc++.h>
using namespace std;
int dp[51][5][7][4];
string arr;
int DP(int n,int i,int vwl,int con,int val){
    int v;
    if(i==n){
        v= ((vwl==3) | (con==5));
        if(vwl==3)vwl=0;if(con==5)con=0;
        return max(v,val);
    }
    if(dp[i][vwl][con][val]!=-1)return dp[i][vwl][con][val];
    else{
        v= ((vwl==3) | (con==5));
        if(vwl==3)vwl=0;if(con==5)con=0;
        v=max(val,v);
        if(arr[i]=='?'){
            int a=DP(n,i+1,vwl+1,0,v);
            int b=DP(n,i+1,0,con+1,v);
            if((a|b)&&((a+b)==1))return dp[i][vwl][con][v]=2;
            return dp[i][vwl][con][v]=max(a,b);
        }
        else{
            if(arr[i]=='A'||arr[i]=='E'||arr[i]=='I'||arr[i]=='O'|arr[i]=='U'){
                return dp[i][vwl][con][v]= DP(n,i+1,vwl+1,0,v);
            }
            else{
                return dp[i][vwl][con][v]= DP(n,i+1,0,con+1,v);
            }
        }
    }
}
int main()
{
    int c,k=0,r;
    cin>>c;
    while(c--){
        cin>> arr;
        memset(dp,-1,sizeof dp);
        r=DP(arr.size(),0,0,0,0);
        //cout << r << endl;
        printf("Case %d: ",++k);
        if(r==1)printf("BAD\n");
        else if(r==2)printf("MIXED\n");
        else printf("GOOD\n");
    }
}

