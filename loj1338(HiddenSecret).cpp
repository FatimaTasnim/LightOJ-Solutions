#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c,k=1,i,flag,cnt1,cnt2;
    string str1,str2;
    scanf("%d",&c);
    while(c--){
        flag=-1;
        cin>> str1 >> str2;
        for(i=1;str1[i];i++){
            if(str1[i]>='A' && str1[i]<='Z')
                cnt1[str1[i]-'A']++;
            if(str1[i]>='a' && str1[i]<='z')
                cnt1[str1[i]-'a']++;
        }
        for(i=1;str2[i];i++){
            if(str2[i]>='A' && str2[i]<='Z')
                cnt2[str1[i]-'A']++;
            if(str2[i]>='a' && str2[i]<='z')
                cnt2[str2[i]-'a']++;
        }
        for(i=0;i<26;i++){
            if(cnt1[i]>=cnt2[i]);
            else flag=-1;
        }
        if(flag==-1){
        for(i=0;i<26;i++){
            if(cnt2[i]>=cnt1[i]);
            else flag=-1;
        }
    }
    if(flag==0)printf("Case %d: Yes\n",k++);
    else printf("Case %d: No\n",k++);
}
