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
int n, k;
multiset< pair<ll,int> > S;
vector<pair<int,int> > R;

int main(){
    ri(n); ri(k);
    FOR(i, 0, n){
        ll u; rl(u);
        S.insert({u, i});
    }
    int cnt  =0;
    FOR(i, 0, k){
        if(((S.begin())->x + 1== (S.rbegin())->x)||(S.begin()->x) == (S.rbegin()->x)) break;
        cnt++;
        pair<ll, int> p1 = *S.rbegin(), p2 = *S.begin();
        S.erase(p1);
        S.erase(p2);
        p1.x--; p2.x++;
        S.insert(p1); S.insert(p2);
        R.pb({p1.y+1, p2.y+1});
    }
    printf("%lld %d\n", (*S.rbegin()).x - (*S.begin()).x, cnt);
    FOR(i ,0, R.size()) printf("%d %d\n", R[i].x, R[i].y);
    return 0;
}