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

int main(){
	int a, b, c, d;
	ri(a); ri(b); ri(c); ri(d);
	int l, m, r;
	l = min(min(a, b), c);
	r = max(max(a, b), c);
	m = (a == l)? ((b == r) ? c : b) : ((a == r) ? ((b == l) ? c : b) : a);
	int ans = max(d - m + l, 0) + max(d - r + m, 0);
	printf("%d", ans);
	return 0;
}