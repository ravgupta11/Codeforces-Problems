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
const int MAXN = 2e5+5;

vector<pair<int, int> > S;
int row[104], col[104];

int cnt[10004];

int main(){
    int n, m;
    ri(n); ri(m);
    for(int i = n, j = 0; j<=m && i>-1; i-- ,j++)
    if(i+j >0 && !row[i] && !col[j]) {
        S.pb({i, j});
        row[i] = 1;
        col[j] = 1;
    }
    printf("%ld\n", S.size());
    for( auto it = S.begin(); it != S.end(); it++){
        printf("%d %d\n", (*it).x, (*it).y);
    }
    return 0;
}