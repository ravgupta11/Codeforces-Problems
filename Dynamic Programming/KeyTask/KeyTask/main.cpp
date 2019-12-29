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
bool vis[102][102][17];
int R,C;
ll d[102][102][17];
char mat[102][102];

bool isvalid1(int x, int y){
    if(x<0||x>=R||y<0||y>=C||mat[x][y]=='#') return false;
    return true;
}

int dx[5] ={1,-1,0,0};
int dy[5] = {0,0,1,-1};

int change(int x,int y,int mask){
    if(mat[x][y]=='b') mask =(mask | (1<<3));
    if(mat[x][y]=='g') mask = (mask | (1<<2));
    if(mat[x][y]=='r') mask = (mask | (1<<1));
    if(mat[x][y]=='y') mask = (mask | 1);
    return mask;
}

bool isvalid2(int x,int y, int mask){
    if(mat[x][y]=='B' && ((1<<3) & mask)==0) return false;
    if(mat[x][y]=='G' && ((1<<2) & mask)==0) return false;
    if(mat[x][y]=='R' && ((1<<1) & mask)==0) return false;
    if(mat[x][y]=='Y' && ((1<<0) & mask)==0) return false;
    return true;
}


void init(){
    FOR(i,0,102) FOR(j,0,102) FOR(k,0,17) {
        vis[i][j][k] = false;
        G[i][j][k].clear();
    }
}

int main(){
    while(scanf("%d %d", &R,&C), (R!=0 && C!=0)){
        FOR(i,0,R) scanf("%s", mat[i]);
        int x1=0,y1 = 0;
        FOR(i,0,R) FOR(j,0,C) if(mat[i][j]=='*'){
            x1 = i;
            y1 = j;
        }
        init();
        FOR(i,0,102) FOR(j,0,102) FOR(k,0,17){
            vis[i][j][k] = false;
            d[i][j][k] = INF;
        }
        queue<pii > Q;
        Q.push({{x1,y1},0});
        d[x1][y1][0] = 0;
        while(!Q.empty()){
            int xd = Q.front().first.first, yd = Q.front().first.second, m = Q.front().second; Q.pop();
            int mm = change(xd,yd,m);
            if(vis[xd][yd][m]) continue;
            vis[xd][yd][m] = true;
            FOR(i,0,4){
                int xdd = xd + dx[i], ydd = yd + dy[i];
                if(!isvalid1(xdd,ydd)||!isvalid2(xdd,ydd,mm)) continue;
                if(d[xdd][ydd][mm]> d[xd][yd][m]+ 1){
                    d[xdd][ydd][mm] = d[xd][yd][m] +1;
                    Q.push({{xdd,ydd},mm});
                }
            }
        }
        ll ans = INF;
        FOR(i,0,R) FOR(j,0,C)
        if(mat[i][j]=='X'){
            FOR(k,0,17)
            ans = min(ans,d[i][j][k]);
        }
        if(ans==INF) printf("The poor student is trapped!\n");
        else printf("Escape possible in %lld steps.\n",ans);
    }
    return 0;
}
