#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;

long long Two[MAX+3],Five[MAX+3];

void factorial(){
    long long i, x,two=0,five=0;
    for(i=2;i<=MAX;i++){
        x=i;
        Two[i] = Two[i-1], Five[i] = Five[i-1];
        while(x%2==0)x/=2,Two[i]++;
        while(x%5==0)x/=5,Five[i]++;
    }
}

int main()
{
    factorial();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
    //cout << fact[20] << endl;
    int c,k=0;
    long long n,r,p,q,twO,fivE,two,five,res;
    scanf("%d",&c);
    while(c--){
        scanf("%lld%lld%lld%lld",&n,&r,&p,&q);
        //cout << Two[n] << " " << Two[r] << " " << Two[n-r] << endl;
        two = Two[n]-(Two[r]+Two[n-r]);
        five = Five[n] - (Five[r]+Five[n-r]);
        twO=fivE=0;
        while(p%2==0)p/=2,twO++;
        while(p%5==0)p/=5,fivE++;
        fivE = fivE * q;
        twO = twO * q;
        //cout << two << " " << five << endl;
        res = min(five+fivE, two+twO);
        printf("Case %d: %lld\n",++k,res);
    }
}
