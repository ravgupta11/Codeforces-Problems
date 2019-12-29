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
const int MAXN = 3e5+5;
vector<int> G[MAXN];
int tin[MAXN];
int tout[MAXN];
bool vis[MAXN];
int N,M;
int T =0;
void dfs(int v){
    vis[v]= true;
    tin[v] = T++;
    for(int u: G[v]){
        if(vis[u]) continue;
        dfs(u);
    }
    tout[v] = T++;
}
bool in(int u,int v){
    int t1= tin[v]; int t2= tout[v];
    int T1 = tin[u]; int T2 = tout[u];
    //printf("%d: %d %d\n%d: %d %d\n",u,tin[u],tout[u],v,tin[v],tout[v]);
    if(t1>T1&&t2<T2) return true;
    return false;
}

int main(){
    scanf("%d",&N);
    for(int i =1;i<N;i++){
        int u;
        scanf("%d",&u);u--;
        G[u].pb(i);
        G[i].pb(u);
    }
    dfs(0);
    int m;
    scanf("%d",&m);
    for(int i =0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);a--;b--;
       // printf("%d %d\n",a,b);
        if(in(a,b))
            printf("1\n");
        else if(in(b,a))
            printf("2\n");
        else
            printf("3\n");
    }
    return 0;
}
