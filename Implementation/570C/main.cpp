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
const int MAXN = 3e5+5;
typedef pair<int, pair<int, int> > piii;

int b[MAXN];
int n, m;
int qnt, len;

bool valid(int i){
    return i<n && i>-1;
}

void divide(int i){
    if(valid(i-1) && b[i-1] == 1 && valid(i+1) && b[i+1] == 1){
        qnt++;
        len--;
    }
    else if((valid(i-1) && b[i-1] == 1)||(valid(i+1) && b[i+1] == 1)) len--;
    else{
        len--;
        qnt--;
    }
}

void merge(int i){
    //printf("%d %d: ", len, qnt);
    if(valid(i-1) && b[i-1] == 1 && valid(i+1) && b[i+1] == 1){
        qnt--;
        len++;
    }
    else if ((valid(i-1) && b[i-1] == 1)||(valid(i+1) && b[i+1] == 1))
        len++;
    else{
        len++;
        qnt++;
    }
    //printf("%d %d\n", len, qnt);
}

int main(){
    ri(n); ri(m);
    char s[MAXN];
    scanf("%s", s);
    len = 0, qnt =0;
    FOR(i, 0, n){
        if(s[i]=='.') {
            b[i] = 1;
            len++;
        }
        else b[i] = 0;
    }
    b[n+1] = 0;
    FOR(i, 0, n){
        if (b[i]==1 && b[i+1] == 0) qnt++;
    }
    //printf("%d %d\n", len, qnt);
    FOR(i, 0, m){
        int in; char c;
        scanf("%d %c", &in, &c);
        in--;
        int bin =0;
        if(c=='.') bin = 1;
        if(b[in]==bin){
            printf("%d\n", len - qnt);
            continue;
        }
        if(bin)
            merge(in);
        else
            divide(in);
        b[in] = bin;
        printf("%d\n", len - qnt);
    }
    return 0;
}