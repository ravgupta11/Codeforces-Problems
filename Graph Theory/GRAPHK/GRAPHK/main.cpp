#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <math.h>
#include <set>
#include <map>
#define pb push_back
#define ll long long int
using namespace std;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector< vector<short> > vii;
typedef pair<int,int> pi;
typedef pair<ll,int> pl;
typedef set< pair<ll,int> > s;
const int MAXN = 2e5+5;
vector<int> G[MAXN];
vector< pi > bridge;
int dep[MAXN];
int fup[MAXN];
int col[MAXN];
int N,M;
map<pi,int> E;
void dfs(int u,int p,int d){
    col[u] =1;
    dep[u] = fup[u] =d;
    for(int v:G[u]){
        if(col[v]==2||v==p) continue;
        if(col[v]==1){
            fup[u] =min(fup[u],dep[v]);
        }
        if(col[v]==0){
            dfs(v,u,d+1);
            fup[u] =min(fup[u],fup[v]);
            if(dep[u]<fup[v]){
                bridge.pb({u,v});
            }
        }
    }
    col[u] =2;
}



void init(){
    for(int i=0;i<N;i++) col[i] =0;
}
void print(vector <int > &V){
    printf("%ld\n",V.size());
    vector <int >::iterator it;
    for(it=V.begin();it!=V.end();it++){
        printf("%d ",(*it)+1);
    }
}

int main(){
    scanf("%d %d",&N,&M);
    for(int i =0;i<M;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        u--;v--;
        E[{u,v}] = i+1;
        E[{v,u}] = i+1;
        G[u].pb(v);G[v].pb(u);
    }
    init();
    for(int i=0;i<N;i++){
        if(col[i]==2)
            continue;
        dfs(i,i,0);
    }
    vector<pi >:: iterator it;
    printf("%ld\n",bridge.size());
    for(it= bridge.begin();it!=bridge.end();it++){
        int indx = E[(*it)];
        printf("%d ",indx);
    }
    return 0;
}
