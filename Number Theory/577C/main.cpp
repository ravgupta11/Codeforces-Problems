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
#define dbl double long

using namespace std;

vector<int> p1, p2;
bool prime[100005];
int N;

void sieve(int N){
    FOR(i,2, N+1) if(!prime[i]){
            p1.pb(i);
            for(int j = i*i;j<=N;j+= i) prime[j] = true;
        }
}
int main(){
    ri(N);
    sieve(N);
    for(int i : p1){
        int j = i;
        while(j*i<= N){
            p2.pb(j*i);
            j*=i;
        }
        p2.pb(i);
    }
    printf("%ld\n", p2.size());
    for(int i: p2) printf("%d ", i);
    return 0;
}
