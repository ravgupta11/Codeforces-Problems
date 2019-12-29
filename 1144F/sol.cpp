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
int n, m;
 
pair<int, int> E[INF]; 
vi G[INF];
bool vis[INF];
int col[INF];
bool chk = false;
int ori[INF];
void init(){
    FOR(i, 0, n){
        col[i] =-1;  vis[i] = 0;
     }
}
 
int edge(int j, int u){
	if(u == E[j].x) return E[j].y;
	return E[j].x;
}
 
void dfs(int u, int p){
    vis[u] = 1;
    col[u] = 1 - p;
    for(int v:G[u]){
    	int o = v;
    	v = edge(v, u);
    	if(col[u]){
        	if(make_pair(v, u) == E[o]) ori[o] = 1;
        	else ori[o] =0;
        }
        else{
        	if(make_pair(u, v) == E[o]) ori[o] = 1;
        	else ori[o] =0;
        }
        if(vis[v]) continue;
        dfs(v, col[u]);
    }
}
 
 
 
int main(){
	ri(n); ri(m);
	FOR(i, 0 , m){
		int u, v;
		ri(u); ri(v);u--; v--;
		E[i] = {u, v};
		G[u].pb(i); G[v].pb(i);
	}
	init();
	FOR(i, 0, n){
		if(vis[i]) continue;
		dfs(i,1);
	}
	FOR(i, 0, m) if(col[E[i].x] == col[E[i].y]) chk = true;
	if(chk) {
		printf("NO");
		return 0;
	}
	printf("YES\n");
	FOR(i, 0, m) printf("%d", ori[i]);
	return 0;
}