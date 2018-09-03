#include<bits/stdc++.h>
using namespace std;

int MyTeam[55], OpposingTeam[55];

int main()
{
   // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int c, k=0, n, i, j, r, cnt;
    scanf("%d",&c);
    while(c--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&MyTeam[i]);
        }
        for(i=0;i<n;i++){
            scanf("%d",&OpposingTeam[i]);
        }

        sort(MyTeam, MyTeam+n);
        sort(OpposingTeam, OpposingTeam+n);

        r=cnt=0;
        for(i=0;i<n;i++){
            r=-1;
            for(j=0;j<n;j++){
                if(MyTeam[i]>OpposingTeam[j] ){
                   //cout << i << " " << j << endl;
                    r=j;
                }

            }
            if(r!=-1){
                cnt+=2;
               // cout << i << " "<< r << " 1 " << OpposingTeam[r]<< endl;
                OpposingTeam[r]=1000000;
                MyTeam[i]=-10000;
            }
        }
        for(i=0;i<n;i++){
            r=-1;
            for(j=0;j<n;j++){
                if(MyTeam[i]==OpposingTeam[j] ){
                   // cout << i << " " << j << endl;
                    r=j;
                }

            }
            if(r!=-1){
                cnt++;
                MyTeam[i]=-10000;
              //  cout<<i<< "  " << r <<" 2 " << OpposingTeam[r]<< endl;
                OpposingTeam[r]=1000000;
            }
        }

        printf("Case %d: %d\n",++k, cnt);
    }
}
