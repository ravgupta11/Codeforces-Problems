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
typedef vector<short> vi;
typedef vector< vector<short> > vii;
typedef pair<int,int> pi;
typedef pair<ll,int> pl;
typedef set< pair<ll,int> > s;
const int MAXN = 505;
short n;
vi G[MAXN];
bool vis[MAXN];
short par[MAXN];
vi path;

void dfs(short s,short p){
    vis[s] = true;
    par[s]= p;
    for(short u: G[s]){
        if(vis[u]) continue;
        dfs(u,s);
    }
}

void path_calc(short b){
    int t = b;
    while(par[t] != t&&par[t]!=-1){
        path.pb(t);
        t = par[t];
    }
    path.pb(t);
    reverse(path.begin(),path.end());
}
void print( vi &p){
    vi::iterator it;
    for(it=p.begin();it!=p.end();it++){
        printf("%d ",(*it)+1);
    }
}
int main(){
    short a,b;
    scanf("%hu %hu %hu",&n,&a,&b);
    a--;b--;
    for(short i =0;i<n;i++){
        for(short j =0;j<n;j++) {
            short key;
            scanf("%hu",&key);
            if(key)
                G[i].pb(j);
        }
    }
    for(short i=0;i<n;i++){
        vis[i] = false;
        par[i] =-1;
    }
    
    par[a] =a;
    dfs(a,a);
    path_calc(b);
    if(par[b]==-1){
        printf("-1");
    }
    else{
        printf("%d\n",path.size()-1);
        print(path);
    }
}
