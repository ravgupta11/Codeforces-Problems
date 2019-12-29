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

int n;
vi a;

int main(){
	ri(n);
	FOR(i, 0, n){
		int b; ri(b);
		a.pb(b);
	}
	int MAX = -1;
	int max_i = INF;
	FOR(i, 0, n){
		int lst = -1;
		int cnt =0;
		FOR(j, 0, n)
		{
			if(j == i) continue;
			if(a[j] < lst) break;
			else {
				lst = a[j];
				cnt++;
			}
		}
		MAX = max(MAX, cnt);
	}
	FOR(i, 0, n){
		int lst = -1;
		int cnt =0;
		FOR(j, 0, n)
		{
			if(j == i) continue;
			if(a[j] < lst) break;
			else {
				lst = a[j];
				cnt++;
			}
			
		}
		if(cnt == MAX) max_i = min(max_i, a[i]);
	}
	printf("%d\n", max_i);
	return 0;
}
