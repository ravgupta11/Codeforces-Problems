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
typedef pair<int,int> pt;
typedef pair<ll,ll> pl;
typedef set< pair<ll,int> > s;

struct L{
    int a,b,c;
};
const dbl EPS =1e-5;

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

int cross(pt A,pt B){
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

int det1(int a,int b,int c,int d){
    return a*d - b*c;
}

pt intersect(struct L L1,struct L L2){//given they are not parallel
    pt p;
    p.x = -1*(det1(L1.c,L1.b,L2.c,L2.b)/det1(L1.a,L1.b,L2.a,L2.b));
    p.y = -1*(det1(L1.a,L1.c,L2.a,L2.c)/det1(L1.a,L1.b,L2.a,L2.b));
    return p;
}

int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
dbl check(pt A,struct L l){//side of a point around a line
    dbl sign1 = l.a*A.x + l.b*A.y +l.c;
    return sign1;
}

int main(){
    struct L L1,L2;
    scanf("%d %d %d %d %d %d",&L1.a,&L1.b,&L1.c,&L2.a,&L2.b,&L2.c);
    if((L1.a==0&&L1.b==0)){
        printf("-1");
        return 0;
    }
    if((L2.a==0&&L2.b==0)){
        printf("-1");
        return 0;
    }
    if((det1(L1.a,L1.b,L2.a,L2.b)==0&&det1(L1.c,L1.b,L2.c,L2.b)==0)&&(det1(L1.a,L1.c,L2.a,L2.c)==0)){
        printf("-1");
    }
    else if(cross({L1.a,L1.b},{L2.a,L2.b})==0){
        printf("0");
    }
    else{
        printf("1");
    }
    return 0;
}
