#include <vector>
#include <iostream>
#define ll long long int
#include <queue>
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define rii(i,j) scanf("%d %d",&i,&j);
#define ri(i) scanf("%d",&i);
using namespace std;
const int MAXN = 103;
const ll INF = 1e9+9;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<pi,int> pii;
queue<int> row,col; int R,C;
int mat[MAXN][MAXN];
int other(int first){
    if(R==first) return C;
    return R;
}
void solve(){
    
}

int main(){
    rii(R,C);
    FOR(i,0,R) FOR(j,0,C) scanf("%d", &mat[i][j]);
    int fi = min(R,C), se = other(fi);
    bool check = false;
    FOR(i,0,R) FOR(j,0,C) if(mat[i][j] != 0) check = true;
    if(check == false){
        printf("0\n");
        return 0;
    }
    if(fi==R){
        FOR(i,0,R){
            int MIN = 501;
            FOR(j,0,C) MIN = min(MIN, mat[i][j]);
            if(MIN == 0) continue;
            FOR(k,0,MIN) row.push(i+1);
            FOR(j,0,C) mat[i][j] -= MIN;
        }
        FOR(j,0,C){
            int MIN = 501;
            FOR(i,0,R) MIN = min(MIN, mat[i][j]);
            if(MIN == 0) continue;
            FOR(k,0,MIN) col.push(j+1);
            FOR(i,0,R) mat[i][j] -= MIN;
        }
    }
    else{
        FOR(j,0,C){
            int MIN = 501;
            FOR(i,0,R) MIN = min(MIN, mat[i][j]);
            if(MIN == 0) continue;
            FOR(k,0,MIN) col.push(j+1);
            FOR(i,0,R) mat[i][j] -= MIN;
        }
        FOR(i,0,R){
            int MIN = 501;
            FOR(j,0,C) MIN = min(MIN, mat[i][j]);
            if(MIN == 0) continue;
            FOR(k,0,MIN) row.push(i+1);
            FOR(j,0,C) mat[i][j] -= MIN;
        }
    }
    check = false;
    FOR(i,0,R) FOR(j,0,C) if(mat[i][j] != 0) check = true;
    if(check){
        printf("-1");
        return 0;
    }
    int ans = (int) row.size() + col.size();
    printf("%d\n",ans);
    while(!row.empty()){
        int top = row.front(); row.pop();
        printf("row %d\n",top);
    }
    while(!col.empty()){
        int top = col.front(); col.pop();
        printf("col %d\n",top);
    }
    return 0;
}
