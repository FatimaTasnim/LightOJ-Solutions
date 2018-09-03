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
int arr[105];
bool dp[105];
double res[105];
double DP(int pos,int n){
      if(pos>=n){
            return 0;
      }
      if(pos+1==n){
            return arr[pos];
      }
      if(dp[pos])return res[pos];
      dp[pos]=1;
      double way;
      way= min(n-pos-1,6);
      res[pos] = arr[pos];
      for(int i=1;i<7;i++){
            res[pos] = res[pos]+(DP(pos+i,n))/way;
      }
      return res[pos];
}
int main()
{
    int n,gold,c,k=0,a,sum,fin,way;
    double p,s;
    fs(c);
    while(c--)
    {
        fs(n);
        sum=fin=way=0;
        memset(dp,0,sizeof dp);
        for(int i=1; i<=n; i++)
        {
            fs(arr[i]);
            //sum+= min(a,6);
        }
        ///DP(1,n,arr[0],fin,way);
        s= fin;
        p=way;
        ///cout << s << " " << p << endl;
        printf("Case %d: %f\n",++k,DP(1,n+1));
    }
}
