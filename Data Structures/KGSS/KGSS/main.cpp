#include <iostream>
#include <math.h>
#define ll long long int
#define INF 100005
using namespace std;
struct node{
    ll max;
    ll si;
};
int N;
ll A[100005];
struct node ST[4*100005];

struct node merge(struct node n1,struct node n2){
    struct node tmp;
    tmp.max = max(n1.max,n2.max);
    tmp.max = max(tmp.max,n1.si+n2.si);
    tmp.si = max(n2.si,n1.si);
    return tmp;
}

void build(int id = 1,int l = 0,int r = N){
    if(r-l==1){
        ST[id].max =ST[id].si = A[l];
        return;
    }
    int L = 2*id,R = 2*id +1,M = (l+r)/2;
    build(L,l,M);build(R,M,r);
    ST[id]= merge(ST[L],ST[R]);
}

struct node query(int x, int y, int l =0,int r = N,int id = 1){
    if(x==l&&y==r) return ST[id];
    //printf("%d %d %d %d\n",l,r,x,y);
    int M = (l+r)/2,L = 2*id,R= 2*id+1;
    if(y<=M) return query(x,y,l,M,L);
    if(x>=M) return query(x,y,M,r,R);
    return merge(query(x,M,l,M,L),query(M,y,M,r,R));
}

void update(int x,ll val,int id = 1,int l = 0,int r = N){
    if(r-l==1){
        A[x] = val;
        ST[id].max = ST[id].si = val;
        return;
    }
    int L = 2*id, R=2*id+1, M= (l+r)/2;
    if(x<M) update(x,val,L,l,M);
    else update(x,val,R,M,r);
    ST[id] = merge(ST[L],ST[R]);
    return;
}


int main(){
    scanf("%d",&N);
    for(int i = 0;i<N;i++)
        scanf("%lld",&A[i]);
    build();
    int Q;
    scanf("%d",&Q);
    for(int i = 0;i<Q;i++){
        char d;int x,y;
        cin>>d>>x>>y;
        x--;
        if(d=='U') update(x,y);
        else{
            ll ans =query(x,y).max;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
