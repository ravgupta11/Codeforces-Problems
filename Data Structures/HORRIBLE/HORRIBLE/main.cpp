#include <iostream>
#include <vector>
#define ll long long int
#define no_lazy 0
using namespace std;
typedef vector<ll> vi;

vi LAZY;
int N;

struct node{
    ll sum;
    void upd(ll v,int l,int r){
        sum += (r-l)*v;
    }
};
vector<struct node> ST;
void init(){
    ST.clear();
    LAZY.clear();
    ST.resize(4*N + 4);
    LAZY.resize(4*N + 4);
}
void upd(int id,ll v,int l,int r){
    LAZY[id] += v;
    ST[id].upd(v,l,r);
}
struct node merge(struct node L, struct node R){
    struct node tmp;
    tmp.sum = L.sum + R.sum;
    return tmp;
}
void shift(int id,int l,int r){
    if(LAZY[id]==no_lazy) return;
    int L = 2*id,R=2*id+1,M=(l+r)>>1;
    upd(L,LAZY[id],l,M);
    upd(R,LAZY[id],M,r);
    LAZY[id] = no_lazy;
}
void update(int x, int y, ll v, int id=1, int l=0, int r=N){
    if(x >= r || l >= y) return;
    if(x <= l && r <= y){
        upd(id, v, l, r);
        return;
    }
    shift(id, l, r);
    int M = (l+r)>>1, L=id<<1, R=2*id+1;
    //printf("%d %lld\n",id,v);
    update(x, y, v, L, l, M);
    update(x, y, v, R, M, r);
    ST[id] = merge(ST[L], ST[R]);
}

void build(int id = 1,int l=0,int r = N){
    if(r-l<2){
        ST[id].sum = 0;
        return;
    }
    //printf("%d %d %d\n",id,l,r);
    int L  =2*id,R=2*id+1,M=(l+r)>>1;
    build(L,l,M);
    build(R,M,r);
    ST[id] = merge(ST[L],ST[R]);
}

struct node query(int x,int y,int id=1,int l=0,int r=N){
    if(x==l&&y==r){
        return ST[id];
    }
    shift(id,l,r);
    int L=id<<1,R=L|1,M=(l+r)>>1;
    if(y<=M) return query(x,y,L,l,M);
    if(x>=M) return query(x,y,R,M,r);
    return merge(query(x,M,L,l,M),query(M,y,R,M,r));
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int Q;
        scanf("%d %d",&N,&Q);
        init();
        build();
        while(Q--){
            int o,l,r;ll v;
            scanf("%d",&o);
            if(o){
                scanf("%d %d",&l,&r);l--;
                ll ans = query(l,r).sum;
                printf("%lld\n",ans);
            }
            else{
                scanf("%d %d %lld",&l,&r,&v);l--;
                update(l,r,v);
            }
        }
    }
    return 0;
}
