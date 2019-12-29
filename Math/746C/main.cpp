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
int s, x2, x1, t1, t2, p, d;

int main(){
    ri(s); ri(x1); ri(x2); ri(t1); ri(t2); ri(p); ri(d);

    if(t1>t2){
        printf("%d", abs((x2-x1))*t2);
        return 0;
    }
    int MIN = abs((x2-x1))*t2;
    if(x1<x2) {
        if (d == 1) {
            if (p <= x1)
                MIN = min(MIN, abs((x2 - p)) * t1);
            if (p > x1)
                MIN = min(MIN, abs((s - p)) * t1 + (s + x2) * t1);
        } else
            MIN = min(MIN, (p + x2) * t1);
    }
    else{
        if (d == 1) {
            MIN = min(MIN, (2*s - p -x2) * t1);
        } else {

            if (p >= x1)
                MIN = min(MIN, abs((x2 - p)) * t1);
            if (p < x1)
                MIN = min(MIN, p * t1 +  s * t1 + (s-x2)*t1);
        }
    }
    printf("%d", MIN);
    return 0;
}