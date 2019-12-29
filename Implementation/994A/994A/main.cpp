#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <utility>
#include <set>
#include <queue>
#define ll long long int
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i,a,b) for(int i = a;i>b;i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;

typedef vector<ll> vl;
typedef vector<int> vi;

vi A, B;int C[11];
int N, M;

int main(){
    ri(N); ri(M);
    FOR(i, 0, N){
        int u;
        ri(u);
        A.pb(u);
    }
    FOR(i, 0, M){
        int u;
        ri(u);
        B.pb(u);
    }
    sort(B.begin(), B.end());
    FOR(i, 0, N)
        if(A[i] == (*lower_bound(B.begin(), B.end(), A[i])))
            C[A[i]] = 1;
    FOR(i, 0, N)
    if(C[A[i]] == 1)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}
