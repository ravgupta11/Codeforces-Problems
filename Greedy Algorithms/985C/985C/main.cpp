#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

#define ll long long int
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i,a,b) for(int i = a;i>b;i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;

typedef vector<ll> vl;
typedef vector<int> vi;

int N, K;ll L;
vl A;

int main(){
    ri(N); ri(K); rl(L);
    int M = N*K;
    FOR(i, 0, M){
        ll u; rl(u); A.pb(u);
    }
    sort(A.begin(), A.end());
    ll s = 0;
    ll lt = K-1;
    ll rem = N;
    FORR(i,M-K, -1){
        if(A[i] - A[0] > L){
            lt++;
            continue;
        }
        if(lt>=K-1){
            rem--;
            lt -= K-1;
            s+= A[i];
        }
        else{
            lt++;
        }
    }
    if(!rem)
        printf("%lld", s);
    else
        printf("0");
    return 0;
}
