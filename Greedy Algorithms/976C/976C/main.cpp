#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define ll long long int
#define fi first
#define se second
#define FOR(i,a,b) for(int i =a;i<b;i++)
using namespace std;
typedef vector<pair<int,int> > vpi;
struct it{
    ll u,v;int indx;
};
vector<struct it> A;
int N;
bool comp(struct it a1,struct it a2){
    if(a1.u==a2.u) return a1.v>a2.v;
    return a1.u<a2.u;
}
int main() {
    scanf("%d",&N);
    FOR(i,0,N){
        ll u,v;
        scanf("%lld %lld",&u,&v);
        struct it tmp;
        tmp.u = u; tmp.v = v; tmp.indx = i+1;
        A.pb(tmp);
    }
    sort(A.begin(),A.end(),comp);
    ll maxr = 0;
    int maxi = 0;
    FOR(i,0,N){
        //printf("%d %d\n",A[i].se,maxr);
        if(A[i].v<=maxr){
            printf("%d %d",A[i].indx,maxi);
            return 0;
        }
        if(A[i].v>maxr){
            maxr = A[i].v;
            maxi = A[i].indx;
        }
    }
    printf("-1 -1");
    return 0;
}
