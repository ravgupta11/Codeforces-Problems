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
const dbl EPS =1e-6;

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
struct Bl construct(pt p, pt q){
    Bl tmp;
    tmp.X1 = p;
    tmp.X2 = {min(p.x,q.x),max(p.y,p.y)};
    tmp.X3 = q;
    tmp.X4 = {max(p.x,q.x),min(p.y,q.y)};
    return tmp;
}
bool blockinter(pt p1,pt p2,pt q1,pt q2){
    if (max(p2.x, q2.x) < min(p1.x, q1.x)) return false;
    if (max(p1.x, q1.x) < min(p2.x, q2.x)) return false;
    if (max(p2.y, q2.y) < min(p1.y, q1.y)) return false;
    if (max(p1.y, q1.y) < min(p2.y, q2.y)) return false;
    return true;
}
bool in(pt A,pt B,pt C){
    if(dot(vect(A,B),vect(A,C))*dot(vect(B,A),vect(B,C))>=0) return true;
    return false;
}
int main(){
    dbl ax,ay,bx,by,cx,cy,dx,dy;
    scanf("%Lf %Lf %Lf %Lf %Lf %Lf",&ax,&ay,&bx,&by,&cx,&cy);
    scanf("%Lf %Lf",&dx,&dy);
    pt A = {ax,ay};pt B = {bx,by},C = {cx,cy},D = {dx,dy};
    pt AB = vect(A,B);
    pt AC = vect(A,C);
    pt AD = vect(A,D);
    pt CA = vect(C,A);
    pt CB = vect(C,B);
    pt CD = vect(C,D);
    if(!blockinter(A,B,C,D)){
        printf("-1");
        return 0;
    }
    //printf("%Lf %Lf %Lf %Lf\n",cross(AB,AD),cross(AB,AC),cross(CD,CA),cross(CD,CB));
    if((cross(AB,AD)*cross(AB,AC)<0)&&(cross(CD,CA)*cross(CD,CB)<0)){
        struct L L1,L2;
        L1 = genL(A.x,B.x,A.y,B.y);
        L2 = genL(C.x,D.x,C.y,D.y);
        pt A = intersect(L1, L2);
        printf("%0.6Lf %0.6Lf",A.x,A.y);
    }
    else if((cross(AB,AD)*cross(AB,AC)==0)&&(cross(CD,CA)*cross(CD,CB)==0)){
        if(in(A,B,C)&&in(A,B,D))
            printf("%0.6Lf %0.6Lf %0.6Lf %0.6Lf",A.x,A.y,B.x,B.y);
        else if(in(C,D,A)&&in(C,D,B))
            printf("%0.6Lf %0.6Lf %0.6Lf %0.6Lf",C.x,C.y,D.x,D.y);
        else if(in(C,D,A)&&!in(C,D,B)){
            if(in(C,B,D))
                printf("%0.6Lf %0.6Lf %0.6Lf %0.6Lf",A.x,A.y,B.x,B.y);
            else
                printf("%0.6Lf %0.6Lf %0.6Lf %0.6Lf",A.x,A.y,C.x,C.y);
        }
        else if(in(C,D,B)&&!in(C,D,A)){
            if(in(C,A,D))
                printf("%0.6Lf %0.6Lf %0.6Lf %0.6Lf",B.x,B.y,D.x,D.y);
            else
                printf("%0.6Lf %0.6Lf %0.6Lf %0.6Lf",B.x,B.y,C.x,C.y);
        }
    }
    else{
        printf("-1");
        return 0;
    }
    return 0;
}
