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

const int MAXN = 5e5 +5;
const ll INF = 1e9+9;

ll D; int N, K;
vl A;
int dp[MAXN];
int suf[MAXN];
void init(){
    FOR(i, 0, MAXN){
        dp[i] = 0;
        suf[i] = 0;
    }
}

int DP(){
    int i = N-1;
    dp[N] =1;
    suf[N] =1;// sufix(i) is defined as dp[i] + dp[i+1] .. dp[N]
    while(i>-1){
        int jl = i+K-1;
        int jr = min((int) distance(A.begin(), upper_bound(A.begin(),A.end(), A[i]+D))-1, N-1);
        if(jl>=N || jr<jl) dp[i] =0;
        else dp[i] = min(suf[jl+1] - suf[jr+1] + dp[jr+1],1);
        //printf("%d %lld %d %d %d %lld %lld\n",i,A[i],dp[i],jl,jr,A[jl],A[jr]);
        suf[i] = suf[i+1] +dp[i];
        i--;
    }
    return dp[0];
}

int main() {
    ri(N); ri(K); rl(D);
    FOR(i, 0, N) {
        ll u; rl(u);
        A.pb(u);
    }
    sort(A.begin(), A.end());
    init();
    int ans = DP();
    if(ans) printf("YES");
    else printf("NO");
    return 0;
}
