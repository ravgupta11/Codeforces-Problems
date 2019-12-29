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
const int MAXN = 1e5+5;
bool vis[MAXN];

vi G[MAXN];
vi topo;
int n,m;

int col[MAXN];
bool e;

void dfs(int u){
    col[u] =1;
    for(int v:G[u]){
        if(e) continue;
        if(col[v]==2) continue;
        if(col[v]==1){
            e = true;
        }
        if(col[v]==0){
            dfs(v);
        }
    }
    col[u] =2;
}
void topo_sort(int u){
    vis[u] =true;
    for(int v:G[u]){
        if(vis[v]) continue;
        topo_sort(v);
    }
    topo.pb(u);
    
}
void init(){
    for(int i =0;i<n;i++){
        vis[i] = false;
        col[i] =0;
    }
}

void print(vi &V){
    reverse(V.begin(), V.end());
    vi::iterator it;
    for(it =V.begin();it!=V.end();it++)
        printf("%d ",(*it));
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i =0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        G[u].pb(v);
    }
    init();
    e =false;
    for(int i =0;i<n;i++){
        if(col[i]==2||e) continue;
        dfs(i);
    }
    if(e){
        printf("NO");
        return 0;
    }
    printf("YES\n");
    for(int i =0;i<n;i++){
        if(vis[i]) continue;
        topo_sort(i);
    }
    print(topo);
}
