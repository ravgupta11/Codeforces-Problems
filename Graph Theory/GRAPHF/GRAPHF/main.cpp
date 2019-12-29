#include <iostream>
#include <utility>
#include <vector>
#define ll long long
using namespace std;

vector < pair<int,int> > e;
const int MAXN = 2e5+5;
vector<int> G[MAXN];
int N, M;
bool vis[MAXN];
int col[MAXN];

void dfs(ll v, int T){
    col[v] = T = 1-T;
    vis[v] = true;
    for(ll u: G[v]){
        if(vis[u]) continue;
        dfs(u, T);
    }
}

int main() {
        scanf("%d %d", &N, &M);
        for(int i = 1;i<=N;i++){
            G[i].clear();
            e.clear();
            col[i] = 0;
            vis[i] = false;
        }
        for(int i = 0;i<M;i++){
            int u, v;
            scanf("%d %d", &u, &v);
            e.push_back({u,v});
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i = 1;i<=N;i++){
            if(vis[i]) continue;
            int T = 1;
            dfs(i, T);
        }
        bool found = false;
        for(int i = 0;i<M;i++){
            pair <int,int> f = e.back();
            e.pop_back();
            int u = f.first;
            int v = f.second;
            if(col[u]==col[v]){
                found = true;
                break;
            }
        }
    if(found){
        printf("NO");
    }
    else{
        printf("YES");
    }
}
