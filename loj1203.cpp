#include<bits/stdc++.h>
#define MAX 100005
#define PI 3.14159265358979323846
using namespace std;

struct Points{
    long long x;
    long long y;
};

Points Pp[MAX], Cc[MAX], P0;
stack <Points> Ss;

long long IsColinear(Points a, Points b, Points c){
    return ((b.y-a.y)*(c.x-b.x))-((c.y-b.y)*(b.x-a.x));
}

long long SqDist(Points a, Points b){
    return ((a.x-b.x)*(a.x-b.x)) + ((a.y-b.y)*(a.y-b.y));
}

double FindAngle(Points a, Points b, Points c){
    double x = sqrt((double)SqDist(a,b));
    double y = sqrt((double)SqDist(b,c));
    double z = sqrt((double)SqDist(c,a));

    return acos((x*x+z*z-y*y)/(2*x*z));
}

bool compare(Points a, Points b){
    if(IsColinear(P0, a, b)==0){
        return SqDist(P0,a)<SqDist(P0,b);
    }

    double d1x = a.x - P0.x, d1y = a.y - P0.y;
    double d2x = b.x - P0.x, d2y = b.y - P0.y;

    return (atan2(d1y, d1x)- atan2(d2y, d2x))<0;
}

Points NextPoint(){
    Points p = Ss.top();
    Ss.pop();
    Points res = Ss.top();
    Ss.push(p);
    return res;
}

double ConvexHull(long long n){
    long long ymin = Pp[0].y, tracker = 0;
    for(int i=1; i<n; i++){
        if(Pp[i].y<ymin || ymin==Pp[i].y && Pp[i].x < Pp[tracker].x){
            ymin = Pp[i].y; tracker = i;
        }
    }
    swap(Pp[0],Pp[tracker]);
    P0 = Pp[0];

    sort(Pp+1, Pp+n, compare);
    int m=1;
    for(int i=1;i<n;i++){
        while(i<n-1 && IsColinear(P0, Pp[i], Pp[i+1])==0)i++;
        Pp[m++] = Pp[i];
    }
    if(m<3)return 0.0;

    Ss.push(Pp[0]), Ss.push(Pp[1]), Ss.push(Pp[2]);

    for(int i=3; i<m; i++){
        while(IsColinear(NextPoint(), Ss.top(), Pp[i])>=0)
            Ss.pop();
        Ss.push(Pp[i]);
    }

    int j,x,k;
    j=x=Ss.size();
    while(!Ss.empty()){
        Points p = Ss.top();
        Cc[--j]=p;
        Ss.pop();
    }

    double res = 180.0;
    for(int i=0; i<x;i++){
        j = (i+1)%x;
        k = (i-1+x)%x;
        res = min (res, (FindAngle(Cc[i], Cc[j], Cc[k])*180)/PI );
    }
    return res;
}

int main()
{
    int c,n,k=0,i;
    scanf("%d",&c);
    while(c--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%lld%lld",&Pp[i].x, &Pp[i].y);
        }
        printf("Case %d: %.10lf\n",++k, ConvexHull(n));
    }
}
