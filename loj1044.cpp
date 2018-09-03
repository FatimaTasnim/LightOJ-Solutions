#include<bits/stdc++.h>
using namespace std;
int n;
int cuts[1001];
int palin[1001][1001];
string str;
int minPartitioning(){
      for(int i=0;i<n;i++)palin[i][i]=true,cuts[i]=100000;
      int length=1;
      while(length<n){
            for(int i=0;i+length<n;i++){
                  if(str[i+length]==str[i] && (palin[i+1][i+length-1] | length<2))palin[i][i+length]=true;
            }
            length++;
      }

      cuts[0]=0;
      for(int i=1;i<n;i++){
            if(palin[0][i]){
                  cuts[i]=0;
                  continue;
            }
            //cout << "position " << i << endl;
            for(int j=0;j<i;j++){
                 // cout << j << " ";
                  if(palin[j+1][i] ){
                              //cout <<cuts[j] << endl;
                              cuts[i]=min(cuts[j]+1,cuts[i]);
                  }
                  //else cout << "no way"<< endl;
            }
      }
      return cuts[n-1];
}
int main()
{
      int c,k=0;
      //freopen("in.txt","r",stdin);
      //freopen("out.txt","w",stdout);
      scanf("%d",&c);
      while(c--){
            cin>> str;
            n=str.size();
            memset(palin,0,sizeof palin);
            printf("Case %d: %d\n",++k,minPartitioning()+1);
      }
}
