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
const int MAXN = 1e6+5;



bool allzero(char s1[], int n1){
    FOR(i, 0, n1) if(s1[i] == '1') return false;
    return true;
}

int main(){
    char s[MAXN], t[MAXN];
    scanf("%s", s);
    scanf("%s", t);
    int n1 = (int) strlen(s);
    int n2 = (int) strlen(t);
    //printf("%d %d\n", allzero(s, n1), allzero(t, n2));
    if(n1 == n2 && allzero(s, n1) == allzero(t, n2)) printf("YES");
    else printf("NO");
    return 0;
}