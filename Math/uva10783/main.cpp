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

int main(){
    int a, b, c, d, len, t;
    ri(t);
    FOR(it, 1, t+1) {
        ri(a);
        ri(b);
        a = min(a,b); b = max(a,b);
        if (a % 2 == 0) a = a + 1;
        if (b % 2 == 0) b = b - 1;
        if (a % 2 != 0) c = (a - 1);
        if (b % 2 != 0) d = (b - 1);
        c /= 2;
        d /= 2;
        len = d - c + 1;
        c = max(c, 0), d = max(d, 0);
        ll s = d * (d + 1) / 2 - c * (c + 1) / 2 + c;
        //printf("%d %d %d %lld",c,d,len, s);
        s = s * 2;
        s += len;
        printf("Case %d: %lld\n",it, s);
    }
}