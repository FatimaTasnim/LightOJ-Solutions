#include<bits/stdc++.h>
using namespace std;
vector <int> vc[55];
int arr[55];
int main()
{
    int c,k=0,i,j,q,m,n,p,flag1,flag2,a;
    scanf("%d",&c);
    while(c--){
        scanf("%d%d%d",&n,&m,&q);
        memset(arr,0,sizeof arr);
        for(i=1;i<=n;i++){
            vc[i].clear();
            vc[i].push_back(0);
            for(j=1;j<=q;j++){
                scanf("%d",&a);
                vc[i].push_back(a);
            }
        }
        scanf("%d",&p);
        for(i=0;i<p;i++)scanf("%d",&a), arr[a]=true;
        flag2=0;
        for(i=1;i<=n;i++){
            flag1=0;
            for(j=1;j<=q;j++){
                if(vc[i][j]<0 and !arr[-vc[i][j]])flag1=true;
                if(vc[i][j]>0 and arr[vc[i][j]])flag1=true;
            }
            if(!flag1)flag2= true;
        }
        if(flag2){
            printf("Case %d: No\n",++k);
            continue;
        }
        printf("Case %d: Yes\n",++k);
    }
}
