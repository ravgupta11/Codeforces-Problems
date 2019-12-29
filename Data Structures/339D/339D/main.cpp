#include <iostream>
#include <vector>
#define fi first
#define se second
#include <algorithm>
#include <utility>

#define ll long long int
#define dbl double long
#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORR(i, a, b) for(int i = a; i > b; i--)
#define ri(x) scanf("%d",&x)
#define rii(x,xx) scanf("%d %d", &x, &xx)
#define rl(x) scanf("%lld", &x);
using namespace std;
const int MAXN = 3e5+5;
int N;

ll A[MAXN];
ll ST[4*MAXN];

ll merge(ll L, ll R, int k){
    if(k)
        return L|R;
    else
        return L^R;
}

void BUILD(int x, int l = 0, int r = 1<<N, int id = 1){
    if(r-l==1){
        ST[id] = A[l];
        return;
    }
    int M  = (l+r)>>1, L= 2*id, R = 2*id+1;
    BUILD(1-x, l, M, L);
    BUILD(1-x, M, r, R);
    ST[id] = merge(ST[L],ST[R],x);
}

ll query(int x, int ql, int qr, int id = 1, int l = 0, int r = 1<<N){
    if(ql==l && qr==r){
        return ST[id];
    }
    int M = (l+r)>>1, L = 2*id, R = 2*id +1;
    if(qr<=M) return query(1-x, ql,qr,L,l,M);
    else if(ql>=M) return query(1-x, ql,qr,R,M,r);
    else return merge(query(1-x, ql,M,L,l,M), query(1-x, M,qr,R,M,r), x);
}
void update(int x, int pos, ll val, int id = 1, int l =0, int r = 1<<N){
    if(r-l==1){
        A[l] = ST[id] = val;
        return;
    }
    int M = (l+r)>>1, L = 2*id, R = 2*id +1;
    if(pos<M) update(1-x, pos,val,L,l,M);
    else if(pos>=M) update(1-x, pos,val,R,M,r);
    ST[id] = merge(ST[L], ST[R], x);
}

int main(){
    ri(N);
    int Q;
    ri(Q);
    FOR(i, 0, 1<<N)
        rl(A[i]);
    BUILD(N%2);
    //printf("%lld\n",query(N%2,0,1<<N));
    FOR(i, 0, Q){
        int p; ll b;
        ri(p); rl(b);
        p--;
        update(N%2, p, b);
        ll v = query(N%2, 0, 1<<N);
        printf("%lld\n",v);
    }
    return 0;
}
