#include <iostream>
#include <vector>
using namespace std;
int cnt;

struct edge{
    int a,b;
};

int N;
const int MAXN = 1e5+5;
bool vis[MAXN];
vector <int> G[MAXN];
vector <struct edge> edges;
void dfs(int u){
    vis[u] =true;
    for(int v:G[u]){
        if(vis[v]) continue;
        cnt++;
        struct edge e;
        e.a = v;
        e.b = u;
        edges.push_back(e);
        dfs(v);
    }
    
}
int main(){
    scanf("%d",&N);
    char s2[MAXN],s1[MAXN];
    scanf("%s\n%s",s1,s2);
    for(int i = 0;i<N;i++){
        int a =s1[i]-97;
        int b =s2[i]-97;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cnt =0;
    for(int i =0;i<27;i++){
        vis[i]= false;
    }
    for(int i =0;i<N;i++){
        int a = s1[i] -97;
        if(vis[a]) continue;
        dfs(a);
    }
    printf("%d\n",cnt);
    while(!edges.empty()){
        struct edge e = edges.back();
        edges.pop_back();
        char a1 =(char)(e.a+97);
        char b1 = (char)(e.b+97);
        printf("%c %c\n",a1,b1);
    }
    return 0;
}
