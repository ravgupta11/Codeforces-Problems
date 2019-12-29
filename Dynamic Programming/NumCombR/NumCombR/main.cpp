#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <math.h>
#include <set>
#define pb push_back
#define ll long long int
#define fi first
#define se second
using namespace std;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,int> pl;
typedef set< pair<ll,int> > s;
typedef pair<pair<int,int>, pair<int,int> > pt;
const short INF = 1e9+8;

ll dp[32][32];
int N,K;
int a[32];
void init(){
    for(int i =0;i<=N+1;i++)
        for(int j =0;j<K+2;j++)
            dp[i][j] = -1;
}

ll f(int u,int i){
    if(i==K) return 1;
    if(u>N) return 0;
    if(dp[u][i]!=-1) return dp[u][i];
    ll ans = f(u,i+1) + f(u+1,i);
    return dp[u][i] = ans;
}

int main(){
    scanf("%d %d",&N,&K);
    init();
    for(int i =0;i<K;i++)
        scanf("%d",&a[i]);
    ll ans = 0;
    int last = 1;
    for(int j=0;j<K;j++){
        for(int k =last;k<a[j];k++){
            ans += f(k,j+1);
        }
        last = a[j];
    }
    printf("%lld",ans);
    
}
