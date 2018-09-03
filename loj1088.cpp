#include<bits/stdc++.h>
using namespace std;
int arr[100005];
int main()
{
      int c,k=0,n,q,r1,r2,ans,i;
      scanf("%d",&c);
      while(c--){
            scanf("%d%d",&n,&q);
            for(i=0;i<n;i++){
                  scanf("%d",&arr[i]);
            }
            sort(arr,arr+n);
            printf("Case %d:\n",++k);
            while(q--){
                  scanf("%d%d",&r1,&r2);
                  ans=  upper_bound(arr, arr+n,r2)-arr;
                  ans-= lower_bound(arr,arr+n,r1)-arr;
                  printf("%d\n",ans);
            }
      }
}
