#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <string.h>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#define ll long long int
#define pb push_back
#define x first
#define y second
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FORR(i, a, b) for(ll i = a; i>b; i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;

const ll MAXN = 1e6+1;

ll root(ll x) {
    ll l = 0, r = 1e6 + 1;
    while (l <= r ) {
        ll m = (l + r) / 2;
        if (m * m == x) return m;
        else if( m * m < x) l = m + 1;
        else r = m - 1;
    }
    if(l*l>x) l--;
    return l;
}

bool p[MAXN];

void sieve(){
    FOR(i, 2, MAXN) p[i] = true;
    for(ll i = 2; i<=MAXN;i++){
        if(p[i]){
            for(ll j = i*i;j<=MAXN;j+=i) p[j] = false;
        }
    }
}
vector<ll> A, B;
void solve(){
    int n;
    ri(n);
    FOR(i, 0, n){
        ll u;
        rl(u);
        A.pb(u);
    }
    sieve();
    FOR(i, 0, n){
        ll k = root(A[i]);
        if(k*k==A[i] && p[k]) B.pb(1);
        else B.pb(0);
    }

    //int cnt = 0;
    FOR(i, 0, B.size()){
        if(B[i]) printf("YES\n");
        else printf("NO\n");
    }
}

int main(){
    solve();
    return 0;
}