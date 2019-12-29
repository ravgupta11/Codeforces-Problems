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
    int t;
    ri(t);
    while(t--){
        ll s, d;
        rl(s); rl(d);

        ll b = (s - d)/2;
        ll a = s - b;
        if(a+b != s || a-b !=d || d>s){
            printf("impossible");
        }
        else printf("%lld %lld", a, b);
        printf("\n");
    }
    return 0;
}