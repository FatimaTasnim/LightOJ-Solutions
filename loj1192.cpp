#include<bits/stdc++.h>
using namespace std;
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
    int c,k=0,a,b,xorsum,n,i;
    scan(c);
    while(c--){
        scan(n);
        xorsum=0;
        for(i=0;i<n;i++){
            scan(a);scan(b);
            xorsum ^= (b-a-1);
        }
        if(xorsum)printf("Case %d: Alice\n",++k);
        else printf("Case %d: Bob\n",++k);
    }
}
