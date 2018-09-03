#include<bits/stdc++.h>
int lim,tt;
long long dp[2][2][33][33];
using namespace std;
vector <long long> check;
long long DP(int pos,int isSml,int value,int prev)
{
    if(pos==lim)return value;
    if(dp[isSml][prev][pos][value]!=-1)return dp[isSml][prev][pos][value];
    long long ret=0,v=0;
    int lmt=isSml?1:check[pos];
    int i;
    for(i=0; i<=lmt; i++)
    {
        ret+= DP(pos+1,isSml|i<check[pos],(prev==i&&i==1)+value,i);
    }
    return dp[isSml][prev][pos][value]=ret;
}
long long call(long long n)
{
    check.clear();
    while(n)
    {
        check.push_back(n%2);
        n/=2;
    }
    reverse(check.begin(),check.end());
    //for(int i=0;i<check.size();i++)cout<<check[i];cout << endl;
    lim= check.size();
    return DP(0,0,0,0);
}
int main()
{
    int c,k=0;
    long long n,m,a,b;
    cin>> c;
    while(c--)
    {
        memset(dp,-1,sizeof dp);
        cin>> m ;
        a=call(m);
        printf("Case %d: %lld\n",++k,a);
    }
}





