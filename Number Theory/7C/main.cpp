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

#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FORR(i, a, b) for(ll i = a; i>b; i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;
const int MAXN = 1e6+1;

void direc(ll &a){
    if(a<0) {
        a*=-1;
    }
}

ll gcd(ll a, ll b, ll &x, ll &y){
    if(b==0){
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll ans= gcd(b, a%b, x1, y1);
    y = x1 - (a/b)*y1;
    x = y1;
    return ans;
}

void solve(){
    ll a, b, c; int mx = 1, my = 1;
    rl(a); rl(b); rl(c);
    if(a<0) mx = -1;
    if(b<0) my = -1;
    direc(a); direc(b);
    ll x, y;
    ll g = gcd(max(a,b), min(a,b), x, y);

    if(abs(c)%g == 0) {
        g = -g;
        x = (c/g)* x;
        y = (c/g)* y;
        if(max(a,b)==b){
            ll t = x;
            x = y;
            y = t;
        }
        x = mx*x;
        y = my*y;
        //printf("%lld %lld %lld %lld %lld\n", a,b,g, x,y);
        printf("%lld %lld", x, y);
       // if(mx*a*x + my*b*y + c== 0) printf("\nYES");
    }
    else printf("-1");
}

int main(){
    solve();
    return 0;
}