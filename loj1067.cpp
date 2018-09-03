#include<bits/stdc++.h>
using namespace std;
long long f[1000003];
long long m= 1000003;
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

/*long long Mod(long long n, long long mm){
      if(mm==1)
        return n;
    if(mm%2==1)
        return(Mod(n,mm-1)*n)%m;
    else{
        long long res=Mod(n,mm/2);
        return (res*res)%m;
    }
}*/

int arr[101];
//long long m =100007;
long long Mod(long long a, long long b){
    long long res = a,c=b,i=0,extra= 1;
    int flag=0;
    if(b%2)flag=1;
    while(c!=1){
        if(c%2 && !(flag && !i)) arr[i]=1;
        i++;
        c/=2;
    }
    for(int j=i-1;j>=0;j--){
        res = (res * res)%m;
        if(arr[j]==1) res = (res * a)%m;
    }
   if(flag)res = (res *a)%m;
    return res%m;
}


int main()
{
      f[1]=1;
      for(int i=2;i<=1000001;i++){
            f[i]= (f[i-1]*i)%m;
      }
      int c,k=0,n,r;
      long long temp;
      fs(c);
      while(c--){
            fs(n);fs(r);
            if(n<r){
                 printf("Case %d: 0\n",++k);
                 continue;
            }
            else if(n==r||r==0){
                printf("Case %d: 1\n",++k);
                continue;
            }
            temp = ((f[n-r]%m )*(f[r]%m))%m;
            printf("Case %d: %lld\n",++k,f[n]*Mod(temp,m-2)%m);
      }
}
