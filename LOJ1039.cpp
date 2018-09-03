#include<bits/stdc++.h>
using namespace std;
struct pair_{
    string str;
    int cnt = 0;
};
queue<pair_> Q;
int bfs(string src, string des){
    pair_ pp ;
    Q.clear();
    marK.clear();
    marK[src] = 1;
    pp.str = src, pp.cnt =0;
    Q.push(pp);
    while(!Q.empty()){
        pp = Q.front();
        Q.pop();
        if(mark[pp.src])continue;
        if(pp.src==dis)return pp.cnt;
        for(i=0;i<3;i++){
            st = ss.str;
        }
    }
}
int main()
{
    int c;
    scanf("%d", &c);
    while(c--){
        cin >> seq1 >> seq2;
        scanf("%d", &n);
        while(n--){
            mark.clear();
            cin >> str1 >> str2 >> str3;
            for(i=0; str1[i]; i++){
                temp = "";
                temp+= str1[i];
                for(j=0; str2[j]; j++){
                    temp+= str2[j];
                    for(k=0; str3[k]; k++){
                        temp += str3[k];
                        mark[temp] = 1;
                        temp.erase(temp.end()-1, temp.end());
                    }temp.erase(temp.end()-1, temp.end());
                }temp.erase(temp.end()-1, temp.end());
            }
            printf("Case %d: %d\n", bfs(seq1, seq2)));
        }
    }
}
