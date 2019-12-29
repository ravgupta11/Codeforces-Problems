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
const int MAXN = 2e5+5;
char alpha[200] = {'0','1','2','3','4','5','6','7','8','9','!','@','#','$','%','^','&','*','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h', 'i' ,'j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int str[MAXN];
int zet[MAXN], pre[MAXN];
int n;

void z_function() {
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            zet[i] = min (r-i+1, zet[i-l]);
        while (i+zet[i] < n && str[zet[i]] == str[i+zet[i]])
            ++zet[i];
        if (i+zet[i]-1 > r)
            l = i,  r = i+zet[i]-1;
    }
}
void calc(){
    int it1 = 1;
    str[0] = 'a';
    FOR(it, 1, n){
        if(pre[it] == 0) {
            str[it] = alpha[it1++];
        }
        else str[it] = str[pre[it]-1];
    }
}

int main(){
    ri(n);
    FOR(i, 0, n)
        zet[i] = 0;
    FOR(i, 0, n)
        ri(pre[i]);
    calc();
    z_function();
    FOR(i, 0, n) printf("%d ", zet[i]);
    return 0;
}

