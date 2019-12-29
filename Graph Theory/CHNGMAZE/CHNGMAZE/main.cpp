#include <vector>
#include <iostream>
#define ll long long int
#include <queue>
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int MAXN = 505;
const ll INF = 1e9+9;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<pi,int> pii;
int R,C,P; char mat[21][21][21];
bool vis[21][21][21];
ll d[21][21][21];

int dx[5] ={0,0,0,1,-1};
int dy[5] ={0,1,-1,0,0};

bool isvalid(int x,int y,int p){
    if(x<0||x>=R||y<0||y>=C||mat[p][x][y]=='1') return false;
    return true;
}

void bfs(){
    FOR(p,0,P) FOR(r,0,R) FOR(c,0,C) {
        vis[p][r][c] = false;
        d[p][r][c] = INF;
    }
    queue< pii > Q;
    d[0][0][0] = 0;
    Q.push({{0,0},0});
    while(!Q.empty()){
        int r = Q.front().first.first , c = Q.front().first.second, p = Q.front().second; Q.pop();
        if(vis[p][r][c]) continue;
        vis[p][r][c] = true;
        FOR(i,0,5){
            int nr = r + dx[i], nc = c + dy[i], np = (p +1)%P;
            if(!isvalid(nr,nc,np)) continue;
            if(d[np][nr][nc] > d[p][r][c]+1){
                d[np][nr][nc] = d[p][r][c]+1;
                Q.push({{nr,nc},np});
            }
        }
    }
}

int main(){
    int it = 1;
    while(scanf("%d %d %d",&R,&C,&P)==3){
        if(R==0 && C==0) break;
        FOR(p,0,P) FOR(r,0,R)
            scanf("%s",mat[p][r]);
        bfs();
        ll MIN = INF;
        FOR(p,0,P) MIN = min(d[p][R-1][C-1],MIN);
        if(MIN==INF) printf("Case %d: Luke and Leia cannot escape.\n",it);
        else printf("Case %d: Luke and Leia can escape in %lld steps.\n",it,MIN);
        it++;
    }
    return 0;
}
