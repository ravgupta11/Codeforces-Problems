#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <math.h>
#include <set>
#define pb push_back
#define ll long long int
#define fi first
#define se second
using namespace std;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,int> pl;
typedef set< pair<ll,int> > s;
typedef pair<pair<int,int>, pair<int,int> > pt;
const short INF = 1000;
const int MAXN = 20;
short dp[(1<<MAXN)+5][MAXN];
//int bits[(1<<MAXN)-1];
int N,M;
void init(){
    for(int  i =0;i<(1<<MAXN);i++)
        for(int j =0;j<=N;j++)
            dp[i][j] =-1;
}

vector<int> G[MAXN];

short f(int mask,short t){
    if(mask==((1<<N)-1)) return 0;
    if(dp[mask][t]!=-1) return dp[mask][t];
    short MIN = INF;
    for(int u = 0;u<N;u++){
        if(mask&(1<<u)) continue;
        short dega=0,degb=0;
        for(int v:G[u]){
            if((mask&(1<<v)))
                dega++;
            else
                degb++;
        }
        MIN = ((dega*t - degb*t + f(mask|(1<<u),t+1))<MIN)?(dega*t - degb*t + f(mask|(1<<u),t+1)):MIN;
        
    }
    return dp[mask][t]=MIN;
}
int main(){
    scanf("%d %d",&N,&M);
    for(int i =0;i<M;i++){
        int u,v;
        scanf("%d %d",&u,&v);u--;v--;
        G[u].pb(v);
        G[v].pb(u);
    }
    init();
    short ans = f(0,1);
    printf("%hu",ans);
    return 0;
}
