#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <math.h>
#include <algorithm>
#include <set>
#define pb push_back
#define ll long long int
#define fi first
#define se second
using namespace std;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef set< pair<ll,int> > s;
const int MAXN = 20;
const int INF =1e9+9;
const int MAXP = 1<<MAXN;

int N;
ll S;

pl dp[MAXP+5];
vector<ll> pizzas;
int pre[MAXP+5];
vector<int> piles;
vector<int> BAGS[MAXN+5];

void init(){
    pizzas.clear();
    for(int mask=0;mask<(1<<MAXN);mask++){
        dp[mask] = {INF,INF};
    }
    for(int i =0;i<N;i++){
        BAGS[i].clear();
    }
    dp[0]={1,0};
    pre[0] =-1;
}
void f(){
    for(int mask =0;mask<((1<<N)-1);mask++){
        ll count = dp[mask].fi;
        ll last = dp[mask].se;
        for(int i =0;i<N;i++){
            if((mask&(1<<i))) continue;
            ll l1 =last+pizzas[i];
            ll l2 =pizzas[i];
            pl a= {count, l1};
            pl b ={count+1,l2};
            pl c =((l1<=S)?a:b);
            //dp[mask + (1<<i)] = min(dp[mask + (1<<i)],c);
            if(dp[mask + (1<<i)]>c){
                dp[mask + (1<<i)] = c;
                pre[mask + (1<<i)] = i;
            }
        }
    }
}
void trace(){
    for(int mask =(1<<N)-1;mask>0;mask -= 1<<pre[mask]){
        BAGS[(dp[mask].fi)-1].pb(pre[mask]+1);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %lld",&N,&S);
        init();
        for(int i=0;i<N;i++){
            ll u;
            scanf("%lld",&u);
            pizzas.pb(u);
        }
        f();
        ll ans =dp[(1<<N) - 1].fi;
        trace();
        printf("%lld\n",ans);
        for(int i =0;i<ans;i++){
            printf("%ld ",BAGS[i].size());
            for(int cap: BAGS[i])
                printf("%d ",cap);
            printf("\n");
        }
    }
    return 0;
}
