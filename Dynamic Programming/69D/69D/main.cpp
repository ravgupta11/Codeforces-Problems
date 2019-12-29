#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <math.h>
#include <algorithm>
#include <set>
#define pb push_back
#define ll long long int
#define x first
#define FOR(i,a,b) for(int i = a;i<b;i++)
#define y second
#define dbl long double
using namespace std;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<dbl,dbl> pt;
typedef pair<ll,ll> pl;
typedef set< pair<ll,int> > s;

struct L{
    dbl a,b,c;
};
pt vect(pt a,pt b){
    return {b.x - a.x,b.y - a.y};
}
const dbl EPS =1e-9;
inline int cmp(dbl a,dbl b){
    return a+EPS<b?-1:b+EPS<a?1:0;
}
dbl len2(pt p){
    return p.x*p.x + p.y*p.y;
}

dbl len(pt p){
    return sqrt(len2(p));
}

pt norm(pt p){
    dbl lenp = len(p);
    return {p.x/lenp,p.y/lenp};
}
bool opp(pt A,pt B, L L1){
    dbl t1 = A.x*L1.a + A.y*L1.b + L1.c;
    dbl t2 = B.x*L1.a + B.y*L1.b + L1.c;
    if((t1<0 && t2<0) || (t1>0 && t2>0)) return false;
    return true;
}
dbl dist(pt X, L L1){
    dbl d = L1.a*X.x + L1.b*X.y + L1.c;
    d = d/(sqrt(L1.a*L1.a + L1.b*L1.b));
    return d;
}
pt ref(pt X, L L1){
    pt A1 = norm({-1,1});
    pt A2 = norm({1,-1});
    pt R1,R2;
    dbl d1 = 2*dist(X,L1);
    R1.x = X.x + d1*A1.x;
    R1.y = X.y + d1*A1.y;
    R2.x = X.x + d1*A2.x;
    R2.y = X.y + d1*A2.y;
    if(opp(R1,X,L1)){
        //printf("A1.x = %Lf A1.y = %Lf, R1.x= %Lf R1.y=%Lf\n", A1.x,A1.y,R1.x, R1.y);
        return R1;
    }
    //printf("A1.x = %Lf A1.y = %Lf, R1.x= %Lf R1.y=%Lf\n", A2.x,A2.y,R2.x, R2.y);
    return R2;
}
const int MAXN = 21;
const int MAXP = (1<<MAXN);
pt vectors[MAXN+1];
int dp[501][501][2][2][2];
int N;dbl d;
L G;

void init(){
    G.a = -1; G.b = 1; G.c = 0;
    FOR(i,0,501) FOR(i1,0,501) FOR(j,0,2) FOR(k,0,2) FOR(l,0,2) dp[i][i1][j][k][l]=-1;
}


bool DP(int par,int r1,int r2,pt X){
    if (((par==0 && r1==0) || (par==1 && r2==0))) return false;
    int a = (int) X.x +250; int b = (int) X.y +250;
    if(dp[a][b][par][r1][r2] > -1 ) return dp[a][b][par][r1][r2];
    bool c = false;
    FOR(i,0,N){
            pt X2; X2.x = X.x + vectors[i].x; X2.y = X.y + vectors[i].y;
            if(cmp(len(X2),(dbl)d)<=0)
                c = c|| !DP(1-par,r1,r2,X2);
            if(c) break;
    }
    if(c) return dp[a][b][par][r1][r2] = c;
    pt R = ref(X,G);
    if(par==0 && r1==1)
        if(cmp(len(R),(dbl)d)<=0)
           c = (c|| !DP(1-par,1-r1,r2,R));
    if(par==1 && r2==1)
        if(cmp(len(R),(dbl)d)<=0)
            c = (c|| !DP(1-par,r1,1-r2,R));
    return dp[a][b][par][r1][r2] = c;
}

int main(){
    int X,Y;
    scanf("%d %d %d %Lf",&X,&Y,&N,&d);
    pt AA = {X,Y};
    init();
    FOR(i,0,N) scanf("%Lf %Lf",&vectors[i].x,&vectors[i].y);
    int ans = DP(0,1,1,AA);
    if(ans == 1) printf("Anton");
    else printf("Dasha");
    return 0;
}

