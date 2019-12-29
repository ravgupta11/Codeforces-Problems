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
int prefix[INF];
void calc(string & a){
	prefix[0] = a[0] - '0';
	FOR(i, 1, n) prefix[i] = prefix[i - 1] + (a[i] - '0');
}
int solve(string & a, string & b){
	calc(a);
	int cnt = 0;
	int sm_b = 0;
	FOR(i, 0, m) sm_b += b[i] - '0';

	FOR(i, m - 1, n){
		int sm_a = (prefix[i] - prefix[i - m + 1] + (a[i - m + 1] - '0'));
		//cout<<prefix[i]<<" "<<prefix[i - m + 1]<<endl;
		if((sm_a + sm_b) % 2 == 0) cnt++; 
	}
	return cnt;
}

int main(){
	string a, b;
	cin >> a;
	cin >> b;
	n = a.length();
	m = b.length();
	int ans = solve(a, b);
	cout<< ans;
}