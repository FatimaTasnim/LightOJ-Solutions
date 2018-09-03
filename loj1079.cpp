#include<bits/stdc++.h>
using namespace std;
float val[10001],million[10001];
float prob[10001];
int main()
{
    int c,k=0,idx,j,i,banks,sum=0;
    float probability;
    scanf("%d",&c);
    while(c--){
        scanf("%f%d",&probability, &banks);
        for(i=0;i<banks;i++){
            scanf("%f%f",&million[i],&prob[i]);
            sum+= million[i];
        }cerr << "done\n";
        for(i=1;i<=sum;i++)val[i]= 1;
        for(i=0;i<banks;i++){
            cerr  << "Bank  " << i << endl;
            for(int j=sum;j>=1;j--){
                idx= j - million[i];
                if(idx>=0){
                    cerr << "j "<< j << " idx " << idx << " val[j] "<< val[j] << " val[idx] " << val[idx] << " " << val[idx] + (1-val[idx])* prob[i] << endl;
                    val[i]= min( val[j], val[idx] + (1-val[idx]*prob[i]));
                }
            }
        }
    }
}
