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
long long inv(long long B, long long b){
      long long b0=b,t,q,x0=0,x1=1;
      if(b==1)return 0;
      while(B>1){
            q= B/b;
            t= b;
            b= B%b; B= t;
            t= x0;
            x0= x1- q*x0;
            x1= t;
      }
      if(x1< 0)x1+= b0;
      return x1;
}
int n;
long long B;
long long num[13],rem[13];
long long FindMinX(){
      long long i,b,res=0,x;
      res=0;
      for(i=0;i<n;i++){
            b= B/num[i];
            res+= rem[i] * inv(b, num[i]) * b;
      }
      x= res%B;
      return x;
}
long long mark[41];
int main()
{
      int i,k=0,c,flag;
      fs(c);
      while(c--){
            fs(n);
            flag=1;B=1;
            memset(mark,-1,sizeof mark);
            for(i=0;i<n;i++){
                  fs(num[i]);
                  fs(rem[i]);
                  B*=num[i];
                  if(mark[num[i]]==-1)mark[num[i]]=rem[i];
                  else if(mark[num[i]]!=rem[i])flag=false;
            }
            if(!flag) printf("Case %d: Impossible\n",++k);
            else printf("Case %d: %lld\n",++k, FindMinX());
      }
}

