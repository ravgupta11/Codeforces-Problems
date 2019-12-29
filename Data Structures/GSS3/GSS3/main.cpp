#include <iostream>
#include <math.h>
#define INF 100005
using namespace std;
struct node{
    int k;
};
int N;
int A[100005];
struct node ST[4*100005];

struct node merge(struct node n1,struct node n2){
    struct node tmp;
    tmp.max = max(n1.max,n2.max);
    tmp.max = max(tmp.max,n1.suf+n2.pref);
    tmp.suf = max(n2.suf,n1.suf+n2.total);
    tmp.pref = max(n1.total+n2.pref,n1.pref);
    tmp.total = n1.total + n2.total;
    return tmp;
}

void build(int id = 1,int l = 0,int r = N){
    if(r-l==1){
        if(f2(l)==
        return;
    }
    int L = 2*id,R = 2*id +1,M = (l+r)/2;
    build(L,l,M);build(R,M,r);
    ST[id]= merge(ST[L],ST[R]);
}

struct node query(int x, int y, int l =0,int r = N,int id = 1){
    if(x==l&&y==r) return ST[id];
    int M = (l+r)/2,L = 2*id,R= 2*id+1;
    if(y<=M) return query(x,y,l,M,L);
        if(x>=M) return query(x,y,M,r,R);
            return merge(query(x,M,l,M,L),query(M,y,M,r,R));
            
            }


int main(){
    scanf("%d",&N);
    for(int i = 0;i<N;i++)
        scanf("%d",&A[i]);
    build();
    int Q;
    scanf("%d",&Q);
    for(int i = 0;i<Q;i++){
        int d,x,y;
        scanf("%d %d %d",&d,&x,&y);x--;
        if(d==0) update(x,y);
        else{
            int ans =query(x,y).max;
            printf("%d\n",ans);
        }
    }
    return 0;
}
