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
typedef vector<ll > vl;
typedef vector< pair<ll,int> > vli;
typedef pair<ll ,int> pli;
typedef pair<int, int> pi;
typedef vector<pi > vii;

int N; vl A;


int main() {
    ri(N);
    FOR(i, 0, N){
        ll u; rl(u);
        A.pb(u);
    }
    sort(A.begin(), A.end());
    int l = -1; ll s1 = 0, s2 =0, s3 = 0,s4 = 0;
    FORR(i, N-1, -1){
        if(A[i]<0){
            l = i;
            break;
        }
        s1 += A[i];
    }
    if(l<0) printf("%lld",s1);
    FORR(i,l,-1){
        s2+= A[i];
        i--;
    }
    FORR(i,l-1,-1){
        s3+= A[i];
        i--;
    }
    s2 = max(s3 + A[l], s2);
    if(l==N-1)
        s3 = -1e9-9;
    ll ans = max(s2,s3) + s1;
    printf("%lld",ans);
    return 0;
}
