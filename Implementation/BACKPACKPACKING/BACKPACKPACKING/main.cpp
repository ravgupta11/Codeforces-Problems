#include <vector>
#include <iostream>
#include <algorithm>

#define ll long long int
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;

typedef vector<ll> vl;
typedef vector<int> vi;

const int MAXN = 2e5 +5;
const ll INF = 1e9+9;
int A, B, N;
int v[101];

int solve(){
    ri(A); ri(B); ri(N);
    //printf("%d %d %d\n",A,B,N);
    FOR(i, 0, N) ri(v[i]);
    //FOR(i, 0, N) printf("%d ",v[i]);
    int lA = A, lB = B, i = 0, cnt=0;
    while(i<N){
        if (!(lA - v[i] >-1 || lB - v[i] >-1 )){
            cnt++;
            i++;
            continue;
        }
        if(lA>lB) lA -= v[i];
        else lB -= v[i];
        //printf("%d %d %d\n",lA, lB, v[i]);
        i++;
    }
    i--;
    return cnt;
}

int main() {
    int ans = solve();
    printf("%d",ans);
    return 0;
}
