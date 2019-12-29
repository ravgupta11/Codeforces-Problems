#include <vector>
#include <iostream>
#include <algorithm>

#define ll long long int
#define pb push_back
#define x first
#define y second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;
typedef pair<int,int> pi;
const int MAXN = 1e5+5;

vector<pi > Q[11];
ll bits[MAXN];
int N, M;

bool in(int x, int l, int r){
    if(x>=l && x<=r) return true;
    return false;
}

int main() {
    ri(N); ri(M);
    FOR(i, 0, N){
        int u, v, k; ri(u); ri(v); u--; v--;
        ri(k);
        Q[k].pb({u,v});
    }
    FOR(k, 1, 11) {
        int lx =-1,ly =-1;
        sort(Q[k].begin(),Q[k].end());
        for(pi n: Q[k]){
            int l = n.x, r = n.y;
            if(in(l,lx,ly) && ly<r){
                bits[ly+1]++; bits[r+1]--;
                ly = r;
            }
            else if(in(l,lx,ly) && in(r,lx,ly)) continue;
            else if(!in(l,lx,ly)){
                bits[l]++; bits[r+1]--;
                lx = l; ly = r;
            }
        }
    }
    ll s = 0;
    FOR(i, 0, M){
        bits[i] = s + bits[i];
        s = bits[i];
    }
    //FOR(i, 0, M) printf("%lld ", bits[i]);
    ll MAX =-1;
    FOR(i, 0, M){
        MAX = max(MAX, bits[i]);
    }
    if(MAX != N) MAX++;
    printf("%lld",MAX);
    return 0;
}
