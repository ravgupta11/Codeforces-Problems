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
ll n;

bool f(ll k){
    ll sumA = 0, sumB = 0;
    ll r = n;
    while(r>0){
        if(r>=k){
            sumA += k;
            r = r-k;
        }
        else {
            sumA += r;
            r = 0;
            break;
        }
        if(r>=10) {
            sumB += r/10;
            r = r - r/10;
        }
    }
    if(2*sumA >= n) return true;
    return false;
}



ll bsearch(ll lo, ll hi){
    while(lo<=hi){
        ll mi = (lo+hi)/2;
        //printf("%d %d %lld\n",f(mi), f(mi+1), mi);
        if(!f(mi) && f(mi+1)) return mi+1;
        if(f(mi) && f(mi+1) ) hi = mi-1;
        else lo = mi +1;
    }
    return lo;
}


int main() {
    rl(n);
    ll ans = bsearch(1, n);
    printf("%lld\n", ans);
    //printf("%d", f(1));
    return 0;
}
