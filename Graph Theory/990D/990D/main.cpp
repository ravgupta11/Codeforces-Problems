#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

#define ll long long int
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a; i>b; i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
#define ub(A,x) upper_bound(A.begin(), A.end(), x)
#define lb(A,x) lower_bound(A.begin(), A.end(), x)
using namespace std;
const int MAXN = 1e3+5;
int N,a,b, adj[MAXN][MAXN];


void print(){
    FOR(i, 0, N){
        FOR(j, 0, N)
        printf("%d",adj[i][j]);
        printf("\n");
    }
}
void inverse(){
    FOR(i, 0, N){
        FOR(j, 0, N)
            adj[i][j] = 1- adj[i][j];
        FOR(i, 0, N) adj[i][i] = 0;
    }
}
int main() {
    ri(N); ri(a); ri(b);
    if(min(a,b) > 1|| ((N==2||N==3) && (a==1 && b==1))) {
        printf("NO");
        return 0;
    }
    if(a == 1 && b == 1){
        FOR(i, 0, N-1){
            adj[i][i+1] = 1;
            adj[i+1][i] = 1;
        }
        printf("YES\n");
        print();
    }
    else{
        int c = max(a,b);
        FOR(i, 0, c-1)
            FOR(j, 0, N)
                if(i != j){
                    adj[i][j] = 1;
                    adj[j][i] = 1;
                }
        printf("YES\n");
        if(b>1)
            print();
        else{
            inverse(); print();
        }
    }
    return 0;
}
