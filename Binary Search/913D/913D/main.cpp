#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long int
#define FOR(i,a,b) for(int i = a;i<(int) b;i++)
#define pb push_back
using namespace std;
typedef vector<struct p> vp;
int N;ll T;
struct p{
    int indx, a,t;
};
vp A,B;

bool by_time(struct p a1,struct p a2){
    return (a1.t<a2.t)?true:false;
}

bool f(int k){
    B.clear();
    int cnt= 0;ll s1 = 0;
    FOR(i, 0, N){
        if(cnt==k) break;
        if(A[i].a<k) continue;
        s1+= A[i].t;
        B.pb(A[i]);
        cnt++;
    }
    if(s1>T||cnt<k) return false;
    return true;
}

int bsearch(int lo,int hi){
    while(lo<=hi){
        int mi = (lo+hi)/2;
        if(f(mi)&&!f(mi+1)) return mi;
        else if(f(mi)&&f(mi+1)) lo = mi +1;
        else hi = mi-1;
    }
    return 0;
}
void print(vp &a){
    vp::iterator it;
    for(it = a.begin();it!=a.end();it++){
        struct p tmp = (*it);
        printf("%d ",tmp.indx);
    }
}
int main() {
    scanf("%d %lld",&N,&T);
    FOR(i,0,N){
        int a,t;
        struct p tmp;
        scanf("%d %d",&a,&t);
        tmp.a = a;
        tmp.t = t;
        tmp.indx = i+1;
        A.pb(tmp);
    }
    sort(A.begin(),A.end(),by_time);
    int ans = bsearch(0,N);
    f(ans);
    if(ans==0){
        printf("0\n0");
    }
    else{
        printf("%d\n%d\n",ans,ans);
        print(B);
    }
    return 0;
}
