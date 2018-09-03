#include<bits/stdc++.h>
using namespace std;
vector<long long>vc;
int main()
{
    int r,cr,c,cnt,i,k=0;
    long long x,y,arr;
    scanf("%d",&cr);
    while(cr--)
    {
        cnt=1;
        scanf("%d%d",&r,&c);
        for(i=0;i<r;i++)
        {
            scanf("%lld%lld",&x,&y);
            vc.push_back(y);
        }
        sort(vc.begin(),vc.end());
        arr=vc[0];
        for(int i=1;i<r;i++){
            if(vc[i]-arr>c){
                cnt++;
                arr=vc[i];
            }
        }
        printf("Case %d: %d\n",++k,cnt);
        vc.clear();
    }
}
