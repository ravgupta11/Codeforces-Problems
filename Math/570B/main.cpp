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

void solve(){
    ll n, m;
    rl(n); rl(m);
    if(n == 1 && m == 1) {
        printf("1");
        return;
    }
    ll cL = m -1, cR = n - m;
    if(cL >= cR)
        printf("%lld", m-1);
    else
        printf("%lld", m+1);
}

int main(){
    solve();
    return 0;
}