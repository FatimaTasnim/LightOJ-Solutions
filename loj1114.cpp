#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
char line[100002];
string str;
int main()
{
    int n,m,c,i,r,ans,k=0;
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d",&n);
        getchar();
        for(i=0; i<n; i++)
        {
            gets(line);
            str=line;
            if(str.size()>2)sort(str.begin()+1,str.end()-1);
            mp[str]++;
        }
        scanf("%d",&m);
        getchar();
        printf("Case %d:\n",++k);
        stringstream ss;
        while(m--)
        {
            ans=1;
           // getline(cin,line);
            gets(line);
            ss<<line;
            while(ss>>str)
            {
                if(str.size()>2)
                    sort(str.begin()+1,str.end()-1);
                if(mp[str]>0)
                    ans= ans* mp[str];
                else
                {
                    ans=0;
                    break;
                }
            }
            printf("%d\n",ans);
            str.clear();ss.clear();
        }
        mp.clear();
    }
}
