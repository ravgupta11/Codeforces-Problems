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
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a; i>b; i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;

ll x, y, n;

int main(){
    rl(n); rl(x); rl(y);
    ll MAX = -1;
    y = y - n +1;
    x = x - n +1;
    if(y<0){
        printf("-1");
        return 0;
    }
    if(y*y>=x) MAX = y;
    if(MAX<1) printf("-1");
    else{
        printf("%lld\n",MAX);
        FOR(i, 0, n-1) printf("1\n");
    }
    return 0;
}
