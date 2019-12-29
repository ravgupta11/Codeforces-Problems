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
const int MAXN = 13;
ll dp[MAXN];
int N;
int a[13];
int p[13];
void init(){
    for(int i =0;i<=12;i++)
        dp[i] =-1;
}

ll f(int n){
    if(n==0) return 1;
    if(dp[n]!=-1) return dp[n];
    return n*f(n-1);
}

int main(){
    init();
    scanf("%d",&N);
    for(int i =0;i<N;i++)
        scanf("%d",&a[i]);
    ll ans = 0;
    for(int j =0;j<N;j++)
        for(int i =j-1;i>-1;i--)
            if(a[i]<a[j])
                p[j]++;
    
    for(int j=0;j<N;j++){
        ans += (a[j]-1-p[j])*f(N-(1+j));
        //printf("%d %d %lld\n",j,a[j]-1-p[j],f(N-1-j));
    }
    printf("%lld",ans+1);
    return 0;
}
