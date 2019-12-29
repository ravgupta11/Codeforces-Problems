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
const int MAXN =1e5+5;

int t, n, k;
int arr[102];

int main(){
    ri(n); ri(k); ri(t);
    int x = (n*k*t)/100;
    int is = x/k;
    int i = x%k;
    FOR(j, 0, is)
        arr[j] = k;
    if(is<n) arr[is] =i;
    FOR(i, 0, n) printf("%d ", arr[i]);
    return 0;
}