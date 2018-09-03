#include<bits/stdc++.h>
#define scan(X) scanf("%d",&X)
using namespace std;
int gcd(int a,int b){
    while(b)b^=a^=b^=a%=b;
    return a;
}
int main()
{
    int c,n,a,sum,cnt,k=0,i,ans;
    scan(c);
    while(c--){
        scan(n);
        sum=cnt=0;
        for(i=0;i<n;i++){
            scan(a);
            if(a<0)cnt++;
            sum+= abs(a);
        }
        if(cnt==n)printf("Case %d: inf\n",++k);
        else{
            ans= gcd(sum,n-cnt);
            printf("Case %d: %d/%d\n",++k,sum/ans,(n-cnt)/ans);
        }
    }
}
