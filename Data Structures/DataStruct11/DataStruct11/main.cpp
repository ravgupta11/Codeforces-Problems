#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define fi first
#define se second
#define ll long long int
using namespace std;
const int MAXN = 2e5+5;
ll ST[4*MAXN];
ll bits[MAXN];

int N;
void build(int id=1,int l =0,int r= N){
    if(r-l==1){
        ST[id] = bits[l] = 0;
        return;
    }
    int L= 2*id,R =2*id+1,M =(l+r)>>1;
    build(L,l,M);
    build(R,M,r);
    ST[id] = ST[L]+ST[R];
}
void update(int pos,ll val,int id = 1,int l =0,int r =N){
    if(r-l==1){
        ST[id] = bits[pos] = val;
        return;
    }
    int L = 2*id,R=2*id+1,M = (l+r)>>1;
    if(pos<M) update(pos,val,L,l,M);
    if(pos>=M) update(pos,val,R,M,r);
    ST[id] = ST[L]+ST[R];
}
ll query(int x,int y,int id=1,int l =0,int r=N){
    if(x==l&&y==r)
        return ST[id];
    int L = 2*id,R = 2*id+1, M =(l+r)>>1;
    if(y<=M) return query(x,y,L,l,M);
    if(x>=M) return query(x,y,R,M,r);
    return query(x,M,L,l,M)+query(M,y,R,M,r);
}


int main() {
        ll A[MAXN];
        ll B[MAXN];
        scanf("%d",&N);
        for(int i =0;i<N;i++)
            scanf("%lld",&A[i]);
        build();
        vector<pair<ll,int> > C;
        for(int i =0;i<N;i++)
            C.push_back({A[i],i});
        sort(C.begin(),C.end());
        for(int i = N-1;i>-1;i--){
            if(C[i].se!=0)
                B[C[i].fi -1]= query(0,C[i].se);
            update(C[i].se,1);
        }
    for(int i=0;i<N;i++)
        printf("%lld ",B[i]);
    return 0;
}
