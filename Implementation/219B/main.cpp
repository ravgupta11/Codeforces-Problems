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
int cnt(ll n){
    int ans = 0;
    while(n>1 && n%10 == 9){
        ans++;
        n /= 10;
    }
    return ans;
}
int main(){
    string s,t; ll n,p;
    cin>>s;
    rl(p);
    int len = s.length()-1;
    ll div  = 1;
    FOR(i, 0, len) div *= 10;
    stringstream ss(s);
    ss>>n;
    ll MAX = n;
    int nine = cnt(n);
    FOR(i, 0, len){
        if(n -div*(n/div)+1 <= p) {
            if(cnt(div*(n/div) -1) > nine) {
                nine = cnt(div * (n / div) - 1);
                MAX = div * (n / div) - 1;
            }
        }
        div /= 10;
    }
    printf("%lld", MAX);
    return 0;
}