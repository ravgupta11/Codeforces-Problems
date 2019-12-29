#include <iostream>
#define ll long long int
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t-->0){
        ll x;
        scanf("%lld",&x);
        bool found = false;
        if(x%3>=0){
            ll a = x/3;
            if(7*a - 2*x>=0){
                found = true;
            }
        }
        if(found) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
