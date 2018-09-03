#include<bits/stdc++.h>
using namespace std;

int a[103];

int main()
{
    int c,k=0,cnt=0,i,j,n;
    scanf("%d",&c);
    while(c--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        cnt=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(a[j]==i && i!=j){
                    swap(a[i],a[j]);
                    cnt++;
                }
            }
        }
        printf("Case %d: %d\n",++k, cnt);
    }
}
