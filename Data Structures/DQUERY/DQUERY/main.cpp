#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#define fi first
#define se second
#define ll long long int
using namespace std;
int N;
const int MAXN =4e5+5;
ll ST[4*MAXN];
ll B[MAXN];
ll C[MAXN];
void build(int id =1,int l =0,int r = N){
    if(r-l==1){
        ST[id] =1;
        return;
    }
    int L = 2*id,R = 2*id+1,M =(l+r)>>1;
    build(L,l,M);
    build(R,M,r);
    ST[id] = ST[L]+ST[R];
}
ll query(int x,int y,int id =1,int l=0,int r=N){
    if(x==l&&y==r)
        return ST[id];
    int L =2*id,R=2*id+1,M = (l+r)>>1;
    if(y<=M) return query(x,y,L,l,M);
    if(x>=M) return query(x,y,R,M,r);
    return query(x,M,L,l,M)+query(M,y,R,M,r);
}
void update(int pos,ll val,int id = 1,int l =0,int r =N){
    if(r-l==1){
        ST[id] = val;
        return;
    }
    int L = 2*id,R=2*id+1,M = (l+r)>>1;
    if(pos<M) update(pos,val,L,l,M);
    if(pos>=M) update(pos,val,R,M,r);
    ST[id] = ST[L]+ST[R];
}

void compress(ll A[]){
    vector<ll> cmps;
    for(int i =0;i<N;i++)
        cmps.push_back(A[i]);
    sort(cmps.begin(),cmps.end());
    cmps.resize(distance(cmps.begin(),unique(cmps.begin(),cmps.end())));
    for(int i =0;i<N;i++)
        B[i] = distance(cmps.begin(),lower_bound(cmps.begin(),cmps.end(),A[i]));
}
struct query{
    int u,v,x,no;
};
bool by_x(const struct query a,const struct query b){
    return a.x<b.x;
}
int main() {
    scanf("%d",&N);
    ll A[MAXN];
    int hash[1000006];
    memset(hash,0,1000006*sizeof(hash[0]));
    for(int i =0;i<N;i++)
        scanf("%lld",&A[i]);
    compress(A);
    int Q;
    scanf("%d",&Q);
    vector<struct query> que;
    for(int i =0;i<Q;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        u--;
        struct query tmp;
        tmp.u = u;tmp.v=v;tmp.x=v-u;tmp.no = i;
        que.push_back(tmp);
    }
    build();
    sort(que.begin(),que.end(),by_x);
    int last_i=N,last_j=-1;
    for(int i =0;i<Q;i++){
        
        struct query tmp = que[i];
        int i1 = tmp.u,j1 =tmp.v-1, n =tmp.no;
        while(j1>last_j&&j1>=i1){
            //printf("%d %d\n",j1,hash[B[j1]]);
            if(!hash[B[j1]])
                hash[B[j1]] = 1;
            else
                update(j1,0);
            j1--;
        }
        while(i1<last_i&&i1<=j1){
            //printf("%d %d\n",i1,hash[B[i1]]);
            if(!hash[B[i1]])
                hash[B[i1]] =1;
            else
                update(i1,0);
            i1++;
        }
        last_i = min(last_i,tmp.u);last_j = max(last_i,tmp.v-1);
        C[n] = query(tmp.u,tmp.v);
    }
    for(int it =0;it<Q;it++)
        printf("%lld\n",C[it]);
    return 0;
}
