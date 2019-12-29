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

ll gcd(ll a, ll b){
    while(b){
        ll t = a;
        a = b;
        b = b%t;
    }
    return b;
}

bool in(ll a, ll b, ll l,ll r){
    if(a<l||a>r||b<l||b>r) return 0;
    return 1;
}

ll factor(ll x, ll y, ll l, ll r){
    ll n = x*y;
    ll cnt  =0;
    for(ll i = 1; i*i<=n;i++){
        if(n%i==0){
            ll a= i, b = n/i;
            if(!in(a,b,l,r) || gcd(max(a,b),min(a,b)) != x) continue;
            cnt++;
            if(a != b)
                cnt++;
        }
    }
    return cnt;
}

void solve(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    ll x, y, l, r;
    cin>>l>>r>>x>>y;
    ll ans = factor(x, y, l, r);
    printf("%lld", ans);
}

int main(){
    solve();
    return 0;
}