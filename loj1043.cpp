#include<bits/stdc++.h>
using namespace std;
double ab,ac,bc,ratio_;
double TrianglePartitioning(double ad){
      double ae,de,areaS,areaL,areaT,p;
      ae= (ad*ac)/ab, de= (ad*bc)/ab;
      p= (ad+de+ae)/2.0;
      areaS= p* (p-ad)*(p-de)*(p-ae);
      areaS = sqrt(areaS);
      p= (ab+ac+bc)/2.0;
      areaL= p*(p-ab)*(p-bc)*(p-ac);
      areaL= sqrt(areaL);
      areaT= areaL-areaS;
      return areaS/areaT;
}
double BinarySearch(){
      double low=0.0, high= ab,mid,ad;
      for(int i=0;i<100;i++){
            mid= (low+high)/2.0;
            ad=mid;
            if(TrianglePartitioning(mid)>ratio_)high=mid;
            else low=mid;
      }
      return ad;
}
int main()
{
      int c,k=0;
      scanf("%d",&c);
      while(c--){
            scanf("%lf%lf%lf%lf",&ab,&ac,&bc,&ratio_);
           // cout << ab << " " << ac << " " << bc << " " << ratio_ << endl;
            printf("Case %d: %.10f\n",++k,BinarySearch());
      }
}
