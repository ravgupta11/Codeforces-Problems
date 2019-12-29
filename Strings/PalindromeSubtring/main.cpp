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
int pre[MAXN];

int main(){
    string s1, s2;
    cin>>s1;
    s2 = s1 + "#";
    reverse(s1.begin(), s1.end());
    s2 = s2 + s1;
    char s[MAXN];
    strcpy(s, s2.c_str());
    int n = strlen(s);
    FOR(i, 0, n) pre[i] = 0;
    FOR(i, 1, n){
        int k = pre[i-1];
        while(k>0 && s[k] != s[i]) k = pre[k-1];
        if(s[k]==s[i]) pre[i] = k+1;
    }
    int MAX = -1;
    FOR(i, n/2, n){
        MAX = max(MAX, pre[i]);
    }
    printf("%d", MAX);
    return 0;
}