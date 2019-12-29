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
const int MAXN =100;
int N;
ll dp[MAXN][8];
void init(){
    for(int i =0;i<N+3;i++)
        dp[i][1] =dp[i][2] = dp[i][3] = dp[i][4] = dp[i][5] =-1;
}
ll comb(int n,int k){
    if(k==0||n==k) return 1;
    if(k>n) return 0;
    if(dp[n][k]!=-1) return dp[n][k];
    ll c = comb(n-1,k-1) + comb(n-1,k);
    return dp[n][k] = c;
}
int main(){
    scanf("%d",&N);
    init();
    ll prod = comb(N,5)*comb(N,5)*120;
    printf("%lld",prod);
    return 0;
}
