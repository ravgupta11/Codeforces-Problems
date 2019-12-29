
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define ll long long
using namespace std;

const ll INF = 1e9+5;
const int MAXN = 1e6+5;
int N, M;
vector< pair<int, ll> > G[MAXN];
vector< pair<int,ll> > G1[MAXN];
bool rel[MAXN];
ll d1[MAXN];
ll d2[MAXN];
void dijkstra(ll d[], vector< pair<int, ll> > G[]){
    for(int it = 0;it<N;it++){
        rel[it] = false;
        d[it] = INF;
    }
    d[0] = 0;
    priority_queue< pair<ll,int> > pq;
    pq.push({-d[0],0});
    while(!pq.empty()){
        int v = pq.top().second; pq.pop();
        rel[v] = true;
        for(pair<int , ll> e:G[v]){
            int u = e.first;
            ll cost = e.second;
            if(rel[u])continue;
            if(d[u]>d[v]+cost){
                d[u] = d[v] + cost;
                pq.push({-d[u],u});
            }
        }
    }
}

int main() {
    int t;
    scanf("%d",&t);
    for(int i = 0;i<t;i++){
        scanf("%d %d",&N,&M);
        for(int it = 0;it<N;it++){
            G[it].clear();
            G1[it].clear();
        }
        for(int it= 0;it<M;it++){
            int u,v; ll c;
            scanf("%d %d %lld" , &u , &v, &c);
            G[u-1].push_back({v-1,c});
            G1[v-1].push_back({u-1,c});
        }
        dijkstra(d1, G);
        dijkstra(d2, G1);
        ll ans = 0;
        for(int it = 0;it<N;it++)
            ans += d1[it] + d2[it];
        printf("%lld\n",ans);
    }
    return 0;
}
