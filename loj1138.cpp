#include<bits/stdc++.h>
#define MOD 1000000000
using namespace std;
int i;
int cnt[100000001];
long long arr[100000001];
void get_trl(){
    arr[1]=1;
    for(i=2;i<=10000000;i++){
        arr[i]= (arr[i-1]*i)%MOD;
        if(arr[i]%10==0){arr[i]/=10;cnt[i]=cnt[i-1]+1;}
        else cnt[i]=cnt[i-1];

    }
}
int main()
{
    get_trl();
    int n,c,k=0;
    scanf("%d",&c);
    while(c--){
        scanf("%d",&n);
        if(cnt[n]==0)printf("Case %d: impossible\n",++k);
        else printf("Case %d: %d\n",++k,cnt[n]);
    }
}
