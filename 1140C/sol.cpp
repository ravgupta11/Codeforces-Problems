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

vector<pair<ll,ll> > songs; int n, k;

int main(){
	ri(n); ri(k);
	FOR(i, 0, n){
		ll ti, bi;
		rl(ti); rl(bi);
		songs.pb({bi, ti});
	}
	ll sum  =0;
	ll MAX = -1;
	priority_queue<ll> play;
	FORR(i, n-1, n-k-1){
		sum += songs[i].y;
		
		play.push(-1*songs[i].y);
		MAX = max(MAX, sum*songs[i].x);
		printf("%lld %lld %lld %lld\n", songs[i].y, songs[i].x, sum, MAX);
	}
	printf("%lld\n",MAX);
	FOR(i, 1, n-k+1){
		ll m = -1*play.top();
		play.pop();
		sum = sum - m + songs[n-k-i].y;
		MAX = max(MAX, sum*songs[n-k-i].x);
		play.push(-1*songs[n-k-i].y);
	}
	printf("%lld", MAX);
	return 0;
}