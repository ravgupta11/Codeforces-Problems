#include <iostream>
#define ll long long int
using namespace std;
ll calv[100][100][100];
bool cal[100][100][100];
ll x;

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b,b%a);
}
ll dp(ll y,ll z,ll a){
    if (y==0&&(gcd(a,z)==x)) return 1;
    if(y==0) return 0;
    if(!cal[y][z][a]){
        ll m  =0;
        ll it = y/x;
        while(it>0){
            ll a = y-it*x;
            m+= dp(a,min(z,it*x),max(a,it*x));
            it--;
        }
        cal[y][z][a] = true;
        calv[y][z][a] = m;
    }
    return calv[y][z][a];
}

int main() {
    ll y;
    scanf("%lld %lld",&x,&y);
    ll ans;
    if(y%x==0)
        ans = (dp(y,y,0))%(1000000009);
    else
        ans= 0;
    printf("%lld",ans);
    return 0;
}
