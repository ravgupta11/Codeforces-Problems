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
#include <sstream>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#define  ll long long int
#define pb push_back
#define x first
#define y second
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a; i>b; i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;
const int MAXN = 1000006;

int n;
vector<int> G[MAXN];
int arr[MAXN], id[MAXN], ng[MAXN];

void in(){
    ri(n);
    FOR(i, 0, n) ri(arr[i]);
}

void init(){
    FOR(i, 0, n) arr[i] = n - arr[i];
    FOR(i, 0, n) G[arr[i]].pb(i);
    FOR(i, 0, n) ng[arr[i]] = G[arr[i]].size()/arr[i];
}
bool check(){
    FOR(i, 0, n)
        if(G[arr[i]].size() % arr[i] != 0)
            return false;
        return true;
}
void assign(){
    int cnt  =1;
    FOR(i, 0, n){

    }
}

int main(){
    in();
    init();
    if(!check()){
        printf("Impossible");
        return 0;
    }
    printf("Possible\n");
    assign();
    FOR(i, 0, n) printf("%d ", id[i]);
    return 0;
}