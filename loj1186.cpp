#include<bits/stdc++.h>
using namespace std;
int a[300],b[300];
template<class T>
inline bool scan(T &x)
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
int main()
{
    int n,c,k=0,i,xorsum;
    scan(c);
    while(c--){
        scan(n);
        xorsum=0;
        for(i=0;i<n;i++){
            scan(a[i]);
        }
        for(i=0;i<n;i++){
            scan(b[i]);
        }
        for(i=0;i<n;i++){
            xorsum ^= (b[i]-a[i] -1);
        }
        if(xorsum)printf("Case %d: white wins\n",++k);
        else printf("Case %d: black wins\n",++k);
    }
}
