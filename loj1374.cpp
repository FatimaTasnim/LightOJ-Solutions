#include<bits/stdc++.h>
using namespace std;

int cnt[1000005];
int main()
{
    int c,n,k=0,flag,i,x;
    scanf("%d",&c);
    while(c--){
        flag=1;
        memset(cnt, 0, sizeof cnt);
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&x);
            if(x>n-1)continue;
            cnt[x]++;
            cnt[n-1-x]++;
        }
        i=0;
        while(i<n){
            if(cnt[i]!=2){
                flag=0;
                break;
            }
            i++;
        }
        if(flag)printf("Case %d: yes\n", ++k);
        else printf("Case %d: no\n",++k);
    }
}
