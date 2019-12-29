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
#define  ll long long int
#define pb push_back
#define x first
#define y second
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a; i>b; i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;
const int MAXN = 1000006;

int solve(){
    ll x;
    rl(x);
    if(x==2) return 2;
    return 1;
}
int main() {
    printf("%d", solve());
    return 0;
}