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
vector<ll> A, B;
int main(){
    ll  n, m;
    rl(n); rl(m);
    FOR(i, 0, n){
        ll u; rl(u); A.pb(u);
        B.pb(0);
    }
    B.pb(0);
    FOR(i, 0, m){
        ll u, v; ri(u); ri(v);
        u--;
        B[u]++; B[v]--;
    }
    FOR(i, 1, n)
        B[i] += B[i-1];
    sort(B.begin(), B.end());
    reverse(B.begin(), B.end());
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    ll s= 0;
    FOR(i, 0, n)
        s += A[i]*B[i];
    printf("%lld", s);
}