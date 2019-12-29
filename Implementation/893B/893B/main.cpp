#include <iostream>
#include <math.h>
#define ll long long int
using namespace std;

ll f(ll a){
    if (a%2!=0) return 1;
    int n = floor(log(a)/log(2));
    printf("%d\n",n);
    for(int it = n;it>=1;it--){
        ll b = ((1<<(it)) -1)*(1<<(it-1));
        if(a%b==0) return b;
    }
    return 1;
}


int main() {
    ll N;
    scanf("%lld",&N);
    printf("%lld",f(N));
    return 0;
}
