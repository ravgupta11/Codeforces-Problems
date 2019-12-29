#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define fi first
#define se second
#define ll long long int
#define FOR(i,a,b) for(ll i = a;i<b;i++)
#define FORR(i,a,b) for(ll i = a;i>b;i--)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<ll> vl;
const int MAXN = 2e5+6;
int phi[MAXN];
vl pre;

void init(){
    FOR(i,1,MAXN)
        phi[i] = i;
    pre.resize(MAXN);
}

void precal(){
    FOR(i,2,MAXN)
        if(phi[i]==i){
            phi[i] = i-1;
            for(int j = 2;i*j<=MAXN;j++){
                phi[i*j] = (phi[i*j] - phi[i*j]/i);
            }
        }
    ll sum = 1;
    FOR(i,1,MAXN){
        sum += phi[i];
        pre[i] = sum;
    }
}

ll gcd(ll a,ll b){
    if(a==0) return b;
    return gcd(b%a,a);
}
ll bsearch(ll key){
    ll lo = 0;ll hi = MAXN;
    while(lo<=hi){
        ll mi = (lo+hi)>>1;
        if(pre[mi]== key) return mi+1;
        else if(pre[mi]< key) lo = mi+1;
        else hi = mi-1;
    }
    return lo;
}
int main() {
    init();
    precal();
    ll it;
    while(scanf("%lld",&it), it!=0){
        if(it==1){
            printf("0/1\n");
        }
        else{
        ll iter = bsearch(it);
            if(pre[iter-1] == it){
                ll ans = 0;ll cnt = 0;
                int i =1;
                while(cnt<phi[iter-1]){
                    if(gcd(i,iter-1)==1){
                        ans = i;
                        cnt++;
                    }
                    i++;
                }
                printf("%lld/%lld\n",ans,iter-1);
        }
        else{
            ll prev = pre[iter-1];
            printf("%lld ",prev);
            ll left = it -prev;
            printf("%lld\n",left);
            int cnt = 0;
            ll ans = 0;
            FOR(i,1,iter){
                if(cnt==left){
                    ans = i-1;
                    break;
                }
                if(gcd(i,iter)==1) cnt++;
            }
            printf("%lld/%lld\n",ans,iter);
        }
        }
    }
    return 0;
}
