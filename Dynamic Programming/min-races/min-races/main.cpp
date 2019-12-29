#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <utility>

#define ll long long int
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i,a,b) for(int i = a;i>b;i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector< pi > vpi;
vpi A; vi B; int N;

int LIS() {
    vi d(N+1, 1000000000);
    for (int i = 0; i < N; i++) {
        *lower_bound(d.begin(), d.end(), B[i]) = B[i];
    }
    for (int i = 0; i <= N; i++) {
        if (d[i] == 1000000000) {
            return i;
        }
    }
    return 0;
}

int main(){
    int K;
    ri(N); ri(K);
    FOR(i, 0, N){
        int a, b;
        ri(a); ri(b);
        A.pb({b,a});
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    FOR(i, 0, N) B.pb(A[i].second);
    int ans = LIS();
    printf("%d",ans);
    return 0;
}
