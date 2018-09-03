#include<bits/stdc++.h>
#define M 100000
using namespace std;
int arr[M+2],tree[(M*4)+2];
void Make_tree(int pos,int low,int high)
{
    if(low==high)
    {
        tree[pos]=arr[low];
        return;
    }
    int mid= (low+high)/2;
    Make_tree((pos<<1)+1,low,mid);
    Make_tree((pos<<1)+2,mid+1,high);
    tree[pos] =tree[(pos<<1)+1]+ tree[(pos<<1)+2];
}
void update(int pos,int low,int high,int nlow,int n)
{
    if(low>nlow || high<nlow)
    {
        if(low==nlow && high==nlow)
        {
            tree[pos]+=n;
            return;
        }
        int mid= (low+high)/2;
        update((pos<<1)+1,low,mid,nlow,n);
        update((pos<<1)+2,mid+1,high,nlow,n);
        tree[pos]=tree[(pos<<1)+1]+tree[(pos<<1)+2];
    }
}
int Query(int pos,int low,int high,int nlow,int nhigh)
{
    if(nlow>high || nhigh<low ||low>high)return 0;
    if(nlow>=low && nhigh<=high)return tree[pos];
    int mid= (low+high)/2;
    Query((pos<<1)+1,low,mid,nlow,nhigh);
    Query((pos<<1)+2,mid+1,high,nlow,nhigh);
    return tree[pos]= tree[(pos<<1)+1] + tree[(pos<<1)+2];
}
int main()
{
    int c,k=0,a,b,i,len,p;
    char ch;
    string str;
    scanf("%d",&c);
    while(c--)
    {
        cin>> str;
        len=str.size();
        for(i=0; i<len; i++)
        {
            arr[i]= str[i]-'0';
        }
        printf("Case %d:\n",++k);
        Make_tree(0,0,len-1);
        cout<< "ok";
        scanf("%d",&p);
        while(p--)
        {
            scanf("%c",&ch);
            if(ch=='I')
            {
                scanf("%d%d",&a,&b);
                update(0,0,len-1,a-1,b-1,1);
            }
            else
            {
                scanf("%d",&a);
                printf("%d\n",tree[a]%2);
            }
        }
    }
}
