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
int m,cnt;
int keeper[28];
char str[28];
string arr="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vector<string> vc;
void DP(int pos,int n){
    if(cnt==m)return;
    if(pos==n){
       for(int i=0;i<n;i++)printf("%c",str[i]);
       printf("\n");
        cnt++;
        return;
    }
    for(int i=0;i<n;i++){
        if(keeper[i]){
            keeper[i]=0;
            str[pos]= arr[i];
            DP(pos+1,n);
            keeper[i]=1;
        }
    }
}

int main()
{
    int c,i,n,k=0;
    scan(c);
    while(c--){
        scan(n);scan(m);
        cnt=0;
       // cout << str << endl;
        memset(keeper,1,sizeof keeper);
        printf("Case %d:\n", ++k);
        DP(0,n);
    }
}

