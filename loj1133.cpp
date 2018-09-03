#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c,n,m,i,d,k=0;
    int arr[200];
    char ch[2];
    scanf("%d",&c);
    while(c--){
        scanf("%d%d",&n,&m);
        for(i=0; i<n; i++)scanf("%d",&arr[i]);
        while(m--){
            scanf("%s",ch);
            if(ch[0]=='S'){
                scanf("%d",&d);
                for(i=0;i<n;i++)arr[i]+=d;
            }
            if(ch[0]=='M'){
                scanf("%d",&d);
                for(i=0;i<n;i++)arr[i]*=d;
            }
            if(ch[0]=='D'){
                scanf("%d", &d);
                for(i=0;i<n;i++)arr[i]/=d;
            }
            if(ch[0]=='R')
                reverse(arr,arr+ n);
            if(ch[0]=='P'){
                scanf("%d %d",&i,&d);
                swap(arr[i],arr[d]);
            }
        }
        printf("Case %d:\n%d",++k,arr[0]);
        for(i=1; i<n; i++) printf(" %d",arr[i]);
        printf("\n");
    }
    return 0;
}

