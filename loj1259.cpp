#include<bits/stdc++.h>
#define M 10000000
using namespace std;
bool mark[M+2];
vector<int> prime;
void siv()
{
    int i,j;
    mark[0]=1;mark[1]=1;
    prime.push_back(2);
    for(i=3;i<=M;i+=2){
    if(!mark[i]){
        prime.push_back(i);
        for(j=i+i;j<=M;j+=i)
        mark[j]=true;
    }
    }
}
int len;
int Pre(int n)
{
    int i,r,cnt=0,s=n/2;
    for(i=0;i<len&&prime[i]<=s;i++){
            r=n-prime[i];
        if(!mark[r]&&(r%2!=0||r==2)){cnt++;}
    }
    return cnt;
}
int main()
{
    int c,k=0,n;
    siv();
    len=prime.size();
    scanf("%d",&c);
    while(c--){
        scanf("%d",&n);
        printf("Case %d: %d\n",++k,Pre(n));
    }
}

