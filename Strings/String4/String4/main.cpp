#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
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

vl A, B;
set <ll> st;
int main(){
    int n; ri(n);
    FOR(i, 0, n){
        ll u;
        scanf("%lld",&u);
        A.pb(u);
    }
    if(n==1){
        printf("%d",1);
        return 0;
    }
    sort(A.begin(), A.end());
    ll s = 2;
    while(s<2e9){
        B.pb(s);
        s *= 2;
    }
    vl ans;
    FOR(i, 0, n){
        ll upi = distance(B.begin(), upper_bound(B.begin(), B.end(), A[i]));
        ll re = B[upi] - A[i];
        ll lpi = distance(A.begin(), upper_bound(A.begin(), A.end(), re)) - 1;
        lpi = max(0LL, lpi);
        if(lpi != i && A[i] + A[lpi] == B[upi]) {
            st.insert(i);
            st.insert(lpi);
        }
    }
    printf("%ld", n - st.size());
    return 0;
}

