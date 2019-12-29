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
#define fi first
#define se second
using namespace std;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef set< pair<ll,int> > s;

ll gcd(ll a,ll b,ll *x,ll *y){//a >b
    if(b==0){
        *x = 1;
        *y = 0;
        return a;
    }
    ll x1,y1;
    ll g =gcd(b,a%b,&x1,&y1) ;
    *x = y1;
    *y = x1 - (a/b)*y1;
    return g;
}

int main(){
    ll l,w,r;
    scanf("%lld %lld %lld",&l,&r,&w);
    ll x,y;
    bool c = false;
    ll g = gcd(max(w,r),min(w,r),&x,&y);
        if((l-w+1)%g&&(w-1<r)){
        printf("DEADLOCK\n");
    }
    else
        printf("OK");
    return 0;
}
