#include <iostream>
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
const int MAXN = 102;
vi G[MAXN];
bool vis[MAXN];
short n;
bool check;

void dfs(int s,int p){
    printf("");
    vis[s] = true;
    for(int u:G[s]){
        if(vis[u]){
            if(u!=p){
                check = true;
                break;
            }
            continue;
        }
        dfs(u,s);
    }
}

void init(){
    for(int i =0;i<n;i++){
        vis[i] = false;
    }
}
int main(){
    scanf("%hu",&n);
    for(short i =0;i<n;i++){
        for(short j =0;j<n;j++) {
            short key;
            scanf("%hu",&key);
            if(key)
                G[i].pb(j);
        }
    }
    check =false;
    init();
    dfs(0,-1);
    for(int i =0;i<n;i++)
        if(!vis[i]) check =true;
    if(check){
        printf("NO");
    }
    else{
        printf("YES");
    }
    return 0;
}
