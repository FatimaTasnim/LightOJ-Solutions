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
int a,b,i,j,k,c,xorsum,n,m;
int main()
{
    scan(c);
    while(c--){
        scan(n);scan(m);
        xorsum= 0;
       // memset(a,0,sizeof a);
        for(i=0;i<n;i++){
            a=0;
            for(j=0;j<m;j++){
                scan(b);
                a += b;
            }
            xorsum ^= a;
        }
        if(xorsum)printf("Case %d: Alice\n",++k);
        else printf("Case %d: Bob\n",++k);
    }
}
