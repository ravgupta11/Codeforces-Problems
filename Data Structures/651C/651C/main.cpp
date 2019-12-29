#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")
#define ll long long int
#define pb push_back
#define x first
#define y second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a; i>b; i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;
const ll INF = 1e9+9;

struct pr{
    ll lhs, rhs;
    bool operator<( const pr &a) const{
        if(lhs == a.lhs) return rhs<a.rhs;
        return lhs<a.lhs;
    }
};
multiset< struct pr > s1,s2, s3;



int main(){
    int n;
    ri(n);
    FOR(i, 0, n){
        ll u,v ;
        rl(u); rl(v);
        s1.insert({u,v});
        s2.insert({v,u});
        s3.insert({u,v});
    }
    ll cnt = 0, fcnt = 0;
    ll lx = -INF,  ly = -INF;
    FOR(i, 0, n){
        ll u = (*s1.begin()).lhs , v = (*s1.begin()).rhs; s1.erase(s1.begin());
        if(lx == u) {
            cnt++;
        }
        else{
            fcnt += (cnt+1)*cnt/2;
            cnt = 0;
        }
        lx = u; ly = v;
    }
    if(cnt > 0) fcnt += (cnt+1)*(cnt)/2;
    lx = -INF; ly = -INF;
    cnt = 0;
    FOR(i, 0, n){
        ll u = (*s2.begin()).lhs , v = (*s2.begin()).rhs; s2.erase(s2.begin());
        if(lx == u){
            cnt++;
        }
        else{
            fcnt += (cnt+1)*cnt/2;
            cnt = 0;
        }
        lx = u; ly = v;
    }
    if(cnt > 0) fcnt += (cnt+1)*cnt/2;
    lx = -INF; ly = -INF;
    cnt = 0;
    FOR(i, 0, n){
        ll u = (*s3.begin()).lhs , v = (*s3.begin()).rhs; s3.erase(s3.begin());
        if(lx == u && ly == v){
            cnt++;
        }
        else{
            fcnt -= (cnt+1)*cnt/2;
            cnt = 0;
        }
        lx = u; ly = v;
    }
    if(cnt > 0) fcnt -= (cnt+1)*cnt/2;
    printf("%lld", fcnt);
    return 0;
}
