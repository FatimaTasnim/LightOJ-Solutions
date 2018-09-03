#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int c,k=0,n,cnt,prev,i,get;
    string str;

    scanf("%d",&c);
    while(c--){
        scanf("%d",&n);
        cin>> str;
        get=cnt=0;prev=-1;
        str+='#';
        i=0;
        while(i<n){
            if(str[i]=='.'){
                i+=3;
                cnt++;
            }
            else i++;
        }

        printf("Case %d: %d\n",++k,cnt);
    }
}
