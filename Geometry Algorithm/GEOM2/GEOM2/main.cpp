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

pt rotate(pt p,dbl a){
    return {cos(a)*p.x-sin(a)*p.y, cos(a)*p.y+sin(a)*p.x};
}

dbl dot(pt A,pt B){
    return A.x*B.x + A.y*A.y;
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

dbl det1(dbl a,dbl b,dbl c,dbl d){
    return a*d - b*c;
}
dbl det12(L l1, L l2){
    return l1.a*l2.b - l1.b*l2.a;
}
struct L genL(dbl x1,dbl x2,dbl y1,dbl y2){
    struct L L1;
    L1.a = y1-y2;
    L1.b = x2- x1;
    L1.c = -1*(L1.a*x1 + L1.b*y1);
    return L1;
}

int main(){
    dbl x1,y1,x2,y2;
    dbl x3,y3,x4,y4;
    scanf("%Lf %Lf %Lf %Lf",&x1,&y1,&x2,&y2);
    scanf("%Lf %Lf %Lf %Lf",&x3,&y3,&x4,&y4);
    L L1 = genL(x1,x2,y1,y2);
    L L2 = genL(x3,x4,y3,y4);
    if((zero(det1(L1.a,L1.b,L2.a,L2.b))&&zero(det1(L1.c,L1.b,L2.c,L2.b)))&&(zero(det1(L1.a,L1.c,L2.a,L2.c)))){
        printf("2");
    }
    else if((zero(det1(L1.a,L1.b,L2.a,L2.b))||zero(det1(L1.c,L1.b,L2.c,L2.b)))||(zero(det1(L1.a,L1.c,L2.a,L2.c)))){
        printf("0");
    }
    else{
        pt p;
        p.x = -1*(det1(L1.c,L1.b,L2.c,L2.b)/det1(L1.a,L1.b,L2.a,L2.b));
        p.y = -1*(det1(L1.a,L1.c,L2.a,L2.c)/det1(L1.a,L1.b,L2.a,L2.b));
        printf("1\n");
        printf("%0.3Lf %0.3Lf",p.x,p.y);
    }
}
