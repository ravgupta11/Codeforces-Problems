#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

#define ll long long int
#define pb push_back
#define fi first
#define se second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a; i>b; i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
#define ub(A,x) upper_bound(A.begin(), A.end(), x)
#define lb(A,x) lower_bound(A.begin(), A.end(), x)
using namespace std;
const int MAXN = 2e5;
typedef vector< pair<ll,int> > vli;
typedef pair<ll ,int> pli;
typedef pair<int, int> pi;
typedef vector<pi > vii;

vli A;vii B;
int N;

int main() {
    ri(N);
    FOR(i, 0, N){
        ll u; rl(u);
        A.pb({u, i});
    }
    sort(A.begin(), A.end());
    FOR(i, 0, N){
        int y = A[i].se;
        B.pb({min(i,y),max(i,y)});
    }
    sort(B.begin(), B.end());
    int MAX = -1, ans = 0;
    FOR(i, 0, N){
        if(B[i].fi >= MAX){
            ans++; MAX = B[i].se;
        }
        else if(B[i].se > MAX) MAX = B[i].se;
    }
    printf("%d",ans);
    return 0;
}
