#include <bits/stdc++.h>
#define ll long long int
#define pb push_back

#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FORR(i, a, b) for(ll i = a; i>b; i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;
const int MAXN = 1e6+8;

ll horner(ll a[], ll n, ll x){
    if(n == 0) return a[0];
    return horner(a, n-1, x)*x + a[n];
}

ll A[MAXN], B[MAXN];

int main(){
    string s1, s2;
    while(getline(cin, s1) && !cin.eof()){
        stringstream ss, sss;
        ss<<s1;
        int n =0;
        while(ss>> A[n]) n++;
        getline(cin, s2);
        sss<<s2;
        int m =0;
        while(sss>>B[m]) m++;
        FOR(i, 0, m){
            if(i) printf(" ");
            ll ans = horner(A, n-1, B[i]);
            printf("%lld", ans);
        }
        printf("\n");
    }
    return 0;
}