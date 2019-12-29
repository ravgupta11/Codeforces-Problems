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
const int MAXN = 1e5+5;

int arr[MAXN];
vector<int> D;
int main(){
    int n;
    ri(n);
    FOR(i, 0, n) ri(arr[i]);
    int m= n;
    for(int i = 2;i*i<=n;i++){
        if(m % i != 0) continue;
        int p = 0;
        while(m % i == 0){
            m /= i;
            p++;
        }
        if(i == 2 && p>=2) D.pb(4);
        else D.pb(i);
    }
    if( m > 1) D.pb(m);
    for(int i: D){
        if(i <=2) continue;
        int d = n/i;
        FOR(j, 0, d){
            int s = 0;
            for(int k = j; k<n; k+= d) s+= arr[k];
            if(s==i){
                printf("YES");
                return 0;
            }
        }
    }
    printf("NO");
    return 0;
}