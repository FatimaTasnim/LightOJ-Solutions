#include<bits/stdc++.h>
#define M 10000007
using namespace std;
int arr[10001];
int a, b, c, d, e, f,n;
int fn( int n ) {
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    if(arr[n]==-1)
    return arr[n]=( fn(n-1)%M + fn(n-2)%M + fn(n-3)%M + fn(n-4)%M + fn(n-5)%M + fn(n-6)%M )%M;
    else return arr[n];
}
int main() {
    int  caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
            memset(arr,-1,sizeof arr);
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %d\n", ++caseno, fn(n)%M );
    }
    return 0;
}
