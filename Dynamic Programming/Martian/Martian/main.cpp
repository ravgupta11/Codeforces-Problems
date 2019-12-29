#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <math.h>
#include <set>
#define pb push_back
#define ll long long int
#define fi first
#define se second
using namespace std;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,int> pl;
typedef set< pair<ll,int> > s;
typedef pair<pair<int,int>, pair<int,int> > pt;
const ll INF = 1e10+9;
const int MAXN = 1e5+5;
ll dp[MAXN];
struct edge{
    int to;ll cost;
};
int N;
int H;
vector<struct edge> G[MAXN];

ll f(int u,ll b){
    if(dp[u]!=-1) return dp[u];
    ll a=0;
    bool c = false;
    for(struct edge i :G[u]){
        c = true;
        int v = i.to;ll cv = i.cost;
        a+= f(v,cv);
    }
    ll MIN = b;
    if(c)
        MIN = min(MIN,a);
    return dp[u] = MIN;
}
void init(){
    for(int i =0;i<N;i++){
            dp[i] = -1;
    }
}

int main(){
    scanf("%d",&N);
    for(int i =0;i<N-1;i++){
        int v;ll c;
        scanf("%d %lld",&v,&c);v--;
        struct edge e; e.to =i+1; e.cost = c;
        G[v].pb(e);
    }
    init();
    double ans =0;
    for(struct edge I:G[0]){
        int v = I.to; ll ct = I.cost;
        ans+= f(v,ct);
    }
    printf("%.2lf",ans);
    return 0;
}
