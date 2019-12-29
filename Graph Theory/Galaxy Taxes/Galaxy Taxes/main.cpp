
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

#define ll long long int
#define dbl double long
#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORR(i, a, b) for(int i = a; i > b; i--)
#define ms(arr, val) memset(arr, val, sizeof(arr[0]));
#define ri(x) scanf("%d",&x);
#define rii(x,xx) scanf("%d %d", &x, &xx);

typedef vector<int> vi;
typedef pair<dbl, int> pi;
typedef pair<pi, int> pii;
typedef pair< pair<int, int>, pair<int, int> > piii;

const int MAXN = 1e3 +5;
const ll INF = 1e9+9;
const dbl EPS = 1e-12;

int N,M;
dbl d[MAXN];
vector< int > G[MAXN];
vector < piii > EL;

int other(piii x, int u){
    if(x.fi.fi==u) return x.fi.se;
    return x.fi.fi;
}

dbl dijk(dbl t, int s = 0,int dest = N-1){
    priority_queue<pi > pq;
    pq.push({0,s});
    FOR(i, 0, N) d[i] = INF;
    d[s] = 0;
    while(!pq.empty()){
        int u = pq.top().se; pq.pop();
        for(int i: G[u]){
            int v = other(EL[i], u); dbl w = EL[i].se.fi *t + EL[i].se.se;
            if( d[v] - (d[u] + w) > EPS){
                d[v] = d[u] + w;
                pq.push({-d[v],v});
            }
        }
    }
    return d[dest];
}

dbl ternary(dbl lo, dbl hi){
    while(hi-lo> EPS){
        dbl m1 = lo + (hi - lo)/3;
        dbl m2 = hi - (hi - lo)/3;
        if(dijk(m1)-dijk(m2)>EPS) hi = m2;
        else lo = m1;
    }
    return hi;
}

int main() {
    while(scanf("%d %d", &N, &M) != EOF){
        EL.clear();
        FOR(i,0,N) G[i].clear();
        FOR(i,0,M){
            int u , v, a, b;
            scanf("%d %d", &u, &v);
            scanf("%d %d", &a, &b);
            u--;v--;
            EL.pb({{u, v}, {a, b}});
            G[u].pb(i);
            G[v].pb(i);
        }
        dbl ans = ternary(0,24*60);
        printf("%Lf\n", dijk(ans));
    }
    return 0;
}
