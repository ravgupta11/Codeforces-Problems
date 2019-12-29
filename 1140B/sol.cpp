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
 
vi a ;char str[106];
int main(){
	int t;
	ri(t);
	FOR(it, 0, t){
		a.clear();
		int n; ri(n);
		scanf("%s", str);
		FOR(i, 0, n){
			if(str[i] == '>') a.pb(1);
			if(str[i] == '<') a.pb(0);
		}
		int X = INF, Y = -INF;
		FOR(i, 0, n) if(a[i] == 1){
			X = i;
			break;
		}
		FORR(i, n-1, -1) if(a[i] == 0){
			Y = i;
			break;
		}
		int ans = min(X, n-1-Y);
		printf("%d", ans);
		if(it != t-1) printf("\n");
	}
	return 0;
}