#include <vector>
#include <iostream>
#include <queue>
#define ll long long int
#define se second
#define fi first
#define pb push_back
using namespace std;
ll L;int N,M,src,dest,quest;
const int MAXN = 1000 +5;
const ll INF = 1e9+9;
struct edge{
    int from, to;ll w;int flag;
    int other(int x){
        if(x==from) return to;
        return from;
    }
};
vector<edge> Elist;
vector<int> G[MAXN];
bool rel[MAXN];
ll d[MAXN];

void dijkstra(int s){
    priority_queue< pair<ll,int> > pq;
    for(int i =0;i<N;i++){
        rel[i] = false;
        d[i] = INF;
    }
    d[s] = 0;
    pq.push({0,s});
    while(!pq.empty()){
        int from = pq.top().se; pq.pop();
        if(from==dest) break;
        if(rel[from]) continue;
        rel[from] = true;
        for(int i: G[from]){
            struct edge e = Elist[i];
            int to = e.other(from); ll w = e.w;
            if(d[from] + w<d[to]){
                d[to] = d[from] + w;
                pq.push({-d[to],to});
            }
        }
    }
}
void update(ll w,int l = M){
    int q = 0;
    for(int i =0;i<M;i++){
        struct edge e = Elist[i];
        ll wi = e.w;
        if(e.flag&& q<l){
            q++;
            wi = w;
        }
        else if(e.flag){
            wi = w-1;
        }
        e.w = wi;
        Elist[i] =e;
    }
}

void bsearch_mod(ll lo,ll hi){
    ll W = lo;
    while(lo<hi){
        ll mi = (lo+hi)/2;
        W =mi;
        update(mi);
        dijkstra(src);
        if(d[dest]==L) return;
        if(d[dest]<L)
            lo = mi;
        else
            hi =mi;
    }
    
    lo = 1; hi = quest;
    while(lo<hi){
        ll mi = (lo+hi)/2;
        update(W+1,(int)mi);
        dijkstra(src);
        if(d[dest]==L) return ;
        if(d[dest]<L)
            lo = mi;
        else
            hi =mi;
    }
}
int main() {
    scanf("%d %d %lld %d %d",&N,&M,&L,&src,&dest);
    for(int i = 0;i<M;i++){
        int u,v;ll w; int flag =0;
        scanf("%d %d %lld",&u,&v,&w);
        if(w==0) {
            quest++;
            flag = 1;
        }
        struct edge e;
        e.from = u;e.to = v; e.w = w;e.flag  = flag;
        Elist.pb(e);
        G[u].pb(i);G[v].pb(i);
    }
    update(1);
    dijkstra(src);
    if(d[dest]>L){
        printf("NO\n");
        return 0;
    }
    update(INF);
    dijkstra(src);
    if(d[dest]<L){
        printf("NO\n");
        return 0;
    }
    bsearch_mod(1,INF);
    printf("YES\n");
    for(int it = 0;it<M;it++){
        struct edge e = Elist[it];
        printf("%d %d %lld\n",e.from,e.to,e.w);
    }
    return 0;
}
