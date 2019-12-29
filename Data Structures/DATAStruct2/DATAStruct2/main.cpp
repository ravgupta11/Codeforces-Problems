#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define ll long long
using namespace std;
typedef vector<int> vi;
const int MAXN =1e5+5;
const ll INF =1e12+8;
struct b{
    ll h,w;int i;
};
struct Node{
    ll pre,suf,sum,total;
    int pre_r,suf_l;
};
// O(1)
Node merge(Node L, Node R){
    Node Ret;
    Ret.sum = max(L.sum, R.sum);
    Ret.sum = max(Ret.sum, L.suf + R.pre);
    Ret.suf = max(R.suf, L.suf+R.total);
    if(Ret.suf==R.suf){
        Ret.suf_l = R.suf_l;
    }
    else{
        Ret.suf_l = L.suf_l;
    }
    Ret.pre = max(L.pre, R.pre + L.total);
    if(Ret.pre==L.pre){
        Ret.pre_r = L.pre_r;
    }
    else{
        Ret.pre_r = R.pre_r;
    }
    Ret.total = R.total + L.total;
    return Ret;
}
int N;
Node ST[MAXN*4];
vector<struct b> C;

ll a[MAXN];
bool by_w(struct b a1,struct b a2){
    return a1.w<a2.w;
}
// O(N)
void build(int id=1, int l=0, int r=N){  // we are in node id, which represents segment [l,r)
    if(r-l == 1){
        ST[id].sum =ST[id].pre=ST[id].suf=a[l]=ST[id].total=-INF;
        ST[id].suf_l = ST[id].pre_r = l;
        return;
    }
    int L = 2*id, R = 2*id+1, M=(l+r)/2;
    build(L, l, M);
    build(R, M, r);
    ST[id] = merge(ST[L], ST[R]);
}

// O(log(N))
Node query(int x, int y, int id=1, int l=0, int r=N){
    if(x==l && y==r) return ST[id];
    int L = 2*id, R = 2*id+1, M=(l+r)/2;
    if(M<=x) return query(x,y,R,M,r);
    if(y<=M) return query(x,y,L,l,M);
    return merge(query(x,M,L,l,M),query(M,y,R,M,r));
}

// O(log(N))
void update(int pos, ll val, int id=1, int l=0, int r=N){
    if(r-l==1){
        ST[id].sum =ST[id].pre=ST[id].suf = ST[id].total=a[l]= val;
        return;
    }
    int L = 2*id, R = 2*id+1, M=(l+r)/2;
    if(pos<M){
        update(pos,val,L,l,M);
    }
    else{
        update(pos,val,R,M,r);
    }
    ST[id]= merge(ST[L],ST[R]);
    return;
}

int main() {
    scanf("%d",&N);
    for(int i =0;i<N;i++){
        struct b tmp;
        ll w;
        scanf("%lld",&w);
        tmp.i =i;tmp.w =w;
        C.push_back(tmp);
    }
    sort(C.begin(),C.end(),by_w);
    ll MAX = 0;
    build();
    int max_l =0;
    int max_r =0;
    for(int it =N-1;it>-1;it--){
        struct b tmp =C[it];
        int i = tmp.i;ll w = tmp.w;
        update(i,w);
        ll Wprf=0,Wsuf=0;int Wr=i;int Wl = i;
        if(i>0){
            struct Node tmp =query(0,i);
            Wprf = tmp.suf;
            Wl = tmp.suf_l;
            if(Wprf<=0){
                Wprf = 0;
                Wl = i;
            }
        }
        if(N-i-1!=0){
            struct Node tmp =query(i+1,N);
            Wsuf = tmp.pre;
            Wr = tmp.pre_r;
            if(Wsuf<=0){
                Wsuf = 0;
                Wr = i;
            }
        }
        ll W = (w +Wsuf+Wprf)*w;
        MAX = max(MAX,W);
        if(MAX==W){
            max_l =Wl;
            max_r = Wr;
        }
    }
    printf("%lld\n",MAX);
    printf("%d %d",max_l+1,max_r+1);
    return 0;
}
