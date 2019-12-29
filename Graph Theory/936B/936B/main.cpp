#include <vector>
#include <iostream>
#define ll long long int
#define FOR(i,a,b) for(int i = a;i<b;i++)
#define pb push_back
using namespace std;
struct node{
    int u,par;
};
const int MAXN = 2e5+5;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<struct node> vs;

vs SG[MAXN][3];
vi stk;
vi G[MAXN];
int col[MAXN][3];
bool vis[MAXN][3];
bool cyc;
bool odeg;
int N,M;

void BUILD(int u,int par){
    vis[u][par] = true;
    for(int v: G[u]){
        struct node tmp;
        tmp.u = v;
        tmp.par = 1-par;
        SG[u][par].pb(tmp);
        if(vis[v][1-par]) continue;
        BUILD(v,1-par);
    }
}

void DFS(int u,int par){
    col[u][par] = 1;
    for(struct node t: SG[u][par]){
        int v  =t.u; int p = t.par;
        if(col[v][p]==2) continue;// v,p is black
        if(col[v][p]==1) cyc = true;// v,p is grey
        else DFS(v,p);// v,p is white
    }
    col[u][par] = 2;
}

void DFS2(int u, int par){
    vis[u][par] = true;
    int E= 0;
    for(struct node t : SG[u][par]){
        E++;
        int v = t.u; int p = t.par;
        if(vis[v][p]||odeg) continue;
        DFS2(v,p);
    }
    if(!E && par==1) odeg = true;
    if(odeg)
        stk.pb(u);
}

int main() {
    scanf("%d %d",&N,&M);
    FOR(i,0,N){
        int e;
        scanf("%d",&e);
        FOR(j,0,e){
            int v;
            scanf("%d",&v); v--;
            G[i].pb(v);
        }
    }
    int src;
    scanf("%d",&src); src--;
    FOR(i,0,N+1) FOR(j,0,3) vis[i][j] = false;
    BUILD(src,0);
    odeg = false;
    FOR(i,0,N+1) FOR(j,0,3) vis[i][j] = false;
    DFS2(src,0);
    if(odeg){
        printf("Win\n");
        while(!stk.empty()){
            printf("%d ",stk.back()+1);
            stk.pop_back();
        }
    }
    else{
        cyc = false;
        FOR(i,0,N+3) FOR(j,0,3) col[i][j]= 0;
        DFS(src,0);
        if(cyc)
            printf("Draw");
        else
            printf("Lose");
    }
    return 0;
}
