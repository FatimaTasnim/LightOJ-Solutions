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
int len;
int spr[20][100009],dspr[20][100009];
int arr[100009];
void sparse()
{
    int i,j;
    //for(i=1;i<=len;i++)spr[0][i]=arr[i];
    for(j=1;(1<<j)<=len;j++)
        for(i=1;(i+(1 << j) - 1)<=len;i++)
           spr[j][i]=max(spr[j-1][i],spr[j-1][i+(1<<(j-1))]);
}
void dsparse()
{
    int i,j;
    //for(i=1;i<=len;i++)spr[0][i]=arr[i];
    for(j=1;(1<<j)<=len;j++)
        for(i=1;(i+(1 << j) - 1)<=len;i++)
           dspr[j][i]=min(dspr[j-1][i],dspr[j-1][i+(1<<(j-1))]);
}
int main()
{
    //cout << log(100000);
    int p,k=0,maxima;
    int n,a,r1,r2,r,i,c;
    scan(c);
    while(c--){
    maxima=0;
    scan(n);scan(p);
    len=n;
    for(i=1;i<=n;i++){
       scan(arr[i]);
       dspr[0][i]=spr[0][i]=arr[i];
    }
    sparse();
    dsparse();
        for(i=1;i<=n;i++){
        r1=i;r2=i+p-1;
        if(r2>n)break;
        a=r2-r1+1;
    r= 31-__builtin_clz(a);
    maxima=max(maxima,(max(spr[r][r1],spr[r][(r2)-(1<<r)+1])-min(dspr[r][r1],dspr[r][(r2)-(1<<r)+1])));
    }
    printf("Case %d: %d\n",++k,maxima);
    }
}

