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
vector< int > points;
int dep[MAXN];
int fup[MAXN];
bool vis[MAXN];
int N,M;
bool ad[MAXN];
void dfs(int u,int p,int d){
    vis[u] = true;
    dep[u] = fup[u] =d;
    int child =0;
    for(int v:G[u]){
        if(v==p) continue;
        if(vis[v]){
            fup[u] =min(fup[u],dep[v]);
            continue;
        }
        dfs(v,u,d+1);
        fup[u] =min(fup[u],fup[v]);
        child++;
        if(fup[v]>=dep[u]&&p!=-1){
            if (ad[u]) continue;
            ad[u]= true;
            points.pb(u);
        }
    }
    if((p==-1 && child>1))
        points.pb(u);
}
void init(){
    for(int i =0;i<N;i++){
        vis[i] =false;
        ad[i] = false;
    }
}
void print(vector <int > &V){
    printf("%ld\n",V.size());
    //unique(V.begin(),V.end());
    vector <int >::iterator it;
    for(it=V.begin();it!=V.end();it++){
        printf("%d ",(*it)+1);
    }
}
int main(){
    scanf("%d %d",&N,&M);
    for(int i=0;i<M;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        u--;v--;
        G[u].pb(v);
        G[v].pb(u);
    }
    init();
    for(int i=0;i<N;i++){
        if(vis[i]) continue;
        dfs(i,-1,0);
    }
    print(points);
    return 0;
}
