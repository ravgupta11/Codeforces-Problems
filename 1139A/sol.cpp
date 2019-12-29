#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define FOR(i, a, b) for(int i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a;i>b; i—-)
#define ri(x) scanf("%d", &x);
#define rl(x) scanf("%lld", &x)
using namespace std;
 
typedef long long ll;
typedef long double dbl;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<char> vc;
const int INF = 2e6;
const ll LINF = 8e18;
const int MOD = 1e9 + 7;
const dbl EPS = 1e-9;
 
 
int main(){
    int n; ri(n);
    char str[100005];
    scanf("%s", str);
    ll ans = 0;
    FOR(i, 0, n)
        if((str[i] - '0')%2==0) ans += i+1;
        printf("%lld ", ans);
        return 0;
}