#include <iostream>
#define ll long long int
using namespace std;
int main() {
    ll x;
    while(scanf("%lld",&x) != EOF){
        ll ans = x*(x+1)/2;
        ans = ans*ans;
        printf("%lld\n",ans);
    }
    return 0;
}