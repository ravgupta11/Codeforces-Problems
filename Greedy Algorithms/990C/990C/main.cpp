#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

#define ll long long int
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a; i>b; i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;

typedef vector<ll> vl;
typedef vector<int> vi;
const int MAXN = 3e5+1;
ll OP[MAXN], CL[MAXN], RG;
vector<string > BR;

int check(int k){
    ll open1 = 0, close1 = 0, open2 = 0, close2 =0;
    bool c1 = true, c2 = true;
    int N = (int) BR[k].length();
    FOR(i, 0, N){
        if(BR[k][i] == ')') close1++;
        else if( BR[k][i] == '(') open1++;
        if(close1 > open1){
            c1 = false;
            break;
        }
    }
    FORR(i, N-1, -1){
        if(BR[k][i] == ')') open2++;
        else if( BR[k][i] == '(') close2++;
        if(close2 > open2){
            c2 = false;
            break;
        }
    }
    if(c1||c2){
        if(close2 == open2 || close1 == open1){
            CL[0]++; OP[0]++;
        }
        else if(c1) OP[open1 - close1]++;
        else if(c2) CL[open2 - close2]++;
    }
    return N;
}

int main() {
    int N; ri(N);
    FOR(i, 0, N){
        string c;
        cin>> c;
        BR.pb(c);
    }
    FOR(i, 0, N){
        int m =check(i);
    }
    ll pairs = 0;
    FOR(i, 0, MAXN)
        pairs += CL[i]*OP[i];
    printf("%lld", pairs);
    return 0;
}
