#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

#define ll long long int
#define pb push_back
#define fi first
#define se second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a; i>b; i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
#define ub(A,x) upper_bound(A.begin(), A.end(), x)
#define lb(A,x) lower_bound(A.begin(), A.end(), x)
using namespace std;
const int MAXN = 2e5;
typedef vector< pair<ll,int> > vli;
typedef pair<ll ,int> pli;
typedef pair<int, int> pi;
typedef vector<pi > vii;

ll gcd(ll a, ll b){
    if(a==0) return b;
    return gcd(b%a, a);
}

ll lcm(ll a, ll b){
    ll pro = a*b;
    ll g = gcd(a, b);
    return pro/g;
}

int main(){
    ll a; ll b;
    rl(a); rl(b);
    ll l = lcm(a,b);
    ll k1, k2;
    k1 = l/a; k2 = l/b;
    if(k1<k2) k1++;
    else k2++;
    if(k1==k2) cout<<"Equal";
    else if(k1<k2) cout<<"Masha";
    else cout<<"Dasha";
}