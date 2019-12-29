#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <utility>
#include <set>
#include <queue>
#define ll long long int
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i,a,b) for(int i = a;i>b;i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;

typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii > vpi;
int N, M; int Set =0,Set2 = 0;
vpi QP, PQ;
vi com1[12], com2[12];
bool comp(pii a, pii b){
    if((a.fi == b.fi && a.se == b.se) ||(a.fi == b.se && a.se == b.fi)) return 0;
    if(a.fi == b.fi) return a.fi;
    if(a.se == b.se) return b.se;
    if(a.fi == b.se) return a.fi;
    if(a.se == b.fi) return a.se;
    return 0;
}

int main(){
    ri(N); ri(M);
    FOR(i, 0, N){
        int u,v;
        ri(u); ri(v);
        PQ.pb({u,v});
    }
    FOR(i, 0, M){
        int u,v;
        ri(u); ri(v);
        QP.pb({u,v});
    }
    int cnt = 0,com = -1;
    FOR(i, 0, N){
        int f1 = 0, f2 = 0;
        FOR(j, 0, M)
            if(comp(PQ[i],QP[j])){
                Set = 1<<i|Set;
                if(PQ[i].fi == comp(PQ[i],QP[j])) f1 = 0;
                if(PQ[i].se == comp(PQ[i],QP[j])) f2 = 0;
                Set2 = 1<<j|Set2;
                cnt++; com = comp(PQ[i], QP[j]);
            }
        if(f1 && f2) {printf("-1"); return 0;}
    }
    FOR(i, 0, M){
        int f1 = 0, f2 = 0;
        FOR(j, 0, N)
        if(comp(QP[i],PQ[j])){
            if(QP[i].fi == comp(PQ[j],QP[i])) f1 = 0;
            if(QP[i].se == comp(PQ[j],QP[i])) f2 = 0;
        }
        if(f1 && f2) {printf("-1"); return 0;}
    }
    
    if(cnt==1){
        printf("%d",com);
        return 0;
    }
    printf("0");
    return 0;
}
