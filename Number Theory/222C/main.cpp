#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <string.h>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#define ll long long int
#define pb push_back

#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FORR(i, a, b) for(ll i = a; i>b; i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;

const int MAX = 1e6+1;
const int MAXS = 1e7 +1;

int n, m, a[MAXS], b[MAXS], x[MAXS], y[MAXS];

int sp[MAXS];

void sieve(){
    for(int i = 2; i*i<=MAXS; i++) if(!sp[i]) for(int j = i*i; j<=MAXS; j+= i)  sp[j] = i;
    for(int i = 2; i<= MAXS; i++) if(!sp[i]) sp[i] = i;
}


int main(){
    sieve();
    ri(n); ri(m);
    FOR(i, 0, n) ri(a[i]);
    FOR(i, 0, m) ri(b[i]);

    printf("%d %d\n",n, m);
    FOR(i, 0, n) for(int k = a[i]; k>1; k/=sp[k]) x[sp[k]]++;
    FOR(i, 0, m) for(int k = b[i]; k>1;k/=sp[k]) y[sp[k]]++;
    FOR(i, 0, n){
        int ans = 1;
        for(int x1 = a[i]; x1>1; x1 /= sp[x1]){
            if(y[sp[x1]]>0) y[sp[x1]]--;
            else ans *= sp[x1];

        }
        printf("%d ", ans);
    }
    printf("\n");
    FOR(i, 0, m){
        int ans = 1;
        for(int x1 = b[i]; x1>1; x1 /= sp[x1]){
            if(x[sp[x1]]>0) x[sp[x1]]--;
            else ans *= sp[x1];
        }
        printf("%d ", ans);
    }
    return 0;
}