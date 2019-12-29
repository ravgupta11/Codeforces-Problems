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
const int MAXN = 1e6+5;

ll a, b, c;
int main(){
    rl(a);
    if(a%2 == 1){
        c = (a*a +1)/2;
        b = a*a - c;
    }
    else{
        c = (a*a)/4 + 1;
        b = c-2;
    }
    if(b > 0 && c > 0) printf("%lld %lld\n", b, c);
    else printf("-1");
    return 0;
}