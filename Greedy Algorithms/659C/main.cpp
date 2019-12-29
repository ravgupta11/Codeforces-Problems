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
#define x first
#define y second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a; i>b; i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;

int n; ll m;
set<ll> S;
vector<ll> v, a;
const ll MAXN = 1e9;
int main(){
    ri(n); rl(m);
    FOR(i, 0, n){
        ll u;
        rl(u);
        v.pb(u);
    }
    v.pb(MAXN+1);
    ll s1 = 0;
    ll c1 = 0;
    sort(v.begin(), v.end());
    FOR(i, 0, n) {
        c1++;
        while (c1 < v[i] && s1+c1<=m) {
            a.pb(c1);
            s1 += c1;
            c1++;
        }
    }
    if(c1== v[n-1]) c1++;
    while(s1 +c1<=m){
        a.pb(c1);
        s1 += c1;
        c1++;
    }
    printf("%ld\n", a.size());
    FOR(i, 0, a.size())
        printf("%lld ", a[i]);
    return 0;
}