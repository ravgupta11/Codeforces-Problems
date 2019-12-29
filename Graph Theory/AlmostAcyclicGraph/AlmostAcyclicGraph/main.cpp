#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;
const int MAXN = 505;

vector<int> G[MAXN];
vector<pair<int,int>> E;
vector<pair<int,int>> E1;
int N,M,T;
int col[MAXN];
int td[MAXN];
int st[MAXN];
int ok;
bool found;
void dfs(int v){
    col[v] = 1;
    td[v]=st[v]= T++;
    for(int u:G[v]){
        if(ok==1) continue;
        if(col[u]==0){
            dfs(u);
            td[v] = min(st[v],td[u]);
            if(td[v]==td[u]) E.push_back({v,u});
        }
        if(col[u]==1){
            td[v] = min(td[v],st[u]);
            E.push_back({v,u});
            ok = 1;
        }
    }
    col[v] =2;
}
void dfs2(int v,int a,int b){
    col[v] = 1;
    td[v]=st[v]= T++;
    for(int u:G[v]){
        if(v==a&&u==b) continue;
        if(col[u]==0){
            dfs2(u,a,b);
            td[v] = min(st[v],td[u]);
        }
        if(col[u]==1){
            td[v] = min(td[v],st[u]);
            found = true;
        }
    }
    col[v] =2;
}

void init(){
    for(int i =1;i<=N;i++){
        st[i] = 0;
        td[i] = 0;
        col[i] =0;
    }
    T=0;
    ok= 0;
}
int main() {
    scanf("%d %d",&N,&M);
    for(int i = 0;i<M;i++){// O(M)
        int u, v;
        scanf("%d %d",&u,&v);
        G[u].push_back(v);
        E1.push_back({u,v});
    }
    init();//O(N)
    for(int i =1;i<=N;i++){//O(N+M)
        if(col[i]==2) continue;
        dfs(i);
    }
    vector<pair<int,int>>::iterator it;
    //for(it = E.begin();it!=E.end();it++)
      // printf("%d %d\n",(*it).first,(*it).second);
    found  = false;int count =0;
    for(it = E.begin();it!=E.end();it++){//O(N)
        
        int v = (*it).first; int u = (*it).second;
        
        
        init();//O(N)
        found = false;
        for(int i =1;i<=N;i++){//O(N+M)
            if(col[i]==2) continue;
            dfs2(i,v,u);
        }
        if(!found){
            printf("YES");
            count++;
            break;
        }
    }
    if(!found&&!count) printf("YES");
    if(found) printf("NO");
    return 0;
}
