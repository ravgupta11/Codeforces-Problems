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
	int T;
	ri(T);
	FOR(i, 0, T){
		int n, s, t;
		ri(n); ri(s); ri(t);
		if(s + t == n) printf("%d\n", max(s, t) + 1);
		else{ 
			int l = s + t - n;
			s = s - l;
			t = t - l;
			int a = max(s, t) + 1;
			int b = max(s + t, l) + 1;
			printf("%d\n", min(a, b));
		}
	}
	return 0;
}