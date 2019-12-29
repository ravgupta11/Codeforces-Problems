#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <math.h>
#include <set>
#define pb push_back
#define ll long long int
using namespace std;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector< vector<short> > vii;
typedef pair<int,int> pi;
typedef pair<ll,int> pl;
typedef set< pair<ll,int> > s;
const int MAXN = 1003;
int r,c;
vi G[MAXN];
vector<int> C;
char mat[MAXN][MAXN];
int dx[] = {+1,-1,0,0};
int dy[] = {0,0,-1,1};
bool vis[MAXN][MAXN];

bool valid(int x,int y){
    if(x<0||y<0||y>=c||x>=r) return false;
    if(mat[x][y]=='#') return false;
    return true;
}
int cnt;
void dfs(int x,int y){
    vis[x][y] = true;
    for(int it=0;it<4;it++){
        int x1 =x+dx[it];int y1 = y+dy[it];
        if(!valid(x1,y1)||vis[x1][y1]) continue;
        if(mat[x1][y1]=='C') cnt++;
        dfs(x1,y1);
    }
}
void print(vi &V){
    vi::iterator it;
    for(it =V.begin();it!=V.end();it++)
        printf("%d ",(*it));
    printf("\n");
}
void init(){
    for(int i=0;i<r;i++)
        for(int j =0;j<c;j++)
            vis[i][j] =false;
}
int main(){
    scanf("%d %d",&r,&c);
    for(int i =0;i<r;i++)
        scanf("%s",mat[i]);
    
    init();
    for(int i =0;i<r;i++){
        for(int j=0;j<c;j++){
            if(vis[i][j]||!valid(i,j)||mat[i][j]!='R') continue;
            init();
            cnt =0;
            dfs(i,j);
            C.pb(cnt);
        }
    }
    print(C);
    return 0;
}
