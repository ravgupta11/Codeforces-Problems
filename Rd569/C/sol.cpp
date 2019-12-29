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
const int INF = 1e6;
const ll LINF = 8e18;
const int MOD = 1e9 + 7;
const dbl EPS = 1e-9;
int a[INF], pre[INF];
int MAX, max_i, n, q;
vi b;
void cal(){
	MAX = a[0], max_i = 0;
	FOR(i, 0, n){
		if( a[i] > MAX ){
			MAX = a[i];
			max_i = i;
		}
		pre[i] = max_i;
	}
}

void preprocess(){
	cal();
	FOR(i, max_i + 1, n) b.pb(a[i]);
	int i = 0, j = 1;
	while(a[i] != MAX){
		if(a[i] > a[j]){
		 b.pb(a[j]);
		 j++;
		}
		else {
			b.pb(a[i]);
			i = j;
			j++;
		}
	}
}

int main(){
	ri(n); ri(q);
	FOR(i, 0, n) ri(a[i]);
	preprocess();
	FOR(i, 0, q){
		ll q_i;
		rl(q_i);
		q_i--;
		if(q_i < max_i )
		{
			printf("%d %d\n", a[pre[q_i]], a[q_i + 1]);
		}
		else
		{
			printf("%d %d\n",MAX, b[(q_i - max_i) % (n - 1)]);
		}
	}
	return 0;
}