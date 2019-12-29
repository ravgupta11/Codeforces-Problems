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
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a; i>b; i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;
const int MAXN = 2e5+5;

vector<ll> powers;

ll root(ll x) {
    ll l = 0, r = 1e9 + 1;
    while (l <= r ) {
        ll m = (l + r) / 2;
        if (m * m == x) return m;
        else if( m * m < x) l = m + 1;
        else r = m - 1;
    }
    if(l*l>x) l--;
    return l;
}

void init(){
    ll U = 1e18;
    vector<ll> p = {1};
    for(ll i = 2;i<=1e6;i++)
        for(ll j = i*i*i;j<=U;j*=i) {
            p.pb(j);
            if(j > U/i) break;
        }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    for(ll &u: p){
        ll x1 = root(u);
        if(x1*x1==u) continue;
        powers.pb(u);
    }
}


int main(){
    int q;
    init();
    ri(q);
    FOR(i, 0, q){
        ll ans = 0;
        ll l, r;
        rl(l); rl(r);
        ans += upper_bound(powers.begin(), powers.end(), r) - lower_bound(powers.begin(), powers.end(), l);
        ans += root(r) - root(l-1);
        printf("%lld\n", ans);
    }
    return 0;
}



