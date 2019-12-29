
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

vector< pair<int, int> > E;

int n,m,p;
int main(){
    ri(n); ri(p);
    int m = 2*n +p;
    FOR(k, 1, 4)
        FOR(i, 0, n-k) {
            if(i+k>=n || m==0) break;
            E.pb({i, i+k}); m--;
        }
    for(int i = 4; i<n && m!=0;i++){
        for(int j = 0; j+i<n && m!=0;j++){
            E.pb({j,j+i});
            m--;
        }
    }
    FOR(i, 0, E.size())
        printf("%d %d\n", E[i].first, E[i].second);
    return 0;
}