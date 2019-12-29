#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

#define ll long long int
#define pb push_back

#define y second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a; i>b; i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;

int main(){
    int a;
    vector<int> vec;
    string s;
    getline(cin, s);
    getline(cin, s);
    stringstream ss;
    ss<< s;
    vec.resize(1000000);
    int n = 0;
    while(ss >> vec[n])
        n++;
    FOR(i,0,n)
    {
        cout<<vec[i];
    }
}