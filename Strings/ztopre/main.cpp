#include <bits/stdc++.h>

#define ll long long int
#define pb push_back
#define x first
#define y second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a; i>b; i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;
const int MAXN = 2e5+5;
int zet[MAXN], pre[MAXN];

int main(){
    int n;
    ri(n);
    FOR(i, 0, n)
        ri(zet[i]);
    FOR(i, 0, n){
        if(!zet[i]) continue;
        pre[zet[i] +i -1] = max(zet[i], pre[zet[i] + i -1]);
    }
    int bst = 0;
    FORR(i, n-1, -1){
        bst = pre[i] = max(bst, pre[i]);
        bst--;
        bst = max(0, bst);
    }
    FOR(i, 0, n) printf("%d ", pre[i]);
    return 0;
}