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
 
 
int main(){
	vi a;
	int n; ri(n);
	FOR(i, 0, n){
		int X;
		ri(X);
		X--;
		a.pb(X);
	}
	int cnt = 1;
	int MAX = a[0];
	FOR(i, 1, n){
		if(i>MAX) {
			cnt++;
		}
		MAX = max(a[i], MAX);
	}
	
	printf("%d", cnt);
	return 0;
}