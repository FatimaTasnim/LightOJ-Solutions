#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
int main()
{
    //freopen("out.txt","w",stdout);
    int n,m,c,i,r,ans,k=0;
    string line,str,se;
    scanf("%d",&c);
    while(c--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            cin>>str;
            if(str.size()>2)
            sort(str.begin()+1,str.end()-1);
            mp[str]++;
        }
        scanf("%d",&m);
        getchar();
        printf("Case %d:\n",++k);
        while(m--){

        ans=1;
        getline(cin,line);
        stringstream ss(line);
        while(ss>>line){
            if(str.size()>2)
            sort(line.begin()+1,line.end()-1);
            //cout << line << mp[se] << endl;
            ans= ans* mp[line];
        }
        printf("%d\n",ans);
        }
        mp.clear();
    }
}
