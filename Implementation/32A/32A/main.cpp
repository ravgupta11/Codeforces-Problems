#include <iostream>
#include <vector>
using namespace std;
#define ll long long int
#define FOR(i,a,b) for(int  i= a;i<b;i++)
#define rl(x) scanf("%lld ",&x);
#define rll(x,y) scanf("%lld %lld",&x,&y);
typedef vector<ll> vl;

vector<ll> H;

ll solve(){
    ll N,D;
    rll(N,D);
    H.resize(N);
    FOR(i,0,N) rl(H[i]);
    ll ans = 0;
    FOR(i,0,N) FOR(j,0,N){
        if(i==j) continue;
        ll dif = H[i] - H[j];
        if(dif<0) dif = -dif;
        if(dif<=D) ans++;
    }
    return ans;
}

int main(){
    ll ans = solve();
    printf("%lld ",ans);
    return 0;
}
