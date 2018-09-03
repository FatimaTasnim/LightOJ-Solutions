#include<bits/stdc++.h>
#define M 10000
using namespace std;

using namespace std;
int mark[M+3];



string multiply( string a, long long b ){
    int carry = 0;
    for( int i = 0; i < a.size(); i++ ){
        carry += (a[i] - 48) * b;
        a[i] =  carry % 10 + 48 ;
        carry /= 10;
    }
    while( carry ){
        a += ( carry % 10 + 48 );
        carry /= 10;
    }
    return a;
}

vector <int> prime;
void sieve(){
    prime.push_back(2);

    for (int i = 3; i * i <= M; i+=2){
        if(mark[i] == 0){
            for (int j = i * i; j <= M; j += 2 * i){
                mark[j] = 1;
            }
        }
    }

    for (int i = 3; i <= M; i += 2){
        if(mark[i] == 0 )
            prime.push_back(i);
    }
}

long long fact[M+3];
int main()
{
    sieve();
    int c,n, k=0;
    long long x,fac;
    string lcm;

    scanf("%d", &c);
    while(c--){
        memset(fact, 0, sizeof fact);
        scanf("%d", &n);
        lcm = "1";
        for(int j = 0; j < n; j++){
            scanf("%lld", &x);
            for (int i = 0; i < prime.size() and prime[i] * prime[i] <= x ; i++){
                fac = prime[i];
                while(x % prime[i] == 0){
                    fac = fac * prime[i];
                    x = x / prime[i];
                }
                fac = fac / prime[i];
                fact[i] = max(fact[i], fac);
            }

            int p;
            if(x == 2 or ((x % 2) and mark[x] == 0)){
                p = lower_bound(prime.begin(), prime.end(),x) - prime.begin();
                fact[p] = max(fact[p], x);
            }
        }
        for (int i = 0; i < prime.size(); i++){
            if(fact[i])
                lcm = multiply(lcm, fact[i]);
        }

        char ans[1000000];
        string s;
        s = lcm;

        for (int i = 0, j = s.size() - 1; i < s.size(); i++, j--)
            ans[i] = s[j];
        ans[s.size()] = '\0';

        printf("Case %d: %s\n", ++k, ans);
    }

}
