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
const int MAXN =1e5+5;
vector<int> G[MAXN];
int cats[MAXN];
int n, m, leaf = 0;
bool vis[MAXN];
void dfs1(int fro){
    vis[fro]= true;
    for(int to: G[fro]){
        if(vis[to]) continue;
        if(cats[to] != 0) cats[to] += cats[fro];
        dfs1(to);
    }
}

void dfs2(int fro, int par){
    vis[fro] = true;
    int cnt = 0;
    for(int to: G[fro]){
        if(to != par) cnt++;
        if(vis[to]) continue;
        if(cats[to] > m) continue;
        dfs2(to, fro);
    }
    if(cnt == 0) leaf++;
}
int main(){
    ri(n); ri(m);
    FOR(i, 0, n) ri(cats[i]);
    FOR(i, 0, n-1){
        int u, v; ri(u); ri(v);
        u--; v--;
        G[u].pb(v); G[v].pb(u);
    }
    FOR(i, 0, n) vis[i] = false;
    dfs1(0);
    FOR(i, 0, n) vis[i] = false;
    dfs2(0,-1);
    printf("%d", leaf);
    return 0;
}