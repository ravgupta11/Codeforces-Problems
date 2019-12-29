#include <vector>
#include <algorithm>
#include <iostream>
#define ll long long
#define pb push_back
#define FOR(i,f,t) for(int i = f;i<(int)t;i++)
using namespace std;
typedef vector<struct it> vs;
struct it{
    ll in,ci;
};
vs A,B;
int N;ll S;

bool by_cost(struct it a1,struct it a2){
    return (a1.ci<a2.ci)?true:false;
}

ll calc(int K){
    B.clear();
    ll sum = 0;
    FOR(i,0,N){
        struct it tmp;
        tmp.ci = A[i].ci+ K*A[i].in;
        tmp.in = A[i].in;
        B.pb(tmp);
    }
    sort(B.begin(),B.end(),by_cost);
    FOR(i,0,K) sum += B[i].ci;
    return sum;
}

int bsearch(int lo,int hi){
    while(lo<=hi){
        int mi = (lo+hi)/2;
        if(calc(mi)<=S&&calc(mi+1)>S) return mi;
        else if(calc(mi)<=S && calc(mi+1)<=S) lo = mi+1;
        else hi = mi -1;
    }
    return 0;
}

int main() {
    
    scanf("%d %lld",&N,&S);
    FOR(i,0,N){
        ll a;
        scanf("%lld",&a);
        struct it tmp;
        tmp.in = i+1;
        tmp.ci= a;
        A.pb(tmp);
    }
    ll s1 = 0;
    FOR(i,0,N) s1+= (A[i].ci + A[i].in *N);
    //printf("%lld\n",s1);
    if(s1<=S)
        printf("%d %lld\n",N,s1);
    else{
        int ans = bsearch(0,N-1);
        ll s2 = calc(ans);
        printf("%d %lld\n",ans,s2);
    }
    return 0;
}
