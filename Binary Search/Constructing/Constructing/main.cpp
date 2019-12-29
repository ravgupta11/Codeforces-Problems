#include <math.h>
#include<iostream>
#define ll long long int
using namespace std;
ll n,x;

ll f(ll m){
    ll k = floor(n/m);
    ll ans = n*n - k*k - x;
    //printf(" %lld\n",ans);
    return ans;
}

ll binary(ll low=2,ll high=n){
    if(high-low<2){
        if(!f(high))
            return high;
        if(!f(low))
            return low;
        return -1;
    }
    ll mid = (low+high)>>1;
    if(!f(mid)) return mid;
    if(f(mid)<0) return binary(mid+1,high);
    return binary(low,mid-1);
}
int main(){
    ll A[102];
    int t;
    scanf("%d",&t);
    for(int i =0;i<t;i++)
        scanf("%lld",&A[i]);
    for(int i =0;i<t;i++){
        x= A[i];
        if(x==0){
            printf("1 1\n");
            continue;
        }
        ll m = -1;
        for(n = 2;n*n<=(4*x/3);n++){
            m = binary();
            if(m>-1)
                break;
        }
        if(m!=-1)
            printf("%lld %lld\n",n,m);
        else
            printf("-1\n");
    }
    return 0;
}
