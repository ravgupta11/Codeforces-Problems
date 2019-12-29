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
#define x first
#define y second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a; i>b; i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;

typedef pair<int,int > pi;

vector<pi > pairs;

int main(){
    int n;
    ri(n);
    FOR(i, 0, n){
        int u,v;
        ri(u);ri(v);
        pairs.pb({u,v});
    }
    sort(pairs.begin(), pairs.end());
    int MAX = -1;
    int cnt = 0;
    FOR(i, 0, n){
        if(pairs[i].y > MAX){
            MAX = pairs[i].y;
        }
        else{
            cnt++;
        }
    }
    printf("%d\n", cnt);
}