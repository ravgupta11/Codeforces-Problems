#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define pb push_back
#define FOR(i,a,b) for(int i =a;i<b;i++)
#define ll long long int
using namespace std;
typedef vector<int> vi;
const int MAXN = 1e5+5;
vi G[MAXN];
int N,M,T,K,L,fup[MAXN],dep[MAXN];
bool vis[MAXN];
vi cyc;
bool check;
bool check2;
void init(){
    FOR(i,0,N) vis[i] = false;
    check = false;
    check2 = false;
    L = -1;
}

void dfs(int fro,int par,int d){
    vis[fro] = true;
    dep[fro] = d;
    fup[fro] = d;
    for(int to: G[fro]){
        if(to==par||check) continue;
        if(vis[to]){
            fup[fro] = min(fup[fro],dep[to]);
            int len = d - dep[to] + 1;
            if(len>=K+1) {
                L = to;
                check = true;
                check2 = true;
                cyc.pb(fro);
            }
        }
        else{
            dfs(to,fro,d+1);
            fup[fro] = min(fup[fro],fup[to]);
            if(check2){
                cyc.pb(fro);
                if(fro==L) check2 = false;
            }
        }
    }
}

void input(){
    scanf("%d %d %d",&N,&M,&K);
    FOR(i,0,M){
        int u,v;
        scanf("%d %d",&u,&v);u--; v--;
        G[u].pb(v); G[v].pb(u);
    }
}

int main() {
    input();
    init();
    dfs(0,-1,0);
    printf("%ld\n",cyc.size());
    FOR(i,0,cyc.size()){
        printf("%d ",cyc[i]+1);
    }
    return 0;
}
