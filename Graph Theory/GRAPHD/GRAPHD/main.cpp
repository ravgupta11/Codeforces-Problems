#include <iostream>
#include <vector>
#include <queue>
#define pb push_back
using namespace std;
typedef vector<int> vi;
const int MAXN = 2e5+5;

vi G[MAXN];
int N;
bool vis[MAXN];

int MAX_D;
int MAX_N;
void init(){
    for(int i =1;i<=N;i++)
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
        scanf("%d",&N);
        MAX_D=0;
        MAX_N =0;
        for(int i=2;i<=N;i++){
            int u;
            scanf("%d",&u);
            G[i].pb(u);G[u].pb(i);
        }
        init();
        dfs(1,0);
        init();
        dfs(MAX_N,0);
    printf("%d",MAX_D);
    return 0;
}
