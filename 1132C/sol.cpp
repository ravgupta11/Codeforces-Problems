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
 
int arr[INF], d[INF];
int n, k;
vector<pair<int, int> > p;
 
int solve(){
	ri(n); ri(k);
	FOR(i, 0, k){
		int u, v;
		ri(u); ri(v);
		if(v < u) swap(u, v);
		p.pb({u, v});
	}
	
	
	int MAX = -1;
	FOR(it, 0, k){
		FOR(i, 1, n+1) arr[i] = d[i] = 0;
		FOR(i, 0, k){
			if(i == it) continue;
			arr[p[i].x]++;
			arr[p[i].y+1]--;
		}
		FOR(i, 1, n+1) arr[i] = arr[i-1] + arr[i];
		FOR(i, 1, n+1) if(arr[i] == 1) d[i] = 1;
		FOR(i, 1, n+1) d[i]+= d[i-1];
		int MIN = INF;
		FOR(i, 0, k){
			if(i == it) continue;
			MIN = min(d[p[i].y] - d[p[i].x-1], MIN); 
		}
		int c =0;
		FOR(i, 1, n+1) if(arr[i] > 0) c++;
		MAX = max(c-MIN, MAX);
	}
	
	printf("%d", MAX);
	return 0;
}
int main(){
	solve();
	return 0;
}