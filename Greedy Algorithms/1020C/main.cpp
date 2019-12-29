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

const int MAXN = 3001;
int n, m;


vector<ll> P[MAXN];




int main(){
    ri(n); ri(m);
    FOR(i, 0, n){
        ll p; int par;
        ri(par); rl(p); par--;
        P[par].pb(p);
    }
    FOR(i, 0, m)
      sort(P[i].begin(), P[i].end());
    ll MIN = 1e18;
    FOR(i, 1, n+1){
        vector<ll> rem;
        int ch = (int)P[0].size();
        ll cost = 0;
        FOR(k, 1, m){
            int j = 0;
            if(P[k].size() >= i){
                int lp = max((int)P[k].size() - i +1, 0);
                while(j<lp) {
                    cost += P[k][j];
                    j++;
                    ch++;
                }
            }
            while(j< P[k].size()){
                rem.pb(P[k][j]);
                j++;
            }
        }
        if(ch < i) {
            nth_element(rem.begin(), rem.begin() + i- ch ,rem.end());
            int lp = i - ch;
            FOR(j, 0, lp)
                cost += rem[j];
        }
        MIN = min(MIN, cost);
    }
    printf("%lld", MIN);
    return 0;
}