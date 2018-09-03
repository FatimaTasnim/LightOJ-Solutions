#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c,k=0,t,t1,t2,x1,x2,a,b;
    scanf("%d",&c);
    while(c--){
        scanf("%d%d",&b,&a);
        if(b==0)t=0;
        else{
            t1= a/(2*b);
            x1= t1*(a-(b*t1));
            t2= t1+1;
            x2= t2*(a-(b*t2));
            if(x1>=x2)t=t1;
            else t=t2;
        }
        printf("Case %d: %d\n",++k, t);
    }
}
