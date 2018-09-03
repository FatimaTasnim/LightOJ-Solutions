#include<bits/stdc++.h>
using namespace std;

int n;
long long rung[100005];

bool check(long long energy){
    long long x;
    for(int i=1;i<n;i++){
        x = rung[i] - rung[i-1];
        if(energy<x)return 0;
        if(energy==x)energy--;
    }
    return 1;
}

long long BS(){
    long long low=0, high=10000000009, mid, ans=0;
    while(low<=high){
        mid = low + (high-low)/2;
        if(check(mid))high= mid-1,ans=mid;
        else low = mid+1;
    }
    return ans;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int c, k=0, i;

    scanf("%d",&c);
    rung[0]=0;
    while(c--){
        scanf("%d",&n);
        n++;
        for(i=1;i<n;i++){
            scanf("%lld",&rung[i]);
        }
        printf("Case %d: %lld\n",++k, BS());
    }
}
