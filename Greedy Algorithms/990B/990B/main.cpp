#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

#define ll long long int
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a; i>b; i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
#define ub(A,x) upper_bound(A.begin(), A.end(), x)
#define lb(A,x) lower_bound(A.begin(), A.end(), x)
using namespace std;
const int MAXN = 2e5;
typedef vector<ll> vl;
typedef vector<int> vi;
int N,K; vi B;

void read(){
    ri(N); ri(K);
    N++;
    B.resize(N);
    FOR(i, 0, N-1) ri(B[i]); B[N-1] = 2e9;
}

int main() {
    read();
    sort(B.begin(), B.end());
    int ans = 0, u =0;
    FOR(i, 0, N){
        while(u < N && B[i] == B[u]) u++;
        if(B[u]> B[i] + K) ans++;
    }
    printf("%d",ans);
    return 0;
}
