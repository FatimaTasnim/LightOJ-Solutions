#include<bits/stdc++.h>
using namespace std;
int main() {
    int c,n,g,r,i,k=0;
    int arr[110];
    scanf("%d",&c);
    while(c--){
        scanf("%d",&n);
        for(i=1;i<=n;i++)scanf("%d",&arr[i]);
        g=0,r=2;
        for(i=1;i<=n;i++){
            if(arr[i]>r){
                g+=ceil((arr[i]-r)/5.0);
                r=arr[i];
                }
        }
        printf("Case %d: %d\n",++k,g);
    }
}
