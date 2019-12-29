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
int n, m;
int A[1003];
vector<pair<int, int> > q;
 
void read(){
	ri(n); ri(m);
	FOR(i, 0, m){
		int t, l, r;
		ri(t); ri(l); ri(r);
		l--; r--;
		if(t == 1){
			FOR(i, l , r) A[i] = 1; 
		}
		else q.pb({l, r});
	}
}
 
void solve(){
	read();
	for(auto p: q){
		int l = p.x, r = p.y;
		bool f= 0;
		FOR(i, l, r){
			if(A[i] == 0) f = 1;
		}
		if(f == 0) {
			printf("NO");
			return;
		}
	}
	printf("YES\n");
	int start = 1000000000 - 1;
	FOR(i, 0, n){
		if(A[i] == 1) A[i] = start;
		else A[i] = start--;
		printf("%d ", A[i]);
	}
}
int main(){
	solve();
	return 0;
}