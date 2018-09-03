#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c,p,l,q,k=0,r,i;
    set<int>st;
    set<int>::iterator rr;
    scanf("%d",&c);
    while(c--){
        scanf("%d%d",&p,&l);
        q=p-l;
        r=sqrt(q)+1;
        for(i=1;i<=r;i++){
            if(q%i==0){
                if(i>l)st.insert(i);
                if((q/i)>l)st.insert(q/i);
            }
        }
        if(st.size()<1)printf("Case %d: impossible\n",++k);
        else{
            printf("Case %d:",++k);
            while(!st.empty()){
                rr=st.begin();
                printf(" %d",*rr);
                st.erase(st.begin());
            }
            printf("\n");
        }
    }
}
