#include<bits/stdc++.h>
using namespace std;

int days;

int check(int n){
    double probability = 1.0;
    int temp = days, i;

    for(i=1;i<=n;i++){
        probability = probability * ((double)temp/days);
        temp--;
    }
    probability = 1.0-probability;

    cout << n << " " << probability << endl;
    if(probability<0.5)return 0;
    else if(probability>0.5)return 1;
    return 2;
}

int BS(){
    int low=0, high=500, mid,ans;
    while(low<=high){
        mid = (high+low)/2;
        i= check(mid);
        if(i==1){
            //cout << mid << endl;
            ans = mid;
            high = mid;
        }
        else if(i==2)
        else low = mid+1;
    }
    return ans;
}

int main()
{
    int c, k=0;

    scanf("%d",&c);
    while(c--){
        scanf("%d",&days);
        if(days<=2){
            printf("Case %d: 1\n",++k);
            continue;
        }
        printf("Case %d: %d\n",++k ,BS());
    }
}
