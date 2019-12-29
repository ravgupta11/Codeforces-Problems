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
int dp[6][INF];
int n;

void init(){
	FOR(i, 0, 6) FOR(j, 0, INF) dp[i][j] = -1;
}

int DP(int i, int X){
	if((i == 6 && X > 0)|| X < 0) return INF;
	if(X == 0) return 0;
	if(dp[i][X] != -1) return dp[i][X];

	int with = min(DP(i, X - coins[i]) + 1, DP(i+1, X - coins[i]) + 1);
	int without = DP(i + 1, X);
	dp[i][X] = min(with, without);
	return dp[i][X];
}

int main(){
	coins.pb(1); coins.pb(2); coins.pb(5); coins.pb(10); coins.pb(20); coins.pb(100);
	ri(n);
	init();
	int ans = DP(0, n);
	printf("%d\n",ans);
	return 0;
}
