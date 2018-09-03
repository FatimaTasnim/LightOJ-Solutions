#include<bits/stdc++.h>
using namespace std;
int M,N,O;
int c[52][52][52];
string x,y,z;
void LCS()
{
    int i,j,k;
    memset(c,0,sizeof c);
    //cout << M << " " << N << endl;
    for(k=1;k<=O;k++){
    for(j=1;j<=N;j++){
        for(i=1;i<=M;i++){
            if(x[i-1]==y[j-1]&&x[i-1]==z[k-1]){
                c[i][j][k]=c[i-1][j-1][k-1]+1;
            }
            else c[i][j][k]=max(c[i-1][j][k],(max(c[i][j-1][k],c[i][j][k-1])));
        }
    }
    }
}
int main()
{
    int p,k=0;
    scanf("%d",&p);
    //freopen("out.txt","w",stdout);
    while(p--){
        getchar();
        cin>> x>>y>>z;
        M=x.size();N=y.size();O=z.size();
        LCS();
        printf("Case %d: %d\n",++k,c[M][N][O]);
    }
}
