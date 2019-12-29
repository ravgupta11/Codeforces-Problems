#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int MAXN = 1e5+5;
int N,M,T=0;;
vector< int > G[MAXN];
vector<int> rG[MAXN];
stack<int> s;
bool vis[MAXN];
int SCC[MAXN];

void dfs1(int v){
    vis[v] = true;
    for(int u:rG[v]){
        if(vis[u]) continue;
        dfs1(u);
        s.push(u);
    }
}
void dfs2(int v){
    vis[v] = true;
    SCC[v] = T;
    for(int u: G[v]){
        if(vis[u]) continue;
        dfs2(u);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for(int it = 0;it<t;it++){
        scanf("%d", &N);
        bool com[MAXN];
        for(int i = 0;i<N;i++){
            G[i].clear();
            rG[i].clear();
            vis[i] = false;
            com[i] = false;
            SCC[i] = 0;
            T=0;
        }
        for(int i = 0;i<N;i++){
            char s[MAXN];
            scanf("%s" ,s);
            for(int j = 0;j<N;j++){
                char c = s[j];
                if(c=='Y'){
                    G[i].push_back(j);
                    rG[j].push_back(i);
                }
            }
        }
        for(int i = 0;i<N;i++){
            if(vis[i]) continue;
            dfs1(i);
            s.push(i);
        }
        for(int i = 0;i<N;i++){
            vis[i] = false;
        }
        while(!s.empty()){
            int v = s.top(); s.pop();
            if(vis[v]) continue;
            dfs2(v);
            T++;
        }
        for(int v = 0;v<N;v++){
            com[SCC[v]] = true;
        }
        int c = 0;
        for(int i = 0;i<N;i++)
            if(com[i]) c++;
        printf("%d\n",c);
    }
    return 0;
}
