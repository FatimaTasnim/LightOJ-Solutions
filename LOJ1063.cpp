#include<bits/stdc++.h>
#define X 20005
using namespace std;
int Time, ap;
bool mark[X], track[X];
int discovery[X], low[X], parent[X];
vector < int > graph[X];
void ArticulationPoint(int node){
    mark[node] = 1;
    discovery[node] = low[node] = Time++;
    int child = 0, temp, length = graph[node].size();
    for(int i=0; i<length; i++){
        temp = graph[node][i];
        if(!mark[temp]){
            mark[temp] = true;
            child++;
            parent[temp] = node;
            ArticulationPoint(temp);
            low[node] = min(low[node], low[temp]);
            if(parent[node] && discovery[node] <= low[temp] && !track[node]){
                track[node] = true;
                ap++;
            }

        }
        else if(parent[node]!=temp and parent[node]){
                low[node] = min(low[node], discovery[temp]);
        }
    }
    if(!parent[node] and child>=2 and !track[node]){
        track[node] = 1;
        ap++;
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int c, k=0, nodes, edges, a, b;
    scanf("%d",&c);
    while(c--){
        scanf("%d%d",&nodes, &edges);
        memset(track, false, sizeof track);
        memset(mark, false, sizeof mark);
        for(int i=0; i<=nodes+1; i++)graph[i].clear();
        for(int i=0; i< edges; i++){
            scanf("%d%d",&a,&b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        ap=Time=0;
        parent[1]=0;
        ArticulationPoint(1);

        printf("Case %d: %d\n",++k, ap);
    }
}
