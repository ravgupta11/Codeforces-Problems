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
#pragma comment (linker, "/STACK:256000000")
#define ll long long int
#define pb push_back
#define x first
#define y second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a; i>b; i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;
typedef vector<ll> vl;

char str[101]; int z[101];

int solve(){
    scanf("%s", str);
    int n = (int) strlen(str);
    FOR(i, 0, n) z[i] = 0;
    int l = 0, r = 0;
    FOR(i, 1, n){
        if(i<=r) z[i] = min(z[i-l], r-i+1);
        while(z[i]+i<n && str[z[i]] == str[i+z[i]]) z[i]++;
        if(i+z[i]-1>r){
            l = i; r = i+z[i]-1;
        }
    }
    int ans = n;
    FOR(i, 1, n){
    if(z[i]==0) continue;
        if(z[i]+i==n && n%(i)==0) {ans = i; break;}
    }
    return ans;
}

int main(){
    int t;
    ri(t);
    while(t--){
        int ans = solve();
        printf("%d\n",ans);
        if(t) printf("\n");
    }
    return 0;
}

