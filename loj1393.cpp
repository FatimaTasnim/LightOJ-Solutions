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
    int c,n,k=0,m,a,xorsum,i,j,x;
    scan(c);
    while(c--)
    {
        scan(n);
        scan(m);
        xorsum=0;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                scan(a);
                if(a){
                    x= (n-i) + (m-j);
                    if(x%2 && a)  xorsum ^= a;
                }
            }
        }
       cerr<< xorsum << endl;
        if(xorsum)printf("Case %d: win\n",++k);
        else printf("Case %d: lose\n",++k);
    }
}
