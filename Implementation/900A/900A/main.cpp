#include <iostream>
typedef long long int ll;
using namespace std;

int main(){
    ll n;
    scanf("%lld",&n);
    ll arr[100004][2];
    for(int it =0;it<n;it++){
        ll x,y;
        scanf("%lld %lld",&x,&y);
        arr[it][0] = x;
        arr[it][1] = y;
    }
    int pos=0,neg=0;
    for(int it =0;it<n;it++){
        if(arr[it][0]>0) pos++;
        else neg++;
    }
    if((pos<=1&&neg>=1)||(neg<=1&&pos>=1))
        printf("Yes");
    else
        printf("No");
}
