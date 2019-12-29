#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <math.h>
#include <set>
#include <map>
#define pb push_back
#define ll long long int
#define fi first
#define se second
using namespace std;
const int MAXN = 2e5+5;

int T[MAXN][20];
int N;
vector<int> A;
int lv[MAXN];
int lp[MAXN];

void build(){
    for(int i = 0;i<N;i++)
        T[i][0] =A[i];
    for(int k = 1,p =2;p<N;k++,p*=2){
        for(int i = 0;i+p<N;i++)
            T[i][k] = min(T[i][k-1],T[i+p/2][k-1]);
    }
    lv[1] = 1;lp[1] =0;
    for(int i =2;i<=N;i++){//forn(i,0,N)
        lv[i] =lv[i-1];
        lp[i] =lp[i-1];
        if(2*lv[i]==i){
            lp[i]++;
            lv[i] = lv[i]*2;
        }
    }
}

int query(int l,int r){
    int len =r-l+1;
    int j = lp[len];
    int len2 = lv[len];
    return min(T[l][j],T[r-len2 +1][j]);
    
}
