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
void print(pt PQ){
    printf("PQ is: %Lf %Lf\n",PQ.x,PQ.y);
}
int main(){
    dbl x1,y1,x2,y2,x3,y3;
    scanf("%Lf %Lf %Lf %Lf %Lf %Lf",&x1,&y1,&x2,&y2,&x3,&y3);
    pt X1 = {x1,y1};
    pt X2 = {x2,y2};
    pt X3 = {x3,y3};
    pt PQ = vect(X2,X3);
    pt QP = vect(X3,X2);
    pt PX = vect(X2,X1);
    pt QX = vect(X3,X1);
    if(zero(cross(PQ,PX))&&dot(PQ,PX)>=0&&dot(QP,QX)>=0){
        printf("YES");
    }
    else
        printf("NO");
}
