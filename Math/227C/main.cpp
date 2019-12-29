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
#define MAT struct mat
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a; i>b; i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
#define dbl double long

using namespace std;

int N, M;

MAT{
    ll a11, a12, a21, a22;

    void print(){
        printf("%lld %lld\n%lld %lld\n", a11, a12, a21, a22);
    }
};


MAT operator*(const MAT &A, const MAT &B){
    MAT C;
    C.a11 = A.a11*B.a11 + A.a12 * B.a21;
    C.a12 = A.a11*B.a12 + A.a12 * B.a22;
    C.a21 = A.a21*B.a11 + A.a22 * B.a21;
    C.a22 = A.a21*B.a12 + A.a22 * B.a22;
    return C;
}
MAT binexpo(MAT A, ll k){
    if(k==1)
        return A;
    MAT ans = binexpo(A, k/2);
    ans = ans*ans;
    if(k%2 == 1)
        ans = ans*A;
    return ans;
}

int main(){
    rl(N); rl(M);
    MAT A;
    A.a11 = 3; A.a12 = 2; A.a21 = 0; A.a22 = 1;
    if(N==1) {
        printf("%lld",2%M);
        return 0;
    }
    MAT B = binexpo(A, N-1);
    ll ans=  (B.a11*2 + B.a12*1)%M;
    printf("%lld", ans);
    return 0;
}