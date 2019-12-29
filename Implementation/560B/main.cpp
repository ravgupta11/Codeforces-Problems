#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
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

struct p{
    ll l,w;
};

bool in(struct p a, struct p b){
    if(a.l<=b.l && a.w<=b.w) return true;
    if(a.w<=b.l && a.l<=b.w) return true;
    return false;
}

struct p union1(struct p a, struct p b){
    struct p c;
    c.l = b.l + a.l;
    c.w = max(b.w ,a.w);
    return c;
}

struct p union2(struct p a, struct p b){
    struct p c;
    c.l = b.l + a.w;
    c.w = max(b.w , a.l);
    return c;
}

struct p union3(struct p a, struct p b){
    struct p c;
    c.w = b.w + a.w;
    c.l = max(b.l ,a.l);
    return c;
}
struct p union4(struct p a, struct p b){
    struct p c;
    c.l = max(b.l , a.w);
    c.w = b.w + a.l;
    return c;
}
int main(){
    struct p fr, a, b;
    rl(fr.l); rl(fr.w);
    rl(a.l); rl(a.w);
    rl(b.l); rl(b.w);
    if(in(union1(a,b), fr)||in(union2(a,b), fr)||in(union3(a,b), fr)||in(union4(a,b), fr)) printf("YES");
    else printf("NO");
    return 0;
}



