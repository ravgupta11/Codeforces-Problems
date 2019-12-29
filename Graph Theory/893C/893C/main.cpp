#include<iostream>
#include<vector>
#define ll long long int
using namespace std;
const int MAXN = 1e5+5;
const ll INF = 2e9+8;
ll m = INF;
vector<int> G[MAXN];
ll c[MAXN];
int N,M;
bool vis[MAXN];


void dfs(int v){
    vis[v] = true;
    m = min(m,c[v]);
    for(int u:G[v]){
        if(vis[u]) continue;
        dfs(u);
    }
}

void init(){
    for(int i= 1;i<=N;i++){
        vis[i] = false;
        G[i].clear();
        c[i] = 0;
    }
}
int main(){
    scanf("%d %d",&N,&M);
    init();
    for(int i = 1;i<=N;i++)
        scanf("%lld",&c[i]);
    for(int i =1;i<=M;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ll sum =0;
    for(int i =1;i<=N;i++){
        if(vis[i]) continue;
        m = INF;
        dfs(i);
        sum+= m;
    }
    printf("%lld",sum);
    return 0;
}
