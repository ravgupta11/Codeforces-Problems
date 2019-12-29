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
vector<char> sv, tv;
int ft[27], fs[27];

void clear(){
	FOR(i, 0, 27) ft[i] = fs[i] = 0;
	sv.clear();
	tv.clear();
}



bool check(string &a, string &b){
	int ln = sz(a), m = sz(b);
	int i =0, j =0, lasti = a[0], lastj = b[0];
	while(i < ln){
		if(a[i] != lasti){
			while(j < m && b[j] == lastj) j++;
			if(j == m || a[i] != b[j]) return false; 
		}
		else{
			if(j == m || a[i] != b[j]) return false;
		}
		lasti = a[i];
		lastj = b[j];
		i++;
		j++;
	}
	while(j < m && b[j] == lastj) j++;
	if(j != m) return false;
	return true;
}

void solve(string & s, string & t){
	clear();
	if(check(s, t)) printf("YES\n");
	else printf("NO\n");
}

int main(){
	ri(n);
	string s, t;
	FOR(i, 0, n){
		cin >> s;
		cin >> t;
		solve(s, t);
	}
	return 0;
}