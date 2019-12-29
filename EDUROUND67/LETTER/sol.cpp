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
int n, m;
vector< pair<char, int > > s;
string str;

int binary(char key){
	int lo = 0, hi = n;
	while(lo < hi - 1){
		int mi = lo + (hi - lo)/2;
		if(s[mi].x >= key) hi = mi;
		else lo = mi;
	}
	FOR(i, lo, hi + 1) 
		if(s[i].x == key){
			int ans = s[i].y;
			s[i].y = s[i + 1].y;
			return ans;
		}
	return -1;
}

int solve(string & t){
	int MAX = -1;
	for(char c: t){
		int in = binary(c);
		MAX = max(MAX, in);
	}
	return MAX + 1;
}
int main(){
	ri(n);
	cin>>str;
	int i =0;
	for(char c: str){
		s.pb({c, i});
		i++;
	}
	sort(all(s));
	ri(m);
	string t;
	FOR(it, 0, m){
		cin >> t;
		printf("%d\n", solve(t));
	}
	return 0;
}