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
ll sum(vi &c){
	ll sm = 0;
	for(int a_i: c) sm += a_i;
	return sm;
}
ll f(vi a, vi b){
	int n = (int) a.size(), m = (int) b.size();
	int i = n-1, j = m-1;
	while(i > -1 && j> -1){
		a.pop_back();i--;
		b.pop_back(); j--;
	}
	if(i> -1) {
		a.pop_back();
		return sum(a);
	}
	return sum(b);
}

vi even, odd, a;
int cnt_e = 0, cnt_o=0;
int n;
int main(){
	ri(n);
	FOR(i, 0, n){
		int X;
		ri(X);
		a.pb(X);
		if(X%2==0){
			even.pb(X);
			cnt_e++;
		}
		else{
			odd.pb(X);
			cnt_o++;
		}
	}
	if(abs(cnt_o - cnt_e) < 2){
		printf("0");
		return 0;
	}
	sort(even.begin(), even.end());
	sort(odd.begin(), odd.end());
	ll ans = min(f(odd, even), f(even, odd));
	printf("%lld", ans);
	return 0;
}