#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define FOR(i, a, b) for(int i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a;i>b; i—-)
#define ri(x) scanf("%d", &x);
#define rl(x) scanf("%lld", &x)
using namespace std;

typedef long long ll;
typedef long double dbl;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<char> vc;
const int MAXN = 2e6;
const ll LINF = 8e18;
const int MOD = 1e9 + 7;
const dbl EPS = 1e-9;


vi G[MAXN];
int col[MAXN];
int T;

void init(int n){
    FOR(i, 0, n){
        col[i] =0; G[i].clear();
    }
}


void dfs(int u){
	T++;
    col[u] =1;
    for(int v:G[u]){
        if(col[v]==2||col[v]==1) continue;
        if(col[v]==0)
            dfs(v);
    }
    col[u] =2;
}

ll mulmod(ll a, ll b, ll mod)
{
    ll res = 0; 
    a = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = (res + a) % mod;
        a = (a * 2) % mod;
        b /= 2;
    }
    return res % mod;
} 

ll binpow (int a, int n) {
    if (n == 0)
        return 1;
    if (n % 2 == 1) {
        ll b = binpow(a, n - 1);
        return mulmod(b, a, MOD);
    }
    else {
        ll b = binpow (a, n/2);
        return mulmod(b , b, MOD);
    }
}



int main(){
	int n; ri(n); int k;
	ri(k);
	init(n);
	FOR(i, 0, n-1){
		int u, v, d; ri(u); ri(v); ri(d);
		u--; v--;
		if(1-d){
			G[u].pb(v);
			G[v].pb(u);
		}
	}
	ll ans = 0;
	FOR(i, 0, n){
		if(col[i] == 2) continue;
		T = 0;
		dfs(i);
		ans =(ans + binpow(T,k))%MOD;
	}
	ll ans2 = binpow(n, k);
	ans2 = ((ans2 - ans)+MOD)%MOD;
	printf("%lld ", ans2);
	return 0;
}