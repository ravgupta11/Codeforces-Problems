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
 
 
vector<string> S;
 
int main(){
	int n;
	ri(n);
	FOR(i, 0, n){
		string s_i;
		cin>>s_i;
		S.pb(s_i);
	}
	for(string s_i: S){
		sort(s_i.begin(), s_i.end());
		int flag = 1;
		FOR(i, 1, s_i.length()){
			if(s_i[i] != s_i[i-1] +1){
				printf("No\n");
				flag = 0;
				break;
			}
		}
		if(flag == 0) continue;
		printf("Yes\n");
	}
	return 0;
}