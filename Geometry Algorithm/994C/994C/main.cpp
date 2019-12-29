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
#define y second
#define dbl long double
#define FOR(i, a, b) for(int i =a;i<b;i++)
#define rp(X) scanf("%Lf %Lf", &X.x, &X.y)
using namespace std;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<dbl,dbl> pt;
typedef pair<ll,ll> pl;
typedef set< pair<ll,int> > s;

struct Bl{
    pt X1, X2, X3, X4;
};

struct L{
    dbl a,b,c;
};
const dbl EPS =1e-9;

inline int cmp(dbl a,dbl b){
    return a+EPS<b?-1:b+EPS<a?1:0;
}
pt vect(pt a,pt b){
    return {b.x - a.x,b.y - a.y};
}
bool zero(dbl x){
    return cmp(x,0)==0;
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

int sign( dbl a){
    if(a>=0) return 1;
    return -1;
}
pt rotate(pt p,dbl a){
    return {cos(a)*p.x-sin(a)*p.y, cos(a)*p.y+sin(a)*p.x};
}

dbl dot(pt A,pt B){
    return A.x*B.x + A.y*B.y;
}

dbl cross(pt A,pt B){
    return A.x*B.y - A.y*B.x;
}
dbl distPL(pt X,L L1){
    dbl root = sqrt(L1.a*L1.a +L1.b*L1.b);
    dbl x1 = X.x,y1=X.y;
    dbl A = L1.a,B= L1.b,C = L1.c;
    dbl ans =((A*x1+B*y1+C)/root);
    return ans>0?ans:-ans;
}

dbl distPP(pt a,pt b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y - b.y));
}

dbl det(L l1, L l2){
    return l1.a*l2.b - l1.b*l2.a;
}

struct L genL(dbl x1,dbl x2,dbl y1,dbl y2){
    struct L L1;
    L1.a = y1-y2;
    L1.b = x2- x1;
    L1.c = -1*(L1.a*x1 + L1.b*y1);
    return L1;
}

dbl det1(dbl a,dbl b,dbl c,dbl d){
    return a*d - b*c;
}

pt intersect(struct L L1,struct L L2){//given they are not parallel
    pt p;
    p.x = -1*(det1(L1.c,L1.b,L2.c,L2.b)/det1(L1.a,L1.b,L2.a,L2.b));
    p.y = -1*(det1(L1.a,L1.c,L2.a,L2.c)/det1(L1.a,L1.b,L2.a,L2.b));
    return p;
}
bool segintersect(pt p1, pt q1, pt p2 , pt q2){
    if(max(p1.x, q1.x)< min(p2.x, q2.x)) return false;
    if(max(p2.x, q2.x)< min(p1.x, q1.x)) return false;
    if(max(p1.y,q1.y) < min(p2.y, q2.y)) return false;
    if(max(p2.y, q2.y) < min(p1.y, q1.y)) return false;
    if(cross(vect(p1,q1),vect(p1,p2))*cross(vect(p1,q1),vect(p1,q2))>0 || cross(vect(p2,q2),vect(p2,p1))*cross(vect(p2,q2),vect(p2,q1))>0) return false;
    return true;
}
struct seg{
    pt p;
    pt q;
};

int main(){
    pt Po[8];
    FOR(i, 0, 8)
    rp(Po[i]);
    struct seg box1[4];
    struct seg box2[4];
    
    FOR(i, 0, 4){
        struct seg tmp;
        tmp.p = Po[i];
        tmp.q = Po[(i+1)%4];
        box1[i] = tmp;
    }
    FOR(i, 0, 4){
        struct seg tmp;
        tmp.p = Po[i+4];
        tmp.q = Po[(i+1)%4 +4];
        box2[i] = tmp;
    }
    FOR(i, 0, 4) FOR(j, 0, 4){
        if(segintersect(box1[i].p, box1[i].q, box2[j].p, box2[j].q)){
            printf("YES");
            return 0;
        }
    }
    bool c1 = true, c2 = true;
    FOR(i, 0, 4){
        int pro  = sign(cross(vect(Po[4], Po[5]), vect(Po[4], Po[i])));
        FOR(j, 1, 4){
            int t =sign(cross(vect(Po[j+4], Po[(j+1)%4 +4]), vect(Po[j+4], Po[i])));
            if((pro < 0 && t>0) || (pro > 0 && t < 0)){
                c1 = false; break;
            }
        }
        if(!c1) break;
    }
    FOR(i, 0, 4){
        int pro  = sign(cross(vect(Po[0], Po[1]), vect(Po[0], Po[i+4])));
        //printf("%Lf %Lf\n",Po[i+4].x,Po[i+4].y);
        FOR(j, 1, 4){
            int t = sign(cross(vect(Po[j], Po[(j+1)%4]), vect(Po[j], Po[i+4])));
            if((pro < 0 && t>0) || (pro > 0 && t < 0)){
                c2 = false;
                break;
            }
        }
        if(!c2) break;
    }
    //printf("%d %d\n",c1,c2);
    if(c1||c2) printf("YES");
    else printf("NO");
    return 0;
}

