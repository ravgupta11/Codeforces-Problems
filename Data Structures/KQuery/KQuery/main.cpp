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

ll bits[MAXN];
ll ST[4*MAXN];

ll merge(ll L, ll R){ return L+R;}

void BUILD(int l = 0, int r = N, int id = 1){
    if(r-l==1){
        ST[id] = bits[l] = 1;
        return;
    }
    int M  = (l+r)>>1, L= 2*id, R = 2*id+1;
    BUILD(l,M,L);
    BUILD(M,r,R);
    ST[id] = merge(ST[L],ST[R]);
}

ll query(int ql, int qr, int id = 1, int l = 0, int r = N){
    if(ql==l && qr==r){
        return ST[id];
    }
    int M = (l+r)>>1, L = 2*id, R = 2*id +1;
    if(qr<=M) return query(ql,qr,L,l,M);
    else if(ql>=M) return query(ql,qr,R,M,r);
    else return merge( query(ql,M,L,l,M), query(M,qr,R,M,r));
}
void update(int pos, ll val, int id = 1, int l =0, int r = N){
    if(r-l==1){
        bits[l] = ST[id] = val;
        return;
    }
    int M = (l+r)>>1, L = 2*id, R = 2*id +1;
    if(pos<M) update(pos,val,L,l,M);
    else if(pos>=M) update(pos,val,R,M,r);
    ST[id] = merge(ST[L], ST[R]);
}

struct que{
    int l,r,n; ll k;
};

vector<struct que> Q;
vector< pair<ll,int> > A;
vector< pair<int, int> > ans;

bool by_k( const struct que &a, const struct que &b){
    return a.k < b.k;
}

void readQ(int q){
    FOR(i, 0 , q){
        struct que tmp;
        ri(tmp.l); ri(tmp.r); rl(tmp.k); tmp.l--; tmp.n = i;
        Q.pb(tmp);
    }
}
void readA(){
    FOR(i, 0, N){
        ll u;rl(u);A.pb({u,i});
    }
}

void solve(int q){
    int it = 0;
    FOR(i, 0, q){
        while(it<N && A[it].fi <= Q[i].k) {
            update(A[it].se, 0);
            it++;
        }
        ans.pb({Q[i].n, query(Q[i].l , Q[i].r)});
    }
}

int main(){
    ri(N);
    readA();
    BUILD();
    int q;
    ri(q);
    readQ(q);
    sort(A.begin(), A.end());
    sort(Q.begin(), Q.end(), by_k);
    solve(q);
    sort(ans.begin(), ans.end());
    FOR(i, 0, q)
        printf("%d\n", ans[i].se);
    return 0;
}

