#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <utility>
#include <math.h>
#include <set>
#include <map>
#define pb push_back
#define no_lazy 0
#define ll long long int
using namespace std;
const int MAXN = 1e5+5;
int N;
ll A[MAXN];

struct node{
    ll sum;
    ll MAX;
    void upd(int l,int r,ll v){
        sum += (r-l)*v;
        MAX = MAX+v;
    }
};

struct node ST[4*MAXN+4];
ll lazy[4*MAXN+4];

struct node merge(struct node left, struct node right){
    struct node tmp;
    tmp.sum = left.sum + right.sum;
    tmp.MAX = max(left.MAX,right.MAX);
    return tmp;
}

void upd(int id, int l, int r,ll u){
    ST[id].upd(l,r,u);
    lazy[id] += u;
}

void shift(int id,int l,int r){
    if(lazy[id]==no_lazy) return;
    int M = (l+r)>>1; int L = 2*id,R = 2*id+1;
    upd(L,l,M,lazy[id]);
    upd(R,M,r,lazy[id]);
    lazy[id] = no_lazy;
}

void update_range(int x,int y,ll val,int id = 1,int l=0,int r=N){
    if(x==l&&y==r){
        upd(id,l,r,val);
        return;
    }
    int M =(l+r)>>1;int L = 2*id,R = 2*id+1;
    shift(id,l,r);
    if(y<=M) update_range(x,y,val,L,l,M);
    else if(x>=M) update_range(x, y, val, R, M, r);
    else{
        update_range(x ,M ,val ,L ,l , M);
        update_range(M, y, val, R, M, r);
    }
    ST[id] = merge(ST[L],ST[R]);
}



void build(int id = 1,int l = 0,int r = N){
    lazy[id] = no_lazy;
    if(r-l==1){
        ST[id].sum=ST[id].MAX= A[l];
        return;
    }
    int M = (l+r)/2; int L = 2*id; int R =2*id+1;
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

int main(){
    int K;
    scanf("%d",&N);
    for(int i =0;i<N;i++)
        scanf("%lld",&A[i]);
    scanf("%d",&K);
    build();
    for(int i =0;i<K;i++){
        char I;int x,y;ll val;
        cin>>I;
        if(I=='a'){
            cin>>x>>y>>val;x--;
            update_range(x, y, val);
        }
        if(I=='m'){
            cin>>x>>y;x--;
            ll ans = query(x,y).MAX;
            printf("%lld ",ans);
        }
    }
}
