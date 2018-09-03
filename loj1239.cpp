#include<bits/stdc++.h>
#define PI 3.14159265358979323846
#define MAX 50005
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

bool compare(Points a, Points b){
    if(IsColinear(P0, a, b)==0){
        return SqDist(P0, a)< SqDist(P0,b);
    }

    double d1x = a.x-P0.x, d1y = a.y-P0.y;
    double d2x = b.x-P0.x, d2y = b.y-P0.y;

    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}

Points NextPoint(){
    Points p = Ss.top();
    Ss.pop();
    Points res = Ss.top();
    Ss.push(p);
    return res;
}

double ConvexHull(int n){
    long long ymin=Pp[0].y, tracker=0;
    for(int i=1;i<n;i++){
        if(Pp[i].y<ymin || (ymin==Pp[i].y and Pp[i].x<Pp[tracker].x))
            ymin=Pp[i].y, tracker = i;
    }

    swap(Pp[0], Pp[tracker]);
    P0= Pp[0];

    sort(&Pp[1], Pp+n, compare);
    long long m=1;

    for(int i=1; i<n; i++){
        while(i<n-1 and IsColinear(P0, Pp[i], Pp[i+1])==0)i++;
        Pp[m++]=Pp[i];
    }

    Ss.push(Pp[0]), Ss.push(Pp[1]), Ss.push(Pp[2]);
    Points ss= Ss.top();
    //cout << ss.x << " hhh " << ss.y << " "<< Pp[2].y << endl;
    for(int i=3; i<m; i++){
        while(IsColinear(NextPoint(), Ss.top(), Pp[i])>=0)
            Ss.pop();
        Ss.push(Pp[i]);
    }

    int x,j;
    x=Ss.size();j=0;
   // cout << j << endl;
    while(!Ss.empty()){
        Points p = Ss.top();
        //cout << "horror " << p.x << " " << p.y << endl;
        Cc[j++]=p;
        Ss.pop();
    }

    Cc[x] = Cc[0];
    double perimeter=0.0;
    for(int i=0; i<x;i++){
        perimeter+= sqrt(SqDist(Cc[i], Cc[i+1]));
        //cout << Cc[i].x << " " << Cc[i].y << " "
          //   << Cc[i+1].x << " " << Cc[i+1].y << endl;
       // cout << "Here " << SqDist(Cc[i], Cc[i+1])<< endl;
    }
    //cout<< "Finally "<< perimeter << endl;
    return perimeter;
}

int main()
{
    //freopen("in.txt", "r",stdin);
    //freopen("out.txt","w",stdout);
    int c, k=0,n,i;
    double xd,ans,d;
    scanf("%d",&c);
    while(c--){
        scanf("%d%lf",&n,&d);
        for(i=0;i<n;i++){
            scanf("%lld%lld",&Pp[i].x, &Pp[i].y);
        }
        xd= 2.0*PI*d;
        if(n==1){
            ans=0;
            printf("Case %d: %.10lf\n",++k, xd+ans);
        }
        else if(n==2){
            double ans = 2.0* sqrt(SqDist(Pp[0],Pp[1]));
            printf("Case %d: %.10lf\n",++k, xd+ans);
        }
        else{
            double ans = ConvexHull(n);
            //cout << "Here I am " << ans  << " " << xd<< endl;
            //cout << ans +xd << endl;
            printf("Case %d: %.10lf\n",++k, xd+ans);
        }

    }
}
