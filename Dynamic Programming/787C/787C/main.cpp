#include <vector>
#include <utility>
#include <queue>
#include <iostream>
#define fi first
#define se second
#define ll long long int
#define FOR(i,a,b) for(int i = a;i<b;i++)
#define pb push_back
using namespace std;
const int MAXN = 7005;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<pi, int > pii;

bool vis[MAXN][2];
int dp[MAXN][2], K1, K2,N,cnt[MAXN][2]; vi k[2];

void print(int a){
    if(a==1) printf("Win ");
    if(a==0) printf("Lose ");
    if(a==-1) printf("Loop ");
}

void bfs(){
    queue<pii > Q;
    Q.push({{0,0},0});
    vis[0][0] = true;
    Q.push({{0,1},0});
    vis[0][1] =true;
    while(!Q.empty()){
        int n = Q.front().fi.fi, p = Q.front().fi.se, w = Q.front().se; Q.pop();
        dp[n][p] = w;
        if(w==0){
            for(int t: k[1-p]){
                int x = (n - t + N) %N;
                if(!vis[x][1-p]){
                    vis[x][1-p] = true;
                    Q.push({{x,1-p},1});
                }
            }
        }
        else{
            for(int t: k[1-p]){
                int x = (n - t + N) %N;
                cnt[x][1-p]--;
                if(cnt[x][1-p]==0 && !vis[x][1-p]){
                    vis[x][1-p] = true;
                    Q.push({{x,1-p},0});
                }
            }
        }
    }
}
int main() {
    scanf("%d",&N);
    scanf("%d",&K1);
    FOR(i,0,K1){
        int u; scanf("%d",&u); k[0].pb(u);
    }
    scanf("%d",&K2);
    FOR(i,0,K2){
        int u; scanf("%d",&u); k[1].pb(u);
    }
    FOR(i,0,N+1) FOR(j,0,2){
        vis[i][j] = false;
        dp[i][j] = -1;
    }
    FOR(i,0,N+1) cnt[i][0] = K1;
    FOR(i,0,N+1) cnt[i][1] = K2;
    bfs();
    FOR(i,1,N)
    print(dp[i][0]);
    printf("\n");
    FOR(i,1,N)
    print(dp[i][1]);
    return 0;
}
