#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define FOR(i, a, b) for(int i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a;i>b; i=i-1)
#define ri(x) scanf("%d", &x);
#define rl(x) scanf("%lld", &x)
using namespace std;
 
typedef long long ll;
typedef long double dbl;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<char> vc;
const int INF = 2e6;
const ll LINF = 8e18;
const int MOD = 1e9 + 7;
const dbl EPS = 1e-9;
 
int n;
vi G[INF];
int p[INF];
int col[INF];
bool vis[INF];
 
void init(){
    FOR(i, 0, n){
        vis[i] =0; G[i].clear();
    }
}
vi del;
 
void dfs(int u){
    vis[u] =1;
    bool chk = col[u];
    for(int v:G[u]){
        if(p[u]==v|| vis[v]) continue;
        if(col[v] == 0) chk = 0;
        dfs(v);
    }
    if(chk){
    	del.pb(u);
    }
}
 
int main(){
	ri(n); int root;
	FOR(i, 0, n){
		ri(p[i]); ri(col[i]); p[i]--;
	}
	init();
	FOR(i, 0, n){
		if(p[i] != -2){
			G[i].pb(p[i]);
			G[p[i]].pb(i);
		}
		else root = i;
	}
	dfs(root);
	if(del.size() == 0){
		printf("-1");
		return 0;
	}
	sort(del.begin(), del.end());
	for(int X: del)
		printf("%d ", X+1);
	return 0;
}