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
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a; i>b; i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;
const int MAXN = 1e6+5;
int a, b, k;
int prime[MAXN];
ll pre[MAXN];

void sieve(){
    FOR(i, 2, MAXN) prime[i] = 1;
    FOR(i, 2, 1e4) if(prime[i]) for(ll j = i*i;j<=MAXN; j += i) prime[j] = 0;
}

void pre_calc(){
    pre[a] = prime[a];
    FOR(i, a+1 ,b+1)
        pre[i] = pre[i-1] + prime[i];
    //FOR(i, a+1, b+1) printf("%lld\n", pre[i]);
}

bool f(int l){
    FOR(i, a+l-1, b+1) {
        //printf("%lld\n", pre[i] - pre[i-l]);
        if(k > pre[i] - pre[i-l]) return false;
    }
    return true;
}
int bsearch(int lo, int hi){
    while(lo<hi){
        int mi = (lo+hi)/2;
        if(!f(mi-1) && f(mi)) return mi;
        else if(f(mi) && f(mi+1)) hi = mi-1;
        else lo = mi+1;
    }
    return lo;
}
int main(){
    sieve();
    ri(a); ri(b); ri(k);
    pre_calc();
    int lo = 1, hi = b - a +1;
    int ans = bsearch(lo, hi);
    if(f(ans)) printf("%d", ans);
    else printf("-1");
    return 0;
}
