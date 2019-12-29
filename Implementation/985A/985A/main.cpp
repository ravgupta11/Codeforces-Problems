#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

#define ll long long int
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i,a,b) for(int i = a;i>b;i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;

typedef vector<ll> vl;
typedef vector<int> vi;

const int MAXN = 5e5 +5;
const ll INF = 1e9+9;
vi od, ev, B;
int solve(){
    int N;
    ri(N);
    FOR(i, 0, N/2){
        int u; ri(u);B.pb(u);
    }
    sort(B.begin(), B.end());
    int j = 1;int s1 = 0;
    FORR(i,N/2-1,-1){
        s1 += abs((N-j) - B[i]);
        j+=2;
    }
    j = 0; int s2 =0;
    FORR(i, N/2-1, -1){
        s2 += abs(N-j - B[i]);
        j+= 2;
    }
    return min(s1,s2);
}

int main(){
    int ans = solve();
    printf("%d",ans);
    return 0;
}
