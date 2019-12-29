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

#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FORR(i, a, b) for(ll i = a; i>b; i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;
const int MAXN = 1e6+1;

ll gcd(ll a, ll b, ll &x, ll &y){
    if(b==0){
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll ans= gcd(b, a%b, x1, y1);
    y = x1 - (a/b)*y1;
    x = y1;
    return ans;
}

vector<pair<ll,ll> > X;
int main(){
    ll a, b, c;
    rl(a); rl(b); rl(c);
    ll x, y;
    ll g = gcd(max(a,b), min(a,b), x, y);
    if(max(a,b)==b){
        ll t = y;
        y = x;
        x = t;
    }
    if(c%g == 0){
        ll k = c/g;
        x = x*k; y = y*k;
        if(a==b && (a*(k/2) + b*(k/2) == c))
            X.pb({k/2, k/2});
        ll li = (x-1)/b, lu = abs(y)/a +1;
        FOR(k, lu, li+1){
            ll x1 = x - k*b;
            ll y1 = y + k*a;
            if(x1>0 && y1>0) X.pb({x1,y1});
        }
        printf("%ld\n", X.size());
        sort(X.begin(), X.end());
        FOR(i, 0, X.size())
            printf("%lld %lld\n", X[i].first, X[i].second);
    }
    else
        printf("0");
}