#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define FOR(i, a, b) for(int i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a;i>b; i=i-1)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define print(x) for(auto i: x) cout<<i<<" "
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
int n, k;
int lt[2002], rt[2002], par[2002], p[2002], col[2002];


vi pre, post, roots;

void read(){
	ri(n); ri(k);
	FOR(i, 0, 2002) lt[i] = rt[i] = -1;
	FOR(i, 0, n){
		int a, b;
		ri(a); ri(b);

		if(a) lt[i] = a - 1;
		if(b) rt[i] = b - 1;
	}
}

int find(int u){
	if (par[u] == u) return u;
	return par[u] = find(par[u]);
}

void join(int a, int b){
	a = find(a), b = find(b);
	par[a] = b;
	find(a);
}
void preorder(int node){
	if(node == -1) return ;

	pre.pb(node);
	preorder(lt[node]);
	preorder(rt[node]);
}

void postorder(int node){
	if(node == -1) return ;
	
	postorder(lt[node]);
	postorder(rt[node]);
	post.pb(node);
}

string solve(){
	pre.clear(); post.clear(); roots.clear();
	preorder(0);
	postorder(0);
	
	FOR(i, 0, 2002) par[i] = i;

	FOR(i, 0, n){
	 	join(pre[i], post[i]);
	}
	
	FOR(i, 0, n)
		if(par[i] == i) roots.pb(i);
	//print(roots);
	if(roots.size() < k) return "Impossible";

	FOR(i, 0, sz(roots)) col[roots[i]] = i % k;
	FOR(i, 0, n) col[i] = col[find(i)];
	int dif =  col[0] - 0;
	FOR(i, 0, n) col[i] = (col[i] - dif + k)%k;

	
	string ans = "";
	FOR(i, 0, n)
		ans += to_string(col[i] + 1) + " ";
	return ans;
}

int main(){
	int T;
	ri(T);
	FOR(it, 1, T+1){
		read();
		printf("Case #%d: %s\n", it, solve().c_str());
	}
	return 0;
}