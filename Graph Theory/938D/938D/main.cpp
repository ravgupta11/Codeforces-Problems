#include <iostream>
#include <set>
#include <utility>
#include <vector>
#define ll long long int
using namespace std;
const int MAXN =3*1e5+5;
ll a[MAXN];
vector<pair<int,ll> > G[MAXN];
int N,M;
ll d[MAXN];

void dijkstra(){
    set<pair<ll,int> > q;
    for(int i =1;i<=N;i++){
        d[i] = a[i];
        q.insert({d[i],i});
    }
    while(!q.empty()){
        set<pair<ll,int> >::iterator it;
        it = q.begin();
        int v =(it)->second;
        q.erase(it);
        for(pair<int,ll> e:G[v]){
            ll w = e.second;
            int u = e.first;
            if(d[u]>w+d[v]){
                q.erase({d[u],u});
                d[u] = w+d[v];
                q.insert({d[u],u});
            }
        }
    }
}

int main(){
    scanf("%d %d",&N,&M);
    for(int i =0;i<M;i++){
        int u,v;ll w;
        scanf("%d %d %lld",&u,&v,&w);
        G[u].push_back({v,2*w});
        G[v].push_back({u,2*w});
    }
    for(int i =1;i<=N;i++) scanf("%lld",&a[i]);
    dijkstra();
    for(int i =1;i<=N;i++) printf("%lld ",d[i]);
    return 0;
}
