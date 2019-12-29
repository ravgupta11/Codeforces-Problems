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
 
ll N, M;
ll mat[1005][1005];
vl row[1005], col[1005];
ll MAX_r[1003], MAX_c[1003];
void condense_row(int it){
	vl b(row[it]);
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	FOR(i, 0, row[it].size())
		row[it][i] = (int) distance(b.begin(), lower_bound(b.begin(), b.end(), row[it][i]))+1;
}
 
void condense_col(int it){
	vl b(col[it]);
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	FOR(i, 0, col[it].size())
		col[it][i] = (int) distance(b.begin(), lower_bound(b.begin(), b.end(), col[it][i]))+1;
}
int main(){
	ri(N); ri(M);
	FOR(i, 0, N) FOR(j, 0, M)
		rl(mat[i][j]);
	FOR(i, 0, N) 
		FOR(j, 0, M)
			row[i].pb(mat[i][j]);
	FOR(j, 0, M)
		FOR(i, 0, N)
			col[j].pb(mat[i][j]);
	FOR(i, 0, N) condense_row(i);
	FOR(j, 0, M) condense_col(j);
	FOR(i, 0, N)
		for(ll a_i: row[i]) MAX_r[i] = max(MAX_r[i], a_i);
	FOR(i, 0, M)
		for(ll a_i: col[i]) MAX_c[i] = max(MAX_c[i], a_i);
	FOR(i, 0, N) FOR(j, 0, M){
		ll a = row[i][j], b = col[j][i];
		ll a_max = MAX_r[i], b_max = MAX_c[j];
		//printf("%lld %lld %lld %lld %lld %lld\n", i,j,a,b,a_max, b_max);
		if(a > b) mat[i][j] = max(a_max, b_max + a-b);
		else mat[i][j] = max(a_max+b-a, b_max) ;
	}
	FOR(i, 0, N){
		 FOR(j, 0, M) printf("%lld ", mat[i][j]);
		printf("\n");
	}
	return 0;
}