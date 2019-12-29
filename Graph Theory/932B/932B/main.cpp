#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 1e6+5;
vector<int> G[MAXN];
int red[MAXN];
bool vis[MAXN];

int p[10][MAXN];
void build_p(){
    for(int i =1;i<10;i++)
        for(int j = 1;j<MAXN;j++){
            p[i][j] = p[i][j-1];
            if(red[j]==i) p[i][j]++;
        }
}

void dfs(int s,int k){
    vis[s] =true;
    for(int u:G[s]){
        if(vis[u]) continue;
        red[u] =k;
        dfs(u,k);
    }
}

int f1(int n){
    int d = n;
    int p = 1;
    while(d!=0){
        int a =d%10;
        if(a!=0) p*=a;
        d /=10;
    }
    return p;
}
void build(){
    for(int i = 1e6+1;i>9;i--){
        int j = f1(i);
        G[j].push_back(i);
    }
}
void init(){
    for(int i =0;i<=MAXN;i++) vis[i] =false;
    for(int i =1;i<10;i++) red[i] = i;
}
int main(){
    int Q;
    scanf("%d",&Q);
    init();
    build();
    for(int i =1;i<10;i++)
        dfs(i,i);
    build_p();
    for(int i =0;i<Q;i++){
        int l,r,k;
        scanf("%d %d %d",&l,&r,&k);
        int cnt = p[k][r] - p[k][l-1];
        printf("%d\n",cnt);
    }
}
