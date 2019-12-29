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
multiset<int> S;
set<int> inc, decr;
int main(){
	ri(n);
	FOR(i, 0, n){
		int X;
		ri(X);
		S.insert(X);
		inc.insert(X);
	}
	for(int i: inc){
		auto it = S.lower_bound(i);
		S.erase(it);
	}
	for(int i: S)
		decr.insert(i);
	for(int i: decr){
		auto it = S.lower_bound(i);
		S.erase(it);
	}
	if(S.size() > 0){
		printf("NO");
		return 0;
	}
	printf("YES\n");
	printf("%ld\n", inc.size());
	for(int i: inc) printf("%d ", i);
	printf("\n");
	printf("%ld\n", decr.size());
	for (auto rit=decr.rbegin(); rit != decr.rend(); ++rit)
    	printf("%d ", *rit);
	printf("\n");
	return 0;
}