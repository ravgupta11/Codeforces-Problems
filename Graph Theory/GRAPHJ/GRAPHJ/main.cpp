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
typedef vector<int> vi;
typedef vector< vector<short> > vii;
typedef pair<int,int> pi;
typedef pair<ll,int> pl;
typedef set< pair<ll,int> > s;
const int MAXN = 2e5+5;
vector<int> G[MAXN];
int N, M;
vector <pi > edge;
int col[MAXN];
int cnt;
void dfs(int u,int p){
    col[u] =1;
    for(int v:G[u]){
        if(col[v]==2||v==p) continue;
        if(col[v]==1){
            cnt++;
            edge.pb({v,u});
        }
        if(col[v]==0){
            dfs(v,u);
        }
    }
    col[u] =2;
}

void init(){
    for(int i=0;i<N;i++) col[i] =0;
}
void print(vector <pi > &V){
    printf("%ld\n",V.size());
    vector <pi >::iterator it;
    for(it=V.begin();it!=V.end();it++){
        printf("%d %d\n",(*it).first+1,(*it).second+1);
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
    for(int i =0;i<N;i++){
        if(col[i]==2) continue;
        if(i!=0) edge.pb({0,i});
        dfs(i,i);
    }
    print(edge);
    return 0;
}
