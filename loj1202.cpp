#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c,r1,r2,c1,c2,k=0,temp1,temp2;
    scanf("%d",&c);
    while(c--){
        scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
        temp1=abs(r1-r2);temp2=abs(c1-c2);
        if(temp1==temp2)printf("Case %d: 1\n",++k);
        else{
        if(temp1%2==temp2%2)printf("Case %d: 2\n",++k);
        else printf("Case %d: impossible\n",++k);
        }
    }
}
