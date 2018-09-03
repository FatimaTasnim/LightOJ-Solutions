#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,c,q,k=1;
    string str;
    deque<int> DQ;
    scanf("%d",&c);
    while(c--){
            DQ.clear();
            printf("Case %d:\n",k++);
        scanf("%d%d",&n,&m);
        getchar();
        while(m--){
            cin>>str;
            if(str=="popRight"){
                if(DQ.size()<1)printf("The queue is empty\n");
                else {
                printf("Popped from right: %d\n",DQ.back());
                DQ.pop_back();
                }
            }
            else if(str=="popLeft"){
                if(DQ.size()<1)printf("The queue is empty\n");
                else {
                    printf("Popped from left: %d\n",DQ.front());
                        DQ.pop_front();
                }
            }
            else if(str[4]=='R'){
                    scanf("%d",&q);
                if(DQ.size()==n){
                    printf("The queue is full\n");
                }
                else {
                    DQ.push_back(q);
                    printf("Pushed in right: %d\n",q);
                }
            }
            else{
                scanf("%d",&q);
                if(DQ.size()==n){
                    printf("The queue is full\n");
                }
                    else{
                        DQ.push_front(q);
                        printf("Pushed in left: %d\n",q);
                    }
            }
        }
    }
}
