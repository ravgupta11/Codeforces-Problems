
#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

#define ll long long int
#define pb push_back
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORR(i, a, b) for(int i = a; i > b; i--)
#define ri(x) scanf("%d",&x);
#define rii(x,xx) scanf("%d %d", &x, &xx);
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<pi, int> pii;

const int MAXN = 1e5+4;
const int INF = 1e7+7;

int other(pii x, int u){
    if (x.first.first == u) return x.first.second;
    return x.first.first;
}

vi G[MAXN], ord;
bool vis[MAXN];
vector< pii > ELi;
int N;
int cnt[MAXN];
bool solve(int ln, int lln,int avoid =-1){
    bool check = true;
    bool ans = true;
    for(int i: G[ln]){
        if(vis[other(ELi[i], ln)]) continue;
        for(int j: G[lln]){
            if((other(ELi[i],ln) == other(ELi[j], lln) && other(ELi[i], ln) != avoid) && check){
                vis[other(ELi[i],ln)] = true;
                lln = ln; ln = other(ELi[i],ln);
                ord.pb(ln); check = false;
                ans = solve(ln,lln);
            }
            else if( (other(ELi[i],ln) == other(ELi[j], lln) && other(ELi[i], ln) != avoid) && !check ){
                if(N != 5) return false;
            }
        }
    }
    return ans;
}
bool edge(int u, int v){
    bool c = false;
    for(int i: G[u]){
        if(c) break;
        if(other(ELi[i], u) == v) c = true;
    }
    return c;
}

bool make(){
    int lln = 0;
    for(int i: G[0]){
        int avoid = other(ELi[i], 0);
        for(int j: G[0]){
            if(i==j) continue;
            ord.clear();
            FOR(it,0,N) vis[it] = false;
            int ln = other(ELi[j], 0);
            bool check = edge(ln, avoid);
            if(!check) continue;
            vis[ln] = vis[lln] = vis[avoid] = true; ord.pb(avoid); ord.pb(lln); ord.pb(ln);
            check = solve(ln, lln, avoid);
            if(check && ord.size() == N) return true;
        }
    }
    return false;
}

int main() {
    ri(N);
    memset(cnt,0,sizeof(int));
    FOR(i, 0, 2*N){
        int u, v;
        rii(u, v);
        u--;v--;
        ELi.pb({{u,v},0});
        G[u].pb(i);
        G[v].pb(i);
        cnt[u]++; cnt[v]++;
    }
    FOR(i, 0, N) if(cnt[i] != 4){
        printf("-1");
        return 0;
    }
    if(make())
        for(int i : ord)
            printf("%d ",i+1);
    else
        printf("-1");
    return 0;
}
