#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define FOR(i, a, b) for(int i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a;i>b; i = i - 1)
#define ri(x) scanf("%d", &x);
#define rl(x) scanf("%lld", &x)
using namespace std;
 
typedef long long ll;
typedef long double dbl;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<char> vc;
const int INF = 2e5+8;
const ll LINF = 8e18;
const int MOD = 1e9 + 7;
const dbl EPS = 1e-9;
 
ll a[INF];
int main(){
	int n; ri(n);
	FOR(i, 0, n) rl(a[i]);
	ll ans = a[n-1];
	ll last = ans;
	FORR(i, n-2, -1) {
		 last = max(min(a[i], last-1), 0LL);
		 ans += last;
	}
	printf("%lld ", ans);
	return 0;
}