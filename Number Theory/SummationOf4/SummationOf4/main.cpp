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
const int MAXN =1e7+1;
bool prime[MAXN];
vi p;
int n;

void sieve(){
    FOR(i, 2, MAXN) prime[i] = true;
    FOR(i, 2, MAXN){
        if(prime[i]){
            p.pb(i);
            for(int j = i*i; j<MAXN && j>0; j+=i) prime[j] =false;
        }
    }
}

pair<int, int> divide(int num){
    int p3 = 0, p4 = 0;
    for(int j: p){
        if(!prime[num-j]) continue;
        p3 = j; p4 = num-j;
        break;
    }
    return {p3,p4};
}

void solve(){
 while(ri(n) != EOF){
    int p1 =0, p2=0, p3 = 0, p4 = 0;
    if(n<8){
        printf("Impossible.\n");
        continue;
    }
    if(n%2==0){
        p1 = 2;p2 = 2;
        pair<int, int> p = divide(n-4);
        p3 = p.x; p4 = p.y;
    }
    else{
        p1 = 2; int o1 = n-2; int e1 = 0;
        for(int j: p){
            if((o1-j)%2==0 && (o1-j)>2){
                p2 = j; e1 = o1-j;
                break;
            }
        }
        pair<int, int> p = divide(e1);
        p3 = p.x; p4 = p.y;
    }
     if(p3==0){
         printf("Impossible.\n");
         continue;
     }
     printf("%d %d %d %d\n",p1,p2,p3,p4);
    }
}

int main(){
    sieve();
    solve();
    return 0;
}

