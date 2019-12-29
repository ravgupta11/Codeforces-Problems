#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

#define ll long long int
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a; i>b; i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;
const ll mod = 1e9+7;

ll binexpo(ll base, ll exp) {
    ll res=1;
    while(exp>0) {
        if(exp%2==1) res=(res*base)%mod;
        base=(base*base)%mod;
        exp/=2;
    }
    return res%mod;
}
ll binexpo2(ll a, ll b)
{
    ll res = 0; // Initialize result
    a = a % mod;
    while (b > 0)
    {
        // If b is odd, add 'a' to result
        if (b % 2 == 1)
            res = (res + a) % mod;
        
        // Multiply 'a' with 2
        a = (a * 2) % mod;
        
        // Divide b by 2
        b /= 2;
    }
    
    // Return result
    return res % mod;
}
int main(){
    ll x,k;
    rl(x); rl(k);
    if(x==0){
        printf("0");
        return 0;
    }
    ll b = binexpo(2, k);
    ll ans = (binexpo2(b, (2*(x%mod)-1)) + 1)%mod;
    printf("%lld",(ans%mod + mod)%mod);
    return 0;
}
