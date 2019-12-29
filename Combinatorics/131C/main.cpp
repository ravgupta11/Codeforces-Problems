#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

#define ll long long int
#define pb push_back
#define fi first
#define se second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a; i>b; i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
#define ub(A,x) upper_bound(A.begin(), A.end(), x)
#define lb(A,x) lower_bound(A.begin(), A.end(), x)
using namespace std;
const int MAXN = 2e5;
typedef vector< pair<ll,int> > vli;
typedef pair<ll ,int> pli;
typedef pair<int, int> pi;
typedef vector<pi > vii;

ll dp[100][100];

ll comb(ll n, ll k){
    if(k>n) return 0;
    if(n==k||k==0) return 1;
    if(dp[n][k] != -1) return dp[n][k];
    return dp[n][k] = comb(n-1, k-1) + comb(n-1, k);
}

int main(){
    ll n, m, t;
    rl(n); rl(m); rl(t);
    FOR(i, 0, 100) FOR(j, 0, 100) dp[i][j] = -1;
    comb(100,99);
    ll s = 0;
    FOR(i, 4, n+1) {
        if (t - i < 1) continue;
        s += comb(n, i)*comb(m, t-i);
    }
    printf("%lld", s);
    return 0;
}