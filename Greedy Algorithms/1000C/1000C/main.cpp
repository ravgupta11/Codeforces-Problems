#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <utility>
#include <map>
#include <queue>
#define ll long long int
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i,a,b) for(int i = a;i>b;i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;
const int MAXN = 2e5+3;
const ll INF = 1e9+9;
struct p{
    ll x1; ll x2; ll k;
};

map<ll, struct p > mp;

bool by_x1(struct p a1, struct p a2){
    return a1.x1 < a2.x1;
}

bool by_x2(struct p a1, struct p a2){
    return a1.x2 < a2.x2;
}
bool by_k(struct p a1, struct p a2){
    return a1.k < a2.k;
}

vector< pair<ll,ll> > pairs;
int N;
ll s[MAXN];


int main() {
    ri(N);
    FOR(i, 0, N){
        ll u,v;
        rl(u); rl(v);
        pairs.pb({u,1});
        pairs.pb({v+1,-1});
    }
    sort(pairs.begin(), pairs.end());
    ll cnt = 0;
    FOR(i, 0, 2*N -1){
        cnt += pairs[i].se;
        s[cnt] += pairs[i+1].fi - pairs[i].fi;
    }
    FOR(i, 1 , N+1){
        printf("%lld ", s[i]);
    }
    return 0;
}
