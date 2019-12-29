#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int
using namespace std;
vector<ll> arr;
ll N,C;

bool f(ll x){
    ll C1 = C-1;
    ll old = 0;
    for(ll i = 1;i<N;i++){
        if(arr[i]-arr[old]>=x){
            C1--;
            old = i;
        }
    }
    if(C1<=0)
        return true;
    return false;
}

ll binary(ll start,ll end){
    if(end-start==1)
        if(!f(end)&&f(start))
            return start;
    if(end-start==0)
        if(!f(end+1)&&f(end))
            return end;
    ll mid = (start+end)/2;
    if(f(mid)&&!f(mid+1)) return mid;
    if(!f(mid)) return binary(start,mid-1);
    return binary(mid+1,end);
}

int main(){
    int t;
    scanf("%d",&t);
    for(int it =0;it<t;it++){
        scanf("%lld %lld",&N,&C);
        arr.clear();
        for(ll i =0;i<N;i++){
            ll u;
            scanf("%lld",&u);
            arr.push_back(u);
        }
        sort(arr.begin(),arr.end());
        ll bound = 1e9;
        ll ans = binary(0,bound);
        printf("%lld\n",ans);
    }
    return 0;
}
