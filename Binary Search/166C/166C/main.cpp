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
typedef vector<int> vi;
vi A;
const int INF  =1e5+5;
int main(){
    int n, x1;int moves  =0;
    ri(n); ri(x1);
    FOR(i, 0, n){
        int u;
        ri(u);
        A.pb(u);
    }
    sort(A.begin(), A.end());
    if(A[n/2] == x1){
        printf("0");
        return 0;
    }
    //FOR(i, 0, n) printf("%d ", A[i]);
    int d = (int) distance(A.begin(), lower_bound(A.begin(), A.end(), x1));
    int d2 = 0;
    if(A[d] == x1){
        int MIN = INF;
        FOR(i, 0, n)
        if(x1 == A[i]){
            d = i;
            d2 = n - d - 1;
            if(d2 - d ==0 || d2-d ==1) continue;
            else if( d<d2) MIN = min(MIN,d2 - d -1);
            else if (d2<d) MIN = min(MIN,d - d2);
        }
    }
    else{
        int maxi = -1;
        FOR(i, 0, n)
            if(A[i]> x1) {maxi =i; break;}
        d = maxi;
        moves++;
        d2 = n - d;
    }
    printf("%d %d\n",d,d2);
    if(d2 - d ==0 || d2-d ==1) printf("%d",moves);
    else if( d<d2) moves+= d2 - d -1;
    else if (d2<d) moves += d - d2;
    printf("%d", moves);
    return 0;
}
