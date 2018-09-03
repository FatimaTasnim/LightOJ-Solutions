#include<bits/stdc++.h>
using namespace std;

long long arr[100005];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int c, k=0,n,q,op;
    long long pos,i,add,sub, val;
    scanf("%d",&c);
    while(c--){
        add=sub=0;
        scanf("%d%d",&n,&q);
        for(i=0;i<n;i++){
            scanf("%lld",&arr[i]);
        }
        for(i=0;i<n;i++){
            add += (arr[i]*(n-i-1));
            if(i)sub += i*(arr[i]);
        }
        printf("Case %d:\n",++k);
        while(q--){
            scanf("%d",&op);
            if(op==0){
                scanf("%lld%lld",&pos, &val);
                add -= (arr[pos]*(n-pos-1));
                if(pos)sub -= pos*arr[pos];
                arr[pos]=val;
                add += (arr[pos]*(n-pos-1));
                if(pos)sub += pos*(arr[pos]);
            }
            else printf("%lld\n",add-sub);
        }
    }
}
