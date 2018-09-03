#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
int sum1,last,sum2;
int s1[102],s2[102];
bool mark[102];
map< int, vector < pair<int,int> > > arr,rev;
void DFS(int src){
    int i,a;
    mark[src]=1;
    last=src;
    for(i=0;i<rev[src].size();i++){
        a=rev[src][i].f;
        if(!mark[a]){
            mark[a]=1;
            sum1+=rev[src][i].s;
            DFS(a);
        }
    }
}
void DFS1(int src){
    int i,a;
    mark[src]=1;
    last=src;
    for(i=0;i<arr[src].size();i++){
        a=arr[src][i].f;
        if(!mark[a]){
            mark[a]=1;
            sum2+=arr[src][i].s;
            DFS1(a);
        }
    }
}
int main()
{
    int c,i,k=0,n,u,v,w;
    scanf("%d",&c);
    while(c--){
        scanf("%d",&n);
        sum1=sum2=0;
        arr.clear();
        rev.clear();
        memset(mark,0,sizeof mark);
        for(i=0;i<n;i++){
            scanf("%d%d%d",&u,&v,&w);
            if(u==1){
                s1[v]=0;
                s2[v]=w;
            }
            else if(v==1){
                s1[u]=w;
                s2[u]=0;
            }
            arr[u].push_back(make_pair(v,w));
            rev[u].push_back(make_pair(v,0));
            arr[v].push_back(make_pair(u,0));
            rev[v].push_back(make_pair(u,w));
        }
        DFS(1);
        sum1+=s2[last] ;
        memset(mark,0,sizeof mark);
        DFS1(1);
        sum2+=s1[last];
        printf("Case %d: %d\n",++k,min(sum2,sum1));
    }
}
