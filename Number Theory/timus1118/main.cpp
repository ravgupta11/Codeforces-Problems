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
#define x first
#define y second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a; i>b; i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;
const int MAXN = 1e6+1;
ll s[MAXN];

void sieve(){
    FOR(i, 2, MAXN) s[i] = 1;
    FOR(i, 2, (int)1e3+1){
        for(int j = i+1;i*j<MAXN; j++) s[i*j] += i+j;
        if(i*i < MAXN) s[i*i] += i;
    }
}

void solve(){
    sieve();
    int l, r;
    ri(l); ri(r);
    double mint = 1e6+1;
    int min = 0;
    FOR(i, l, r+1){
        double c = ((double)s[i])/((double)i);
        //printf("%lld %d %lf\n",s[i],i,c);
        if(c < mint){
            mint = c;
            min = i;
        }
    }
    printf("%d", min);
}

int main(){
    solve();
    return 0;
}