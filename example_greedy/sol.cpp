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

vi coins;

int n;
int main(){
	ri(n);
	coins.pb(1); coins.pb(2); coins.pb(5); coins.pb(10); coins.pb(20); coins.pb(100);
	sort(all(coins));
	reverse(all(coins));
	int MIN = 0;
	FOR(i, 0, sz(coins)){
		MIN += n / coins[i];
		n = n % coins[i];
	}
	printf("%d\n", MIN);
	return 0;
}