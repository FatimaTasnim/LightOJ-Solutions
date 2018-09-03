#include<bits/stdc++.h>
using namespace std;
int M,N;
long long lcss[31][31],ways[31][31];
char X[31],Y[31];
void count_LCSS(){
    for(int i=0;i<=M;i++)ways[i][0]=1;
    for(int j=0;j<=N;j++)ways[0][j]=1;
    for(int i=1; i<=M; i++){
        for(int j=1; j<=N; j++){
            if(X[i-1] == Y[j-1]) lcss[i][j]= lcss[i-1][j-1]+1, ways[i][j]= ways[i-1][j-1];
            else{
                lcss[i][j]= max(lcss[i-1][j], lcss[i][j-1]);
                if(lcss[i][j-1]==lcss[i-1][j])ways[i][j]= ways[i-1][j] + ways[i][j-1];
                else ways[i][j]= min(ways[i][j-1],ways[i-1][j]);
            }
        }
    }
}
int main()
{
    int c,k=0;
    scanf("%d",&c);
    while(c--){
        //cin>> X >> Y;
        scanf("%s%s",X,Y);
        M= strlen(X);
        N= strlen(Y);
        count_LCSS();
        //cerr << lcss[M][N] << " " <<   << " " << << endl;
        printf("Case %d: %lld %lld\n",++k, M+N - lcss[M][N],ways[M][N]);
    }
}
