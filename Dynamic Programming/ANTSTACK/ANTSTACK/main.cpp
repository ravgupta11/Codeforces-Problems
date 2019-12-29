#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <math.h>
#include <set>
#define FOR(i,a,b) for(int i = a;i<b;i++)
#define pb push_back
#define ll long long int
#define fi first
#define se second
using namespace std;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,int> pl;
typedef set< pair<ll,int> > s;
typedef pair<pair<int,int>, pair<int,int> > pt;
const ll INF = 1e9+9;
const int MAXN = 1e5+5;
ll dp[MAXN][102];
int N;
ll w[102];

void init(){
    FOR(i,0,MAXN){
        FOR(j,0,102)
        dp[i][j] = -1;
    }
}
void input(){
    scanf("%d",&N);
    FOR(i,0,N)
        scanf("%lld",&w[i]);
}


ll DP(ll S,int j){
    if(j>=N) return 0;
    if(dp[S][j]!=-1) return dp[S][j];
    ll MAX = 0;
    FOR(i,j,N){
        if(S<=6*w[i])
            MAX = max(MAX,1+DP(S+w[i],i+1));
    }
    return dp[S][j] = MAX;
}

int main() {
    int t;
    scanf("%d",&t);
    FOR(it,1,t+1){
        input();
        init();
        ll ans = DP(0,0);
        printf("Case #%d: %lld\n",it,ans);
    }
    return 0;
}
