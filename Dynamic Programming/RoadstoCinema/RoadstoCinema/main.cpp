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
const ll INF = 1e9+9;
vector<pt> R;
int pre[505][505];
ll dp[505][505];
int x[505];int y[505];
int n;

ll f(int l,int r){
    if(l==r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    ll MIN = INF;
    for(int m =l;m<r;m++){
        MIN= min(MIN,y[m]- y[r] +(x[m+1]-x[l])+f(l,m)+f(m+1,r));
    }
    for(int m =l;m<r;m++){
        if(MIN== y[m]-y[r] +(x[m+1]-x[l])+f(l,m)+f(m+1,r)){
            pre[l][r] =m;
        }
    }
    return dp[l][r]=MIN;
}
void init(){
    for(int i =0;i<504;i++)
        for(int j =0;j<504;j++){
            dp[i][j] = -1;
        }
}
void trace(int l,int r){
    if(r-l<=0) return;
    int  m=pre[l][r];
    pt a,b;
        a ={{x[l],y[m]},{x[l],y[r]}};
        if(y[m]-y[r]>0){
            R.pb(a);
            
        }
        trace(l,m);
        b = {{x[m+1],y[r]},{x[l],y[r]}};
        if(x[m+1]-x[l]>0){
            R.pb(b);
        }
        trace(m+1,r);
}
int main(){
    init();
    scanf("%d",&n);
    for(int i =0;i<n;i++) {
        int x1, y1;
        scanf("%d %d", &x1, &y1);
        x[i] = x1;
        y[i] = y1;
    }
    ll ans = f(0,n-1);
    ans += x[0] + y[n-1];
    trace(0,n-1);
    pt a,b,c,d;
    a={{x[0],0},{0,0}};
    b ={{x[0],y[n-1]},{x[0],0}};
    c = {{0,y[n-1]},{0,0}};
    if(x[0]>0&&y[n-1]>0){
        R.pb(a);R.pb(b);
    }
    else if(y[n-1]>0){
        R.pb(c);
    }
    else if(x[0]>0){
        R.pb(a);
    }
    long D = R.size();
    printf("%ld %lld\n",D,ans);
    for(int i =0;i<D;i++){
       printf("%d %d %d %d\n",R[i].fi.fi,R[i].fi.se,R[i].se.fi,R[i].se.se);
    }
    return 0;
}
