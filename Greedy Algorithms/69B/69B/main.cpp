#include <iostream>
#include <vector>
#define pb push_back
#define fi first
#define se second
#define ll long long int
#define FOR(i,a,b) for(int i = a;i<b;i++)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<ll> vl;

struct player{
    int l,r,t,c,indx;
};

bool by_time(struct player a1,struct player a2){
    if(a1.t==a2.t) return a1.indx<a2.indx;
    return a1.t<a2.t;
}

vector<struct player> A;
int main() {
    int N,M;
    scanf("%d %d",&N,&M);
    FOR(i,0,M){
        int l1,r1,t1,c1;
        scanf("%d %d %d %d",&l1,&r1,&t1,&c1);
        struct player tmp; tmp.l =l1;tmp.r = r1; tmp.t = t1; tmp.c= c1;tmp.indx = i+1;
        A.pb(tmp);
    }
    sort(A.begin(),A.end(),by_time);
    ll sum = 0;
    FOR(i,1,N+1){
        FOR(j,0,M)
            if(A[j].l<=i && i<=A[j].r){
                sum+= A[j].c;
                break;
            }
    }
    printf("%lld",sum);
    return 0;
}
