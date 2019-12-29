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

#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FORR(i, a, b) for(ll i = a; i>b; i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;
const int MAXN = 1e6+1;

vector<int> T1, T2;

void prefix(string s, vector<int> &t){
    FOR(i, 0, s.length()+1) t.pb(0);
    FOR(i, 1, s.length()){
        int pos = t[i-1];
        while(pos != 0 && s[pos] != s[i]) pos = t[pos -1];
        if(s[pos] == s[i]) t[i] = pos+1;
    }
}

int main(){
    string s1, s2;
    cin>> s2;
    s1 = s2;
    reverse(s2.begin(), s2.end());
    prefix(s1, T1);
    prefix(s2, T2);
    reverse(T2.begin(), T2.end());
    FOR(i, 1, s1.length()+1) T2[i-1] = T2[i];
    int MAX = -1;
    int maxi = 0;
    FOR(i, 1, s1.length()) {
        int j = i - T1[i]+1;
        if (T1[i] == T2[j]) MAX = max(MAX, T1[i]);
        if(MAX == T1[i]) maxi  = j;
    }
    FOR(i, 0, MAX) {
        int j = maxi + i;
        printf("%c", s1[i]);
    }
    if(MAX <= 0) printf("Just a legend");
    return 0;
}