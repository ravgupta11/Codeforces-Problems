#include <iostream>
#include <vector>
typedef long long int ll;
using namespace std;
const int MAXN = 3e4+5;
int N;
ll A[MAXN];

struct node{
    ll arr[MAXN];
    int l;
};
struct node ST[4*MAXN];

ll bs(ll a[],int low,int high,ll k){
    if(high-low==0){
        if(a[low]<=k) return low;
        else return low-1;
    }
    if(high-low==1){
        if(a[high]<=k) return high;
        if(a[low]<=k) return low;
        else return low-1;
    }
    int mid = (low+high)>>1;
    if(a[mid]<=k&&a[mid+1]>k) return mid+1;
    if(a[mid]>k&&a[mid+1]>k) return bs(a,low,mid-1,k);
    return bs(a,mid+1,high,k);
}

struct node merge(struct node a,struct node b){
    struct node tmp;
    int i,j,k;
    i =j =k =0;
    while(i<a.l&&j<b.l){
        if(a.arr[i]<b.arr[j])
            tmp.arr[k++] = a.arr[i++];
            else
                tmp.arr[k++] = b.arr[j++];
                }
    while(i<a.l)
        tmp.arr[k++] = a.arr[i++];
        while(j<b.l)
            tmp.arr[k++] = b.arr[j++];
            tmp.l = a.l+b.l;
            return tmp;
}
void Build(int id =1,int i=0,int j =N){
    if(j-i==1){
        ST[id].l = 1;
        ST[id].arr[0]=A[i];
        return;
    }
    int L =2*id;
    int R = 2*id+1;
    int M= (i+j)>>1;
    Build(L,i,M);
    Build(R,M,j);
    ST[id] = merge(ST[L],ST[R]);
}

ll query(int x,int y,ll k,int id=1, int i=0, int j=N){
    if(x==i&&y==j){
        ll q =bs(ST[id].arr,0,ST[id].l-1,k);
        if(q==-1) return (j-i);
        return j-(i+q)-1;
    }
    int L = 2*id,R = 2*id+1,M = (i+j)>>1;
    if(y<=M) return query(x,y,k,L,i,M);
    if(x>=M) return query(x,y,k,R,M,j);
    return query(x,M,k,L,i,M)+query(M,y,k,R,M,j);
}
int main() {
    scanf("%d",&N);
    for(int i = 0;i<N;i++) scanf("%lld",&A[i]);
    int Q;
    scanf("%d",&Q);
    Build();
    for(int i =0;i<Q;i++){
        int l,r;ll k;
        scanf("%d %d %lld",&l,&r,&k);
        l--;
        printf("%lld\n",query(l,r,k));
    }
    return 0;
}
