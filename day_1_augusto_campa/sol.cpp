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

vector<string> mp;

int N, K, T;ll V;
 
void read(){
	mp.clear();
	ri(N); ri(K); rl(V);
	FOR(i, 0, N){
		string s;
		cin>>s;
		mp.pb(s);
	}
}
string solve(){
	string s = "";
	vector<int> a;
	FOR(i, 0, K){
		int in = ((V-1)*K + i)%N;
		a.pb(in);
	}
	sort(all(a));
	for(int i = 0;i < K; i++){
		s += mp[a[i]];
		if(i != K - 1) s += " "; 
	}
	return s;
}
int main(){
	ri(T);
	FOR(it, 1, T+1){
		read();
		printf("Case #%d: %s\n", it, solve().c_str());
	}
	return 0;
}