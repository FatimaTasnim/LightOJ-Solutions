#include<bits/stdc++.h>
using namespace std;
int id;
int mark[1002],check[1002],reachable_from[1002],source[102];
map< int, vector<int> > graph;
queue<int> Q;
void BFS(int src)
{
    int i,tsrc;
    Q.push(src);
    while(!Q.empty())
    {
        tsrc=Q.front();
        Q.pop();
        for(i=0; i<graph[tsrc].size(); i++)
        {
            if(mark[graph[tsrc][i]]!=id)
            {
                mark[graph[tsrc][i]]=id;
                reachable_from[graph[tsrc][i]]++;
                Q.push(graph[tsrc][i]);
            }
        }
    }
}
int main()
{
    int c,r,k=0,n,m,i,cnt,ans,u,v;
    scanf("%d",&c);
    while(c--){
        memset(mark,0,sizeof mark);
        memset(check,0,sizeof check);
        memset(reachable_from,0,sizeof reachable_from);
        graph.clear();
        cnt=ans=0;
        scanf("%d%d%d",&r,&n,&m);
        for(i=0;i<r;i++){
            scanf("%d",&source[i]);
        }
        for(i=0;i<m;i++){
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
        }
        for(i=0;i<r;i++){
            id=source[i];
            if(!check[id]){
            check[id]=1;
            cnt++;
            mark[source[i]]=id;
            reachable_from[source[i]]++;
            BFS(source[i]);
            }
        }
        //cout << cnt << endl;
        for(i=1;i<=n;i++){
           // cout << reachable_from[i] << endl;
            if(reachable_from[i]==cnt)ans++;
        }
        printf("Case %d: %d\n",++k,ans);
    }
}
