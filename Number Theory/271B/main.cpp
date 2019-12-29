#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <string.h>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <sstream>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#define ll long long int
#define pb push_back
#define x first
#define y second
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a; i>b; i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;
const int MAXN = 1000006;
int mat[501][501], n, m;


ll sumr(int i){
    ll s =0;
    FOR(j, 0, m) s+= mat[i][j];
    return s;
}

ll sumc(int i){
    ll s =0;
    FOR(j, 0, n) s += mat[j][i];
    return s;
}

vector<int> p;
bool pr[MAXN];

void sieve(){
    FOR(i, 2, 1e6)
        if(!pr[i]){
            p.pb(i);
            for(ll j = i*i; j<=1e6; j+= i) pr[j] = true;
        }
}

ll solve(){
    ri(n); ri(m);
    FOR(i, 0, n) FOR(j, 0, m) ri(mat[i][j]);
    FOR(i, 0, n) FOR(j, 0, m) {
            int in = (int)distance(p.begin(), lower_bound(p.begin(), p.end(), mat[i][j]));
            mat[i][j] =  p[in] - mat[i][j];
    }
    ll MIN = 1e9;
    FOR(i, 0, m) MIN = min(MIN, sumc(i));
    FOR(i, 0, n) MIN = min(MIN, sumr(i));
    return MIN;
}

int main(){
    sieve();
    ll ans = solve();
    printf("%lld", ans);
    return 0;
}