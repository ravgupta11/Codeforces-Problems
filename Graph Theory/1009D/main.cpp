#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstring>
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
int n, m;
vector<pair<int, int> > E;
vector<int> G[MAXN];

ll gcd(ll a, ll b){
    if(a==0) return b;
    return gcd(b%a, a);
}




int main(){
    ri(n); ri(m);
    FOR(i, 1, n){
        if(gcd(i, i+1)==1){
            G[i].pb(i+1);
            G[i+1].pb(i);
            E.pb({i,i+1});
            m--;
        }
    }
    for(int i = n; i>=1 && m>0; i--){
        for(int j =i-2;j>=1 && m>0; j--){
            if(gcd(min(i,j), max(i,j)) == 1){
                G[j].pb(i); G[i].pb(j);
                E.pb({i,j});
                m--;
            }
        }
    }

    if(m!=0){
        printf("Impossible");
        return 0;
    }
    printf("Possible\n");
    FOR(i, 0, E.size())
        printf("%d %d\n", E[i].x, E[i].y);
    return 0;
}