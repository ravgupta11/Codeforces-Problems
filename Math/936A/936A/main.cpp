#include <iostream>
#include <math.h>
using namespace std;
#define ll long long int
#define dbl long double

ll k,d,t;

int main(){
    scanf("%lld %lld %lld",&k,&d,&t);
    ll p;
    if(k<d)
        p= d;
    else
        p = ((k+d-1)/d)*d;
    ll z = p + k;
    ll x = floor((2*t)/z);
    dbl y = 2*t - z*x;
    if(y>2*k) y = y - k;
    else y = y/2;
    dbl ans;
    ans = p*x  + y;
    printf("%Lf\n",ans);
    return 0;
}
