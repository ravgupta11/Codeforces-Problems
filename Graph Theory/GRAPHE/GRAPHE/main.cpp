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
typedef vector<short> vi;
typedef vector< vector<short> > vii;
typedef pair<int,int> pi;
typedef pair<ll,int> pl;
typedef set< pair<ll,int> > s;
const int MAXN = 2e5+5;
int n,m;
vi G[MAXN];
vi cycle;
int dep[MAXN];
int fup[MAXN];
int col[MAXN];
bool e;

void dfs(int u,int d){
    col[u] =1;
    dep[u] = fup[u] =d;
    for(int v:G[u]){
        if(e) continue;
        if(col[v]==2) continue;
        if(col[v]==1){
            fup[u] =min(fup[u],dep[v]);
            e = true;
            cycle.pb(v);//back edge
            cycle.pb(u);
        }
        if(col[v]==0){
            dfs(v,d+1);
            if(fup[v]<=fup[u]){
                fup[u] =fup[v];
                cycle.pb(u);
            }
        }
    }
    col[u] =2;
}

void init(){
    for(int i =0;i<n;i++){
        col[i] =0;
        G[i].clear();
    }
    e =false;
    cycle.clear();
}
void print(vi &V){
    reverse(V.begin(), V.end());
    vi::iterator it;
    for(it =V.begin();it!=V.end();it++)
        printf("%d ",(*it)+1);
    printf("\n");
}
int main(){
    short t;
    scanf("%hu",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        init();
        for(int it=0;it<m;it++){
            int u,v;
            scanf("%d %d",&u,&v);
            u--;v--;
            G[u].pb(v);
        }
        for(int i=0;i<n;i++){
            if(col[i]==2||e) continue;
            dfs(i,0);
        }
        if(e){
            printf("NO\n%ld\n",cycle.size()-1);
            print(cycle);
        }
        else{
            printf("YES\n");
        }
    }
}
