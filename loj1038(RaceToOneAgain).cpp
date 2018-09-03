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
int k;
int mark[100005];
bool mr[100001];
double res[100005];
vector< int > divisor[100005];
void findDivisors(int n){
      if(mr[n])return;
      mr[n]=1;
      int r=sqrt(n);
      for(int i=2;i<=r;i++){
          if(n%i==0){
            divisor[n].push_back(i);
            if((n/i)!=i)divisor[n].push_back(n/i);
          }
      }
      divisor[n].push_back(1);
}
double ExpectedValue(int n){
      if(n==1){
            return 0;
      }
      if(mark[n]){
                  return res[n];
      }
      mark[n]=k;
      findDivisors(n);
      double way= divisor[n].size();
      res[n]=1.0;
      for(int i=0;i<divisor[n].size();i++){
            res[n] = res[n]+ExpectedValue(divisor[n][i]);
      }
      res[n]= (res[n]+way)/(way);
      return res[n];
}
int main()
{
      int c,n;
      fs(c);
      while(c--){
            fs(n);
            ++k;
           printf("Case %d: %.6lf\n",k, ExpectedValue(n));
      }
}
