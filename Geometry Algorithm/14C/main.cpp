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
    pt X1, X2, Y1, Y2;
};

bool cmpp(pt X1 , pt X2){
    if(X1.x == X2.x && X2.y == X1.y) return true;
    return false;
}

struct seg{
    pt X1, X2;
};
pt make_vector(struct seg A){
    return {A.X2.x - A.X1.x, A.X2.y - A.X1.y};
}

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


dbl distPP(pt a,pt b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y - b.y));
}

dbl det(L l1, L l2){
    return l1.a*l2.b - l1.b*l2.a;
}

struct seg ls[4];

bool contact(struct seg I, struct seg J){
    if(cmpp(I.X1 ,J.X2)) return true;
    if(cmpp(I.X1 ,J.X1)) return true;
    if(cmpp(I.X2 ,J.X2)) return true;
    if(cmpp(I.X2 ,J.X1)) return true;
    return false;
}

int main(){
    FOR(i, 0, 4){
        rp(ls[i].X1); rp(ls[i].X2);
    }
    FOR(i, 0, 4){
        pt I = make_vector(ls[i]);
        int p = 0, q = 0;
        FOR(j, 0, 4){
            if(i==j) continue;
            pt J = make_vector(ls[j]);
            if(dot(I,J) == 0) q++;
            else if(cross(I,J) == 0) p++;
            else {
                printf("NO");
                return 0;
            }
        }
        if(p !=1 || q != 2){
            printf("NO");
            return 0;
        }
    }
    FOR(i, 0, 4){
        struct seg I = ls[i];
        int r = 0;
        FOR(j, 0, 4){
            if(i==j) continue;
            struct seg J = ls[j];
            if(contact(I,J)) r++;
        }
        if(r != 2){
            printf("NO");
            return 0;
        }
    }
    FOR(i, 0, 4) {
        if ((ls[i].X1.x != ls[i].X2.x) && (ls[i].X1.y != ls[i].X2.y)){
            printf("NO");
            return 0;
        }
    }
    int area = 0;
    pt A = make_vector(ls[0]);
    FOR(i, 1, 4){
        if(dot(A, make_vector(ls[i])) == 0) {
            area = cross(A, make_vector(ls[i]));
            if(abs(area) == 0) {
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES");
    return 0;
}