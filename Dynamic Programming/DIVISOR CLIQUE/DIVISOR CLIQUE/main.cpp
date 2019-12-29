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

const int MAXN = 2e3 +5;
const ll INF = 1e9+9;

vl A;
int N, dp[MAXN];

void init(){
    FOR(i, 0, N) dp[i] =-1;
}

int DP(int i){
    if(dp[i] != -1) return dp[i];
    int MAX = 0;
    FOR(j, i+1, N){
        if(A[j] % A[i] ==0)
            MAX =  max(MAX, DP(j)+1);
    }
    return dp[i] = MAX;
}

int main() {
    ri(N);
    FOR(i, 0, N){
        ll u;
        rl(u);
        A.pb(u);
    }
    sort(A.begin(),A.end());
    init();
    int ans = 0;
    FOR(i,0,N)
        ans = max(ans, DP(i) + 1);
    printf("%d", ans);
    return 0;
}
