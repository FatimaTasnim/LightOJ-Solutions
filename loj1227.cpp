#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,p,q,weight,k=0,a,c,i;
    vector<int> golu;
    scanf("%d",&c);
    while(c--) {
        weight=0;
        golu.clear();
        scanf("%d%d%d",&n,&p,&q);
        for(i=0;i<n;i++) {
            scanf("%d",&a);
            golu.push_back(a);
        }
        for(i=0;i<n;i++) {
            weight=weight+golu[i];
            if(i>=p||weight>q)break;
        }
        printf("Case %d: %d\n",++k,i);
    }
    return 0;
}
