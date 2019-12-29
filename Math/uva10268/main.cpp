#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

#define ll long long int
#define pb push_back

#define y second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a; i>b; i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;

const int MAXN = 1e6+5;
ll P[MAXN];


ll eval(ll n, ll x){
    if(n<0) return 0;
    if(n==0) return P[n];
    return (eval(n-1, x)*x + P[n]);
}

int main(){
        ll x;
        while(rl(x) != EOF){
            string s;
            getline(cin, s);
            getline(cin, s);
            stringstream ss;
            ss << s;
            ll n = 0;
            while(ss >> P[n]) n++;
            ll m = n-1;
            FOR(i, 0, n){
                P[i] = P[i]*m;
                m -= 1;
            }
            ll ans = eval(n-2, x);
            cout<< ans << endl;
        }
    return 0;
}
