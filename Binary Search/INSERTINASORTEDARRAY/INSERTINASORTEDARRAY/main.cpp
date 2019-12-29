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
int N, X; vi ARR;

int main() {
    ri(N); ri(X);
    ARR.resize(N);
    FOR(i, 0, N)
    ri(ARR[i]);
    int in = (int)distance(ARR.begin(), upper_bound(ARR.begin(), ARR.end(), X)) +1;
    printf("%d", in);
    return 0;
}
