#include<bits/stdc++.h>
using namespace std;
int M,N;
int c[103][103];
string x,y;
string s[103][103];
void LCS()
{
    int i,j;
    for(i=0;i<N+2;i++){
        c[i][0]=0;
        s[i][0]="";
    }
    for(i=0;i<M+2;i++){
        c[0][i]=0;
        s[0][i]="";
    }
    for(int i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
        {
           // cout<< "OK" << endl;
            if(x[i-1]==y[j-1]){
                c[i][j]=c[i-1][j-1]+1;
                //cout<< c[i][j] << " ";
                s[i][j]=s[i-1][j-1]+ x[i-1];
            }
            else if(c[i][j-1]>c[i-1][j])
            {
                c[i][j]=c[i][j-1];
                s[i][j]=s[i][j-1];
            }
            else if(c[i-1][j]>c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                s[i][j]=s[i-1][j];
            }
            else{
                c[i][j]=c[i-1][j];
                s[i][j]=min(s[i-1][j],s[i][j-1]);
            }
        }
    }
}
int main()
{
    int cn,k=0;
    cin>> cn;
    while(cn--){
        cin>>x>>y;
        N=x.size();
        M=y.size();
        LCS();
        if(c[N][M]==0)cout<< "Case "<<++k << ": :(\n";
        else
        cout << "Case " << ++k << ": " << s[N][M] <<endl;
    }
}
