#include<bits/stdc++.h>
using namespace std;
map<char,int>mp;
struct node{
    node *next[6];
    int flag;
    node(){
        for(int i=0;i<6;i++)next[i]=NULL;
        flag=0;
    }
}*root;
void Insert(string str){
    node *curr= root;
    int id;
    for(int i=0;str[i];i++){
        id= mp[str[i]];
        if(curr->next[id]==NULL){
            curr->next[id]=new node();
        }
        curr->flag++;
        curr= curr->next[id];
    }
    curr->flag++;
}
int Search(string str){
    node *curr=root;
    int id,maxima=0;
    for(int i=0;str[i];i++){
        id= mp[str[i]];
        //if(curr->next[id]==NULL)return 0;
        curr=curr->next[id];
        maxima=max(maxima, (curr->flag)*(i+1));
        //cout << curr->flag << " " << (curr->flag)*(i+1)<<endl;

    }
    return maxima;
}
void Delete(node *curr){
    for(int i=0;i<6;i++){
        if(curr->next[i])Delete(curr->next[i]);
    }
    delete(curr);
}
int main()
{
    mp['A']=0;mp['C']=1;mp['G']=2;mp['T']=3;
    int n,q,i,c,k=0,flag=1,maxima;
    string str;
    scanf("%d",&c);
    while(c--){
    flag=1;maxima=0;
    scanf("%d",&n);
    root= new node();
    for(i=0;i<n;i++){
        cin>> str;
        Insert(str);
        maxima=max(maxima,Search(str));
    }
    //cout << "Case " << ++k << ": "<<maxima<< endl;
    printf("Case %d: %d\n",++k,maxima);
    Delete(root);
    }
}
