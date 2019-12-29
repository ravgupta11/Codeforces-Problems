#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <math.h>
#include <set>
#include <map>
#define pb push_back
#define no_lazy -1
#define ll long long int
const int MAXN = 1e+5;
struct node{
    ll sum;
    void upd(int l,int r,ll v){
        sum += (r-l)*v;
    }
};
int N;

struct node ST[4*MAXN+4];
int lazy[4*MAXN+4];

struct node merge(struct node left, struct node right){
    struct node tmp;
    //
    return tmp;
}

void upd(int id, int l, int r,int u){
    ST[id].upd(l,r,u);
    lazy[id]+= u;
}

void shift(int id,int l,int r){
    if(lazy[id]==no_lazy) return;
    int M = (l+r)>>1; int L = 2*id,R = 2*id+1;
    upd(L,l,M,lazy[id]);
    upd(R,M,r,lazy[id]);
    lazy[id] = no_lazy;
}

void update(int x, int y, ll v, int id=1, int l=0, int r=N){
        if(x >= r || l >= y) return;
        if(x <= l && r <= y){
            upd(id,l, r,v);
            return;
        }
        shift(id, l, r);
        int M = (l+r)>>1, L=id<<1, R=2*id+1;
        //printf("%d %lld\n",id,v);
        update(x, y, v, L, l, M);
        update(x, y, v, R, M, r);
        ST[id] = merge(ST[L], ST[R]);
    }



void build(int id = 1,int l = 0,int r = N){
    if(r-l==1){
        //ST[id]=
        return;
    }
    int M = (l+r)>>1; int L = 2*id; int R =2*id+1;
    build(L,l,M);
    build(R,M,r);
    ST[id] = merge(ST[L],ST[R]);
    return ;
}

struct node query(int x,int y,int id=1,int l = 0,int r =N){
    if(l==x&&r==y){
        return ST[id];
    }
    shift(id,l,r);
    int M = (l+r)>>1;int L =2*id,R=2*id+1;
    if(y<=M) return query(x,y,L,l,M);
    else if(x>=M) return query(x,y,R,M,r);
    return merge(query(x,M,L,l,M),query(M,y,R,M,r));
}

void update(int pos,int val,int id = 1,int l =0,int r =N){
    if(r-l==1){
        //ST[id] =
        return;
    }
    shift(id,l,r);
    int M =(l+r)>>1; int L = 2*id;int R= 2*id+1;
    if(pos<M) update(pos,val,L,l,M);
    if(M<=pos) update(pos,val,R,M,r);
    ST[id] = merge(ST[L],ST[R]);
}
