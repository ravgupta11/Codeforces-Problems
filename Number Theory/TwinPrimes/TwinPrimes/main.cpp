#include <bits/stdc++.h>

#define ll long long int
#define pb push_back
#define x first
#define y second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a; i>b; i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)

using namespace std;
typedef vector<int> vi;
typedef vector<ll> vl;

struct twin{
    int p1, p2;
};

const int MAXN = 2e7+1;
const ll INF = 1e9;

typedef vector<int> vi;

bool prime[MAXN];
vi p;
int lp[MAXN];
vector<struct twin> ans;

void sieve(){
    FOR(i, 2, MAXN){
        if (lp[i] == 0) {
            lp[i] = i;
            p.push_back (i);
        }
        for (int j=0; j<(int)p.size() && p[j]<=lp[i] && i*p[j]<=MAXN; j++){
            lp[i * p[j]] = p[j];
        }
    }
}

int main() {
    sieve();
    FOR(i,0,p.size()-1){
        if(p[i+1] - p[i] == 2){
            struct twin tmp;
            tmp.p1 = p[i];
            tmp.p2 = p[i+1];
            ans.pb(tmp);
        }
    }
    int n;
    while(1){
        if(ri(n) == EOF) break;
        printf("(%d, %d)\n", ans[n-1].p1, ans[n-1].p2);
    }
    return 0;
}
