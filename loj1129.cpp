#include<bits/stdc++.h>
using namespace std;
struct node{
    node *next[11];
    int flag;
    node(){
        for(int i=0;i<11;i++)next[i]=NULL;
        flag=0;
    }
}*root;
void Insert(string str){
    node *curr= root;
    int id;
    for(int i=0;str[i];i++){
        id=str[i]-'0';
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
    int id;
    for(int i=0;str[i];i++){
        id= str[i]-'0';
        if(curr->next[id]==NULL)return 0;
    curr=curr->next[id];
    }
    return curr->flag;
}
void Delete(node *curr){
    for(int i=0;i<11;i++){
        if(curr->next[i])Delete(curr->next[i]);
    }
    delete(curr);
}
int main()
{
    int n,q,i,c,k=0,flag=1;
    string str[10002];
    scanf("%d",&c);
    while(c--){
    flag=1;
    scanf("%d",&n);
    root= new node();
    for(i=0;i<n;i++){
        cin>> str[i];
        Insert(str[i]);
    }
    for(i=0;i<n;i++){
        if(Search(str[i])>1){flag=-1;break;}
    }
    /*if(flag==1)cout << "Case " << ++k << ": YES"<< endl;
    else cout << "Case " << ++k << ": NO" << endl;*/
    if(flag==1)printf("Case %d: YES\n",++k);
    else printf("Case %d: NO\n",++k);
    Delete(root);
    }
}

