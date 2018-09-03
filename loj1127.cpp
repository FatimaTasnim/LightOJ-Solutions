#include<bits/stdc++.h>
using namespace std;
long long w;
long long arr[33];
vector<long long> ans1 , ans2;
void s1(int n,long long value){
      if(value>w)return;
      if(n==0){
            ans1.push_back(value);
            return;
      }
      s1(n-1,value);
      s1(n-1,value+arr[n]);
}
int p;
void s2(int n,long long value){
      if(value>w )return;
      if(n==p){
            ans2.push_back(value);
            return;
      }
      s2(n-1,value);
      s2(n-1,value+arr[n]);
}
int BinarySearch(long long val)
{
    int low = 0 , high =(int ) ans2.size() - 1 , mid , ans =low -1;
    while (low <= high ) {
        mid = (low + high ) >>1;
        if(ans2[mid] <= val) {
            ans = mid ;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans ;
}
int main()
{
      int c,k=0,n,i,s;
      int cnt;
      scanf("%d",&c);
      while(c--){
            cnt=0;
            ans1.clear();
            ans2.clear();
            scanf("%d%lld",&n,&w);
            for(i=1;i<=n;i++){
                  scanf("%lld",&arr[i]);
            }
            sort(arr,arr+n);
            p=n/2;
            s1(n/2,0);
            s2(n,0);
            int r= ans1.size();
            sort(ans2.begin(),ans2.end());
           /* for(i=0;i<r;i++)cout << ans1[i] << " ";
            cout << endl;
            for(i=0;i< ans2.size();i++)cout << ans2[i] << " ";
            cout << endl;*/
            for(i=0;i<r;i++){
                  s= BinarySearch(w-ans1[i]);
                  //cout << s  << " " << ans1[i]<< endl;
                  cnt+= s+1;
            }
            printf("Case %d: %d\n",++k,cnt);
      }
}
