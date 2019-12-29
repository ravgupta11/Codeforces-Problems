#include <vector>
#include <iostream>
#include <algorithm>

#define ll long long int
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;

typedef vector<ll> vl;
typedef vector<int> vi;

const int MAXN = 2e5 +5;
const ll INF = 1e9+9;
int N;ll A[MAXN]; ll dp[MAXN];

void init(){
    FOR(i, 0, N) dp[i] = -INF;
}

ll DP(int i){
    if(i==N-1) return -INF;
    if(i>N-1) return 0;
    if(dp[i] != -INF) return dp[i];
    dp[i] = max(A[i]+A[i+1] + DP(i+2), A[i]+A[i+1]);
    return dp[i];
}

int main() {
    ri(N);
    FOR(i, 0, N) rl(A[i]);
    init();
    DP(0); DP(1);
    ll ans = -INF;
    FOR(i, 0, N) ans = max(dp[i], ans);
    printf("%lld", ans);
    return 0;
}
