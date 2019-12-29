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
#define fi first
#define se second
using namespace std;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector< vector<short> > vii;
typedef pair<int,int> pi;
typedef pair<ll,int> pl;
typedef set< pair<ll,int> > s;
const int MAXN = 3e5+5;
int fup[MAXN];
int dep[MAXN];

struct edge{
    int to,indx;
};
int T = 0;
pair<int,int> E[MAXN];
vector<struct edge> G[MAXN];
vector<int> comp[MAXN];
bool vis[MAXN];
bool vis_edge[MAXN];
stack<int> stck;
int N,M;
void print(vector <int > &V){
    printf("%ld\n",V.size());
    vector <int >::iterator it;
    for(it=V.begin();it!=V.end();it++){
        int u = E[(*it)].fi +1,v = E[(*it)].se +1;
        printf("%d %d\n",u ,v);
    }
}

void dfs(int v,int p,int d){
    vis[v] = true;
    dep[v] = fup[v] = d;
    int child =0;
    for(struct edge e: G[v]){
        int to = e.to;
        if(to==p) continue;
        if(!vis_edge[e.indx]){
            stck.push(e.indx);
            //printf("STORING EDGE %d\n",e.indx);
            vis_edge[e.indx] = true;
        }
        if(vis[to]){
            //printf("%d\n",e.indx);
            fup[v] = min(fup[v],dep[to]);
            continue;
        }
        
        child++;
        long psize = stck.size();
        dfs(to,v,d+1);
        fup[v] =min(fup[v],fup[to]);
        if(fup[to]>=dep[v]){
            while(stck.size() >= psize){
                comp[T].pb(stck.top());
                //printf("REMOVING EDGE %d\n",stck.top());
                stck.pop();
            }
            T++;
        }
    }
}
void init(){
    for(int i = 0;i<N;i++) vis[i]  =false;
    for(int i =0;i<M;i++) vis_edge[i] = false;
}
int main(){
    scanf("%d %d",&N,&M);
    for(int i =0;i<M;i++){
        int u,v;
        scanf("%d %d",&u,&v);u--;v--;
        struct edge tmp1;tmp1.to = v;
        struct edge tmp2;tmp2.to = u;
        tmp1.indx = tmp2.indx = i;
        E[i] = {u,v};
        G[u].pb(tmp1);
        G[v].pb(tmp2);
    }
    init();
    for(int i =0;i<N;i++){
        if(vis[i]) continue;
        dfs(i,-1,0);
    }
    long CPs = T;
    printf("%ld\n",CPs);
    for(int i=0;i<CPs;i++){
        print(comp[i]);
    }
    return 0;
}
