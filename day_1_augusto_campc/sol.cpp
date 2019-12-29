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
const int INF = 2e3 +1;
const ll LINF = 8e18;
const int MOD = 1e9 + 7;
const dbl EPS = 1e-9;

int pref[INF];
int T;
string A;

void prefix(string &s){
	FOR(i, 0, s.length()) pref[i] = 0;
	FOR(i, 1, s.length()){
		pref[i] = pref[i-1];
		while(pref[i] > 0 && s[i] != s[pref[i]]) 
			pref[i] = pref[pref[i] - 1];
		if(s[pref[i]] == s[i])
			pref[i] = pref[i] + 1;
	}
}

void read(){
	cin>>A;
}

string solve(){
	prefix(A);
	bool f = 1;
	int N = A.length();
	FOR(i, 0, N) 
		if(pref[i] != 0){
			f = 0;
			break;
	}
	if(f) return "Impossible";
	f = 1;
	FOR(i, 1, N){
		if(pref[i] <= pref[i-1] && pref[i-1] != 0){
			f = 0;
			break;
		}
	}
	if(f) return "Impossible";
	string B;
	int j, k;
	FOR(i, 1, N){
		B.pb(A[i - 1]);
		if(pref[i] <= pref[i-1] && pref[i-1] != 0){
			k = pref[i - 1];
			j = i;
			break;
		}
	}
	FOR(i, k, A.length()){
		B.pb(A[i]);
	}
	return B;
}

int main(){
	ri(T);
	FOR(it, 1, T+1){
		read();
		printf("Case #%d: %s\n", it, solve().c_str());
	}
	return 0;
}