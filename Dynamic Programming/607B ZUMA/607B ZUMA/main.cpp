#include <vector>
#include <iostream>
#define ll long long int
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int MAXN = 505;
const ll INF = 1e9+9;
typedef vector<ll> vl;
typedef vector<int> vi;

ll dp[MAXN][MAXN];
int N;
int A[MAXN];

void init(){
    FOR(i,0,MAXN)
        FOR(j,0,MAXN)
            dp[i][j] = -1;
}

void input(){
    scanf("%d",&N);
    FOR(i,0,N)
        scanf("%d",&A[i]);
}

ll DP(int i,int j){
    if(i==j|| i - j == 1) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    ll MIN = INF;
    FOR(it,i+1,j)
        if(A[i]==A[it])
            MIN = min(MIN,DP(i+1,it-1)+DP(it+1,j));
    MIN = min(MIN,1+DP(i+1,j));
    if(A[i]==A[j]) MIN = min(MIN,DP(i+1,j-1));
    return dp[i][j] = MIN;
}

int main() {
    input();
    init();
    ll ans = DP(0,N-1);
    printf("%lld\n",ans);
    return 0;
}
