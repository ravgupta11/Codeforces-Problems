#include <vector>
#include <iostream>
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
#define mod1 12345
#define mod2 23456
using namespace std;
const int MAXN = 1e5+5;
struct node{
    ll MAX,MIN;
    /*void upd(int l,int r,ll v){
        sum += (r-l)*v;
    
    }*/
};
int N;

struct node ST[4*MAXN+4];
//int lazy[4*MAXN+4];

struct node merge(struct node left, struct node right){
    struct node tmp;
    tmp.MAX = max(left.MAX,right.MAX);
    tmp.MIN = min(left.MIN,right.MIN);
    return tmp;
}

/*void upd(int id, int l, int r,int u){
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

void update_range(int x,int y,int val,int id = 1,int l=0,int r=N){
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

*/

ll mulmod(ll a, ll b, ll mod)
{
    ll res = 0; // Initialize result
    a = a % mod;
    while (b > 0)
    {
        // If b is odd, add 'a' to result
        if (b % 2 == 1)
            res = (res + a) % mod;
        
        // Multiply 'a' with 2
        a = (a * 2) % mod;
        
        // Divide b by 2
        b /= 2;
    }
    
    // Return result
    return res % mod;
}
void build(int id = 1,int l = 1,int r = MAXN){
    if(r-l==1){
        ST[id].MAX =ST[id].MIN = mulmod(l,l,mod1) + mulmod(mulmod(l,l,mod2),l,mod2);
        return;
    }
    int M = (l+r)>>1; int L = 2*id; int R =2*id+1;
    build(L,l,M);
    build(R,M,r);
    ST[id] = merge(ST[L],ST[R]);
    return ;
}

struct node query(int x,int y,int id=1,int l = 1,int r =MAXN){
    if(l==x&&r==y){
        return ST[id];
    }
    //shift(id,l,r);
    int M = (l+r)>>1;int L =2*id,R=2*id+1;
    if(y<=M) return query(x,y,L,l,M);
    if(x>=M) return query(x,y,R,M,r);
    return merge(query(x,M,L,l,M),query(M,y,R,M,r));
}

void update(int pos,int val,int id = 1,int l =1,int r =MAXN){
    if(r-l==1){
        ST[id].MAX = ST[id].MIN = val;
        return;
    }
    //shift(id,l,r);
    int M =(l+r)>>1; int L = 2*id;int R= 2*id+1;
    if(pos<M) update(pos,val,L,l,M);
    if(M<=pos) update(pos,val,R,M,r);
    ST[id] = merge(ST[L],ST[R]);
}

int main(){
    int K;
    scanf("%d",&K);
    build();
    for(int i =0;i<K;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        if(x>0){
            y++;
            struct node ans = query(x,y);
            //printf("%lld\n",ans.MAX);
            ll diff = ans.MAX - ans.MIN;
            printf("%lld\n",diff);
        }
        else{
            x = abs(x);
            
            update(x,y);
        }
    }
    return 0;
}
