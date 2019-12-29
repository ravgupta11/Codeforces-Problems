#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define ll long long
using namespace std;
const int MAXN = 1e5+5;
const ll INF = 9e9 +5;
ll d[MAXN];
ll d1[MAXN];
vector< pair<int, ll> > G[MAXN];
vector< pair<int, ll> > G1[MAXN];
int N, M;
void dijkstra(int root){
    bool rel[MAXN];
    for(int it = 0;it<N;it++){d[it]=INF;rel[it] = false;}
    priority_queue< pair<ll,int> > pq;
    d[root]=0;
    pq.push({-d[root],root});
    while(!pq.empty()){
        int v = pq.top().second; pq.pop();
        if(rel[v])continue;
        rel[v] = true;
        for(pair<int,ll> e:G[v]){
            int u = e.first;
            ll cost = e.second;
            if(d[u]>d[v]+cost){
                d[u] = d[v]+ cost;
                pq.push({-d[u],u});
            }
        }
    }
}
void dijkstra1(int root){
    bool rel[MAXN];
    for(int it = 0;it<N;it++){d1[it]=INF;rel[it] = false;}
    priority_queue< pair<ll,int> > pq;
    d1[root]=0;
    pq.push({-d1[root],root});
    while(!pq.empty()){
        int v = pq.top().second; pq.pop();
        if(rel[v])continue;
        rel[v] = true;
        for(pair<int,ll> e:G1[v]){
            int u = e.first;
            ll cost = e.second;
            if(d1[u]>d1[v]+cost){
                d1[u] = d1[v]+ cost;
                pq.push({-d1[u],u});
            }
        }
    }
}

int main() {
    while(scanf("%d %d",&N,&M),N!=0){
        int S, D;
        scanf("%d %d",&S,&D);
        for(int it = 0;it<N;it++){
            G[it].clear();
            G1[it].clear();
        }
        for(int it=0;it<M;it++){
            int u,v;
            ll cost;
            scanf("%d %d %lld",&u,&v,&cost);
            G[u].push_back({v,cost});
            G1[v].push_back({u,cost});
        }
        dijkstra(S);
        dijkstra1(D);
        for(int it = 0;it<N;it++){
            for(pair<int,ll> &p:G[it])
            {
                ll cost = p.second;
                int u = p.first;
                if(d[D]==d[it] + cost + d1[u]){
                    p.second = INF;
                }
            }
        }
        dijkstra(S);
        if(d[D]==INF)
            printf("-1\n");
        else
            printf("%lld\n",d[D]);
    }
    return 0;
}
