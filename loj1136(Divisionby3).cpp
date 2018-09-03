#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n1,n2,c,k=1,r2,r1;
    scanf("%d",&c);
    while(c--){
        scanf("%d%d",&n1,&n2);
        n1--;
        r1= (n1/3)*2;
        if(n1%3==2)r1++;
        r2= (n2/3)*2;
        if(n2%3==2)r2++;
        printf("Case %d: %d\n",k++,(r2-r1));
    }
}
