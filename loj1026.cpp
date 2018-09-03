#include<bits/stdc++.h>
using namespace std;
int Time = 0;
int low[10005], discovery[10005], parent[10005];
bool mark[10005];
vector<int> graph[10005];
vector < pair <int, int> > ab;
void ArticulationBridges(int node){
    mark[node] = true;
    discovery[node] = low[node] = ++Time;
    int len = graph[node].size(), temp,a,b;
    for(int i=0;i<len;i++){
        temp = graph[node][i];
        if(temp==parent[node])continue;
        parent[temp] =  node;
        if(mark[temp]){
            low[node] = min (low[node], discovery[temp]);
        }
        else{
            ArticulationBridges(temp);
            low[node] = min(low[node], low[temp]);
            if(discovery[node] < low[temp]){
                a=node;b=temp;
                if(a>b)swap(a,b);
                ab.push_back(make_pair(a,b));
            }
        }
    }
}
void DustClear(int n){
    for(int i=0;i<=n;i++){
        graph[i].clear();
        mark[i]=0;
        parent[i]=-1;
    }
    ab.clear();
}
bool compare(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first)return a.second<b.second;
    return a.first<b.first;
}
int main()
{
    int c,k=0,i,x,m,n,r,j,nodes;
    string str;
    scanf("%d",&c);
    while(c--){
        scanf("%d",&nodes);
        DustClear(nodes);
        Time=0;
        for(j=0;j<nodes;j++){
           scanf("%d (%d)", &n , &r);
           for(i=0;i<r;i++){
            cin>> m;
            graph[m].push_back(n);
           }
        }
        for(i=0; i<nodes; i++){
            if(!mark[i]){
                ArticulationBridges(i);
            }
        }
        sort(ab.begin(), ab.end(), compare);
        printf("Case %d:\n%d critical links\n",++k, ab.size());
        for(i=0;i<ab.size();i++)printf("%d - %d\n", ab[i].first, ab[i].second);
    }

}
