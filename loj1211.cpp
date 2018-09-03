#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c,k=0,n;
    long long x1,y1,z1,x2,y2,z2,xmin,xmax,ymin,ymax,zmin,zmax, res;
    scanf("%d",&c);
    while(c--){
        scanf("%d",&n);
        xmin=ymin=zmin= 100000;
        xmax=ymax=zmax= 0;
        while(n--){
            scanf("%lld%lld%lld%lld%lld%lld",&x1,&y1,&z1,&x2,&y2,&z2);
            xmin= min(x2,xmin); xmax = max(x1,xmax);
            ymin= min(y2,ymin); ymax = max(y1,ymax);
            zmin= min(z2,zmin); zmax = max(z1,zmax);
        }
        //cout << xmax << " " << xmin << endl;
        res = (xmin-xmax) * (ymin-ymax) * (zmin-zmax);
        printf("Case %d: %lld\n", ++k,res);
    }
}
