#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

#define ll long long int
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i,a,b) for(int i = a;i>b;i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;

typedef vector<ll> vl;
typedef vector<int> vi;

ll N, H;

bool f(ll k){
    ll P =0, ht = (k-H-1)/2;
    ll P2 = 0;
    if(ht*2 == k) P2 = ht*(ht+1);
    else P2 = (ht+1)*(ht+1);
    if (H<k) P = P2 +H*(H+1)/2 + H*(ht+1);
    else P = k*(k+1)/2;
    if(N>P) return false;
    return true;
}

ll bsearch(ll lo, ll hi){
    while(lo<hi){
        ll m = (lo+hi+1)/2;
        //printf("%lld -> %d and %lld -> %d\n",m, f(m), m-1, f(m-1));
        if(f(m) && !f(m-1)) return m;
        else if (f(m) && f(m-1)) hi = m-1;
        else lo = m +1;
    }
    return lo;
}
int main(){
    rl(N); rl(H);
    ll ans = bsearch(1, N);
    printf("%lld",ans);
}
