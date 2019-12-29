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
const int INF = 1e3;
const ll LINF = 8e18;
const int MOD = 1e9 + 7;
const dbl EPS = 1e-9;

vi a, b;

int main(){
	srand(time(0));
	FOR(i, 1, INF) b.pb(i);
	random_shuffle(all(b));
	int n = b[0];
	FOR(i, 1, n+1) a.pb(i);
	random_shuffle(all(a));
	printf("%d\n", n);
	FOR(i, 0, n){
		printf("%d ",a[i]);
	}
	return 0;
}
