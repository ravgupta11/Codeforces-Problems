#include <iostream>
#include <vector>
#include <queue>
#define pb push_back
using namespace std;
typedef vector<int> vi;
const int MAXN = 1e5+5;

vi G[MAXN];
int N;
bool vis[MAXN];

int MAX_D;
int MAX_N;
void init(){
    for(int i =0;i<N;i++)
        vis[i] = false;
}

void dfs(int s,int k){
    vis[s] = true;
    for(int u:G[s]){
        if(vis[u]) continue;
        dfs(u,k+1);
    }
    if(k>MAX_D){
        MAX_D = k;
        MAX_N = s;
    }
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&N);
        for(int i =0;i<N;i++) G[i].clear();
        MAX_D=0;
        MAX_N =0;
        for(int i=0;i<N-1;i++){
            int u,v;
            scanf("%d %d",&u,&v);
            G[u].pb(v);G[v].pb(u);
        }
        init();
        dfs(0,0);
        init();
        dfs(MAX_N,0);
        if(MAX_D%2==0)
            printf("%d\n",MAX_D/2);
        else
            printf("%d\n",(MAX_D+1)/2);
    }
    return 0;
}
