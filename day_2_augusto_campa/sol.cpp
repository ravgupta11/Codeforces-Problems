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

char mat[3][1003];int N, c[1003];

void read(){
	ri(N);
	FOR(i, 0, 3)
		scanf("%s", mat[i]);
}

bool base(){
	if( N < 2 || N % 2 == 1 || mat[0][0] == '#' || mat[2][N-1] == '#') return 1;
	FOR(i, 0, N)
		if(mat[1][i] == '#') return 1;
	return 0;

}

void cal_c(){
	FOR(i, 0, N) c[i] = -1;
	for(int j = 1; j < N-1; j += 2){
		if((mat[0][j] == '#' || mat[0][j+1] == '#') && (mat[2][j] == '#' || mat[2][j+1] == '#'))
			c[j] = 0;
		else if (mat[0][j] == '.'  && mat[0][j+1] == '.' && mat[2][j] == '.' && mat[2][j+1] == '.')
			c[j] = 2;
		else 
			c[j] = 1;
	}
}

ll solve(){
	if(base()) return 0LL;
	cal_c();
	ll ans = 1;
	for(int i = 1; i < N-1; i += 2)
		ans = (ans * c[i])%MOD;
	return ans;
}

int main(){
	int T;
	ri(T);
	FOR(it, 1, T+1){
		read();
		printf("Case #%d: %lld\n", it, solve());
	}
	return 0;
}