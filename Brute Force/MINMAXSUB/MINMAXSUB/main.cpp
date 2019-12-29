#include <iostream>
#include <vector>
#define fi first
#define se second
#include <algorithm>
#include <math.h>
#include <utility>
using namespace std;

#define ll long long int
#define dbl double long
#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORR(i, a, b) for(int i = a; i > b; i--)
#define ri(x) scanf("%d",&x)
#define rii(x,xx) scanf("%d %d", &x, &xx)
#define rl(x) scanf("%lld", &x);

const int MAXN = 5e5+1;
const int INF = 1e9+9;

vector<int> mins, maxs, diff;

int main() {
    int N; ll A[MAXN];
    ri(N);
    FOR(i, 0, N)
        rl(A[i]);
    ll MIN = INF, MAX = -1;
    FOR(i, 0, N){
        MAX = max(MAX, A[i]);
        MIN = min(MIN, A[i]);
    }
    int ans  =MAXN;
    if(MIN != MAX){
        FOR(i, 0, N){
            if(A[i] == MIN) mins.pb(i);
            if(A[i] == MAX) maxs.pb(i);
        }
        for(int u: mins)
            for(int v: maxs){
                int diff = max(u-v+1,v-u+1);
                //printf("%d %d %d\n",u,v, diff);
                ans = min(ans, diff);
            }
        printf("%d",ans);
    }
    else
        printf("1");
    
    return 0;
}
