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
bool mat[2][100000];
vector<pair<pair<ll, int>, int> > vi;
vector<int> A, B;
int n;

int main(){
    ri(n);
    FOR(i, 0, n){
        ll u; ll v;
        rl(u); rl(v);
        vi.pb({{u,0},i}); vi.pb({{v,1},i});
        A.pb(u); B.pb(v);
    }
    sort(vi.begin(), vi.end());
    FOR(i, 0, n){
        int j = vi[i].x.y;
        int k = vi[i].y;
        mat[j][k] = 1;
    }
    FOR(k, 0, n/2){
        mat[0][k] = 1;
        mat[1][k] = 1;
    }
    FOR(i, 0, 2){
        FOR(j, 0, n)
        printf("%d",mat[i][j]);
        printf("\n");
    }
    return 0;
}