#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <math.h>
#include <set>
#define pb push_back
#define ll long long int
using namespace std;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector< vector<short> > vii;
typedef pair<int,int> pi;
typedef pair<ll,int> pl;
typedef set< pair<ll,int> > s;
const int MAXN = 2e5+5;
int n,m;
vi G[MAXN];
bool vis[MAXN];
bool vis2[MAXN];
int S[MAXN];
int cnt;
void dfs(int s){
    vis[s] = true;
    cnt++;
    for(int u: G[s]){
        if(vis[u]) continue;
        dfs(u);
    }
}

void dfs1(int s){
    vis2[s] = true;
    S[s] =cnt;
    for(int u: G[s]){
        if(vis2[u]) continue;
        dfs1(u);
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i= 0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        u--;v--;
        G[u].pb(v);
        G[v].pb(u);
    }
    for(int i=0;i<n;i++) {
        vis2[i] = false;
        vis[i] = false;}
    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        cnt=0;
        dfs(i);
        dfs1(i);
    }
    for(int i =0;i<n;i++){
        printf("%d ",S[i]);
    }
    return 0;
    
}
