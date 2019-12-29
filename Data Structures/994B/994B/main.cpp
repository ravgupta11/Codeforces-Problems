#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <utility>
#include <set>
#include <queue>
#define ll long long int
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i,a,b) for(int i = a;i>b;i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;

typedef vector<ll> vl;
typedef vector<int> vi;

int N, K;
vector< pair<ll, pair<ll,int>> > Kn;

int main() {
    ri(N); ri(K);
    vl P, C;
    FOR(i, 0, N){
        ll u;
        rl(u); P.pb(u);
    }
    FOR(i, 0, N){
        ll u;
        rl(u); C.pb(u);
    }
    if(K==0){
        FOR(i, 0, N) printf("%lld ",C[i]);
        return 0;
    }
    FOR(i, 0, N)
        Kn.pb( {P[i], {C[i],i}} );
    sort(Kn.begin(),Kn.end());
    priority_queue<ll> S;
    S.push(-Kn[0].se.fi);
    ll sum = Kn[0].se.fi;
    int cnt = 1;
    FOR(i, 1, N){
        sum += Kn[i].se.fi;
        int in = Kn[i].se.se;
        C[in] = sum;
        S.push(-Kn[i].se.fi); cnt++;
        if(cnt>K){
            sum += S.top();
            S.pop();
            cnt--;
        }
    }
    FOR(i,0,N) printf("%lld ",C[i]);
    return 0;
}
