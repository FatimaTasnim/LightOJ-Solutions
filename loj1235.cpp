#include<bits/stdc++.h>
using namespace std;
long long arr[19];
vector < long long> ans1,ans2;
int s1(int n,long long value){
      ans1.push_back(value);
      if(n==0) return 0;
      s1(n-1,value);
      s1(n-1,value+arr[n]);
      s1(n-1,value+arr[n]+arr[n]);
}
int p;
int s2(int n,long long value){
      ans2.push_back(value);
      if(n==p) return 0;
      s2(n-1,value);
      s2(n-1,value+arr[n]);
      s2(n-1,value+arr[n]+arr[n]);
}
int main()
{
      int c,n,k=0,i,r,flag;
      long long m;
      scanf("%d",&c);
      while(c--){
            ans1.clear();ans2.clear();
            flag=0;
            scanf("%d%lld",&n,&m);
            for(i=1;i<=n;i++){
                  scanf("%lld",&arr[i]);
            }
            sort(arr,arr+n);
            p=n/2;
            s1(n/2,0);
            s2(n,0);
            r=ans1.size();
            sort(ans2.begin(),ans2.end());
            for(i=0;i<r;i++){
                  if(binary_search(ans2.begin(),ans2.end(), m-ans1[i])){
                              printf("Case %d: Yes\n",++k);
                              flag=1;
                              break;
                  }
            }
            if(!flag) printf("Case %d: No\n",++k);
      }
}
