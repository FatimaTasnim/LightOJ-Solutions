#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ax,ay,bx,by,cx,cy,dx,dy,c,k=0,area,l,w,h;
    scanf("%d",&c);
    while(c--){
        scanf("%d%d%d%d%d%d",&ax,&ay,&bx,&by,&cx,&cy);
        dx= ax+cx-bx;
        dy= ay+cy-by;
        area= ((ax*by-ay*bx)+(bx*cy-by*cx)+(cx*dy-cy*dx)+(dx*ay-dy*ax))/2;
        if(area<0)area*=-1;
        printf("Case %d: %d %d %d\n",++k,dx,dy,area);
    }
}
