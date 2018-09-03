#include<bits/stdc++.h>
using namespace std;
int arr[1010],nh[1010],ph[1010];
int knapsack1(int n){
    if(n<=0)return 0;
    if(nh[n]!=-1)return nh[n];
    else return nh[n]=max(knapsack1(n-2)+arr[n],knapsack1(n-1));
}
int knapsack2(int n){
    if(n<=1)return 0;
    if(ph[n]!=-1)return ph[n];
    else return ph[n]=max(knapsack2(n-2)+arr[n],knapsack2(n-1));
}
int main()
{
    int c,k=0,r,i;
    scanf("%d",&c);

    while(c--){
        memset(nh,-1,sizeof nh);
        memset(ph,-1,sizeof ph);
        scanf("%d",&r);
        for(i=1;i<=r;i++)scanf("%d",&arr[i]);
        //a1=knapsack1(r-1);a2=knapsack2(r);
        printf("Case %d: %d\n",++k,max(knapsack1(r-1),knapsack2(r)));
    }
}
