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
const int INF = 5002;
const ll LINF = 8e9;
const int MOD = 1e9 + 7;
const dbl EPS = 1e-9;
int N, M, K, S[INF], D[INF];
vector<pair<int, int> > G[INF];
int mat[INF][INF];

ll dist[INF][INF]; bool rel[INF];
ll pick(int i, bool full);
ll drop(int i, bool empty);
ll dp1[INF][2], dp2[INF][2];

void init(){
	FOR(i, 0, K) FOR(j, 0, 2) 
		dp1[i][j] = dp2[i][j] = -1;
}

ll pick(int i, bool full){	
	if(i >= K) return INF;
	if(i == K - 1){
		if(full) return drop(i - 1, 0) + dist[S[i]][D[i - 1]];
		else return drop(i, 1) + dist[S[i]][D[i]];
	}

	if(dp1[i][full] != -1) return dp1[i][full];

	if(full)
		dp1[i][full] = drop(i - 1, 0) + dist[S[i]][D[i - 1]];
	else
		dp1[i][full] = min(drop(i, 1) + dist[S[i]][D[i]], pick(i + 1, 1) + dist[S[i]][S[i + 1]]);
	
	return dp1[i][full];
}

ll drop(int i, bool empty){
	if(i == K-1) return 0;
	if(dp2[i][empty] != -1) return dp2[i][empty];
	
	if(empty)
		dp2[i][empty] = pick(i + 1, 0) + dist[D[i]][S[i + 1]];
	else
		dp2[i][empty] = min( drop(i + 1, 1) + dist[D[i]][D[i + 1]], pick(i + 2, 1) + dist[D[i]][S[i + 2]]);
	
	return dp2[i][empty];	
}

void dijk(){
	priority_queue<pair<ll, int> > pq;
	FOR(src, 0, N){
		FOR(i, 0, N) dist[src][i] = LINF;
		FOR(i, 0, N) rel[i] = 0;

		dist[src][src] = 0;
		while(!pq.empty()) pq.pop();
		pq.push({0, src});
		while(!pq.empty()){
			auto p = pq.top(); pq.pop();
			int fro = p.y; ll d_fro = -1*p.x;
			if(rel[fro]) continue;
			rel[fro] = 1;
			for(auto e: G[fro]){
				int to = e.y; ll w = e.x;
				if(dist[src][to] > d_fro + w){
					dist[src][to] = d_fro + w;
					pq.push({-dist[src][to], to});
				}
			}
		}
	}
}

void read(){
	ri(N); ri(M); ri(K);

	FOR(i, 0, N) FOR(j, 0, N) mat[i][j] = 10000;
	FOR(i, 0, N) G[i].clear();

	FOR(i, 0, M){
		int a, b, c;
		ri(a); ri(b); ri(c);
		--a; --b;
		mat[a][b] = min(mat[a][b], c);
		mat[b][a] = min(mat[b][a], c);
	}

	FOR(i, 0, N) FOR(j, i + 1, N) if(mat[i][j] != 10000){
		G[i].pb({mat[i][j], j});
		G[j].pb({mat[i][j], i});
	}

	FOR(i, 0, K){
		int a, b;
		ri(a); ri(b);
		--a; --b;
		S[i]= a; D[i] = b;
	}
}

ll solve(){
	dijk();
	init();
	ll ans = pick(0, 0) + dist[0][S[0]];
	if(ans >= LINF) return -1;
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