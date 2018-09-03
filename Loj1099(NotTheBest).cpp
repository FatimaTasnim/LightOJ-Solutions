#include<bits/stdc++.h>
#define M 5000
using namespace std;
struct node{
        int n;
        int c;
        node(){}
        node(int n,int c){
                this->n=n;
                this->c=c;
        }
        bool operator < (const node &m) const{return c>m.c;}
};
bool mark[M+3];
int cost1[M+3], cost2[M+3],cost3[M+3],cost4[M+3];
vector <node> graph[M+3];
int Dijkstra(int src,int des,int n){
        node temp, tsrc;
        priority_queue<node>Q;
         for(int i = 1; i <= n; i++){
                        cost3[i] = INT_MAX;
                        for(int j = 0; j < graph[i].size(); j++)
                                cost3[i] = min(cost3[i], 2*graph[i][j].c);
         }
        Q.push(node(src,0));
        cost1[src]=0;
        while(!Q.empty()){
                tsrc= Q.top();
                Q.pop();
                if(mark[tsrc.n]){
                        if(cost1[tsrc.n]< tsrc.c &&(cost2[tsrc.n]<0 || cost2[tsrc.n]>=tsrc.c))
                                cost2[tsrc.n]= tsrc.c;
                        else
                                continue;
                }
                else mark[tsrc.n]=1;
                for(int i=0;i<graph[tsrc.n].size();i++){
                        temp=graph[tsrc.n][i];
                        if(cost1[temp.n]==-1 || cost1[temp.n]>tsrc.c+temp.c){
                                Q.push(node(temp.n,tsrc.c+temp.c));
                                cost2[temp.n]= cost1[temp.n];
                                cost1[temp.n]= tsrc.c + temp.c;
                        }
                        else if(cost2[temp.n]==-1 || cost2[temp.n]>tsrc.c+temp.c){
                                if(cost1[temp.n]!= tsrc.c +temp.c){
                                        Q.push(node(temp.n,tsrc.c+temp.c));
                                }
                        }
                }
                if(!cost4[tsrc.n]){
			Q.push(node(tsrc.n, cost1[tsrc.n] + cost3[tsrc.n]));
			cost4[tsrc.n] = 1;
		}

        }
        return cost2[des];
}
int main()
{
        int i, j, k=0, w,a,b,c,p,n,m;
	scanf("%d", &c);
	while(c--){
		scanf("%d%d", &n, &m);
		for(i=0;i<=n;i++)graph[i].clear();
		for(i = 0; i < m; i++){
			scanf("%d %d %d", &a, &b, &w);
			graph[a].push_back(node(b, w));
			graph[b].push_back(node(a, w));
		}
		memset(cost1,-1,sizeof cost1);
		memset(cost2,-1,sizeof cost2);
		memset(cost4,0,sizeof cost4);
		memset(mark,0,sizeof mark);
		printf("Case %d: %d\n", ++k, Dijkstra(1, n,n));
	}
}
