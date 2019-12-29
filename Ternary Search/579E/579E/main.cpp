#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <iostream>
#define fi first
#define se second
#define ll long long int
#define FOR(i,a,b) for(int i = a;i<b;i++)
#define pb push_back
#define dbl double long
using namespace std;
const int MAXN = 7005;
const dbl EPS = 1e-12;
const dbl INF = 1e9;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<pi, int > pii;

vi ARR,ARR1;int N;
dbl largest1(dbl x,vi A){
    dbl max_h= -0, max_s = -INF;
    FOR(i,0,N){
        max_h += A[i] - x;
        max_s = max(max_s,max_h);
        if(max_h<0) max_h = 0;
    }
    return max_s;
}
dbl largest2(dbl x,vi A){
    dbl max_h= -0, max_s = -INF;
    FOR(i,0,N){
        max_h += A[i] + x;
        max_s = max(max_s,max_h);
        if(max_h<0) max_h = 0;
    }
    return max_s;
}
dbl sum(dbl x){
    dbl s1 = largest1(x,ARR);
    dbl s2 = largest2(x,ARR1);
    s1 = max(s1,-s1);
    s2 = max(s2,-s2);
    //printf("%Lf %Lf %Lf\n",x,s1,s2);
    return max(s1,s2);
}

dbl ternary(dbl lo,dbl hi){
    while(hi-lo>EPS){
        dbl m1 = lo + (hi-lo)/3;
        dbl m2 = hi - (hi-lo)/3;
        if(sum(m1)<sum(m2)) hi = m2;
        else lo= m1;
    }
    return hi;
}
int main(){
    scanf("%d",&N);
    FOR(i,0,N){
        int u;scanf("%d",&u);ARR.pb(u);
    }
    int MIN = 1e4; int MAX = -1e4;
    FOR(i,0,N){
        MIN = min(MIN,ARR[i]);
        MAX = max(MAX,ARR[i]);
    }
    FOR(i,0,N) ARR1.pb(-ARR[i]);
    dbl ans = ternary(MIN,MAX);
    //ans = sum(2);
    ans = sum(ans);
    printf("%Lf",ans);
}
