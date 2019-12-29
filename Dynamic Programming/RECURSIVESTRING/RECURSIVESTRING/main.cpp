#include <vector>
#include <iostream>
#include <algorithm>

#define ll long long int
#define pb push_back
#define x first
#define y second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;
typedef pair<int,int> pi;
const int MAXN = 36;
ll dp[MAXN];


int pos(ll n, ll k){
    while(n > 2){
        if(k>dp[n-1]){
            k -= dp[n-1];
            if(k > dp[n-2]){
                k -= dp[n-2];
                n = n-3;
            }
            else
                n = n-2;
        }
        else
            n = n-1;
    }
    return 2-(int)n;
}


void init(){
    FOR(i, 0, MAXN) dp[i] = -1;
}



int main() {
    int N;ll K;
    ri(N); rl(K);
    init();
    dp[0] = dp[1] = dp[2] = 1;
    FOR(i, 3, N+1) dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    ll len =dp[N];
    if(len < K){
        printf("-1");
        return 0;
    }
    int c = pos(N, K);
    if(c==0) printf("c");
    else if(c==1) printf("b");
    else if(c==2) printf("a");
    return 0;
}
