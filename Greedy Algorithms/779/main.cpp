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
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#define ll long long int
#define pb push_back
#define x first
#define y second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a; i>b; i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;
const int MAXN = 1e6+5;

vector <pair<ll, pair<ll, ll> > > S, Sd;
vector<ll> C, D;
int n, k;
int main(){
    ri(n); ri(k);
    FOR(i, 0, n){
        ll u; rl(u); C.pb(u);
    }
    FOR(i, 0, n){
        ll u; rl(u); D.pb(u);
    }
    ll sum= 0;
    int cnt = 0;
    FOR(i, 0, n) S.pb({C[i] - D[i] ,{D[i], C[i]}});
    for(auto i: S){
        if(i.x < 0 ) {
            sum += i.y.y;
            cnt++;
        }
        else Sd.pb(i);
    }
    sort(Sd.begin(), Sd.end());
    for(auto i: Sd) {
        if (cnt < k) {
            sum += i.y.y;
            cnt++;
        } else {
            sum += i.y.x;
            cnt++;
        }
    }
    printf("%lld", sum);
    return 0;
}