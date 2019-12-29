#include <iostream>
#include <vector>
#define pb push_back
#define fi first
#define se second
#define ll long long int
#define FOR(i,a,b) for(int i = a;i<b;i++)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<ll> vl;

ll euler(ll n){
    ll result = n;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0)
                n/=i;
            result = result - result/i;
        }
    }
    if(n>1){
        result = result - result/n;
    }
    return result;
}

int main() {
    ll N;
    while(scanf("%lld",&N), N!=0){
        ll ans;
        if(N==1) ans = 0;
        else
            ans = euler(N);
        printf("%lld\n",ans);
    }
    return 0;
}
