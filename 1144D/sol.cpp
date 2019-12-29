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

int n;
vl a;
struct triplet{
	int ti, i, j;
};
vector<struct triplet> s;
int cnt[INF];


int main(){
	ri(n);
	if(n == 1){
		printf("0");
		return 0;
	}
	FOR(i, 0, INF) cnt[i] = 0;
	FOR(i, 0, n){ll X; rl(X); a.pb(X); cnt[X]++;}
	int mx = -1, mx_i = 0;
	FOR(i, 0, n) 
		mx = max(mx, cnt[a[i]]);
	FOR(i, 0, n) if(mx == cnt[a[i]]) mx_i = i;
	FOR(i, mx_i+1, n){
		if(a[i] < a[mx_i]) 
			s.pb({1, i, i-1});
		if(a[i] > a[mx_i])
			s.pb({2, i, i-1});
	}
	FORR(i, mx_i-1, -1){
		if(a[i] < a[mx_i])
			s.pb({1, i, i+1});
		if(a[i] > a[mx_i])
			s.pb({2, i, i+1});
	}
	printf("%ld", s.size());
	for(struct triplet it: s){
		printf("\n");
		printf("%d %d %d", it.ti, it.i+1, it.j+1);
	} 
	return 0;
}