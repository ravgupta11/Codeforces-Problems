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
#include <sstream>
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
int A[1<<5];

void binary(int mask){
    if(!mask) return;
    else {
        binary(mask/2);
        printf("%d", mask%2);
    }
}

int operate(int ai, int o, int aj){
    if(o == 0) return ai+aj;
    if(o == 1) return ai-aj;
    return ai*aj;
}

bool permute(int E, int mask){
    if(E == 23 && !mask) return true;
    if(!mask) return false;
    bool ans = false;
    FOR(k, 0, 3){
        for(int j = 1; j<(1<<5); j = j<<1){
            if(!(j & mask)) continue;
            int aj = A[j];
            ans = permute(operate(E, k, aj), mask - j);
            if(ans) return true;
        }
    }
    return ans;
}

int main(){
    while(1){
        int mask = (1<<5) -1;
        bool flag = 1;
        for(int j = 1; j< (1<<5); j = j<<1){
            int u; ri(u);
            A[j] = u;
            if(u != 0) flag  =0;
        }
        if(flag) break;
        for(int j = 1; j < (1<<5); j = j<<1){
            if(flag) break;
            if(permute(A[j], mask - j)) flag = 1;
        }
        if(flag) printf("Possible\n");
        else printf("Impossible\n");
    }
    return 0;
}