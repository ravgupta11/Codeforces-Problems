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
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector< vector<short> > vii;
typedef pair<int,int> pi;
typedef pair<ll,int> pl;
typedef set< pair<ll,int> > s;
const int MAXN = 3e5+5;
int x,y,z;

vector<int> G[MAXN];
vector<pair<int,int> > list;
bool vis[MAXN];
int N,M;
int lv[MAXN],lp[MAXN];
pair<int,int> T[MAXN][20];
vector<int> pos;

void dfs(int v,int d){
    vis[v] = true;
    list.pb({d,v});
    for(int to: G[v]){
        if(vis[to]) continue;
        dfs(to,d+1);
        list.pb({d,v});
    }
}

void build(){
    ll size = list.size();
    for(int i =0;i<size;i++){
        T[i][0] = list[i];
    }
    for(int k =1,p=2;p<=size;p*=2,k++){
        for(int i= 0;i+p<size;i++){
            //printf("%d %d : ",T[i][k-1].fi,T[i][k-1].se);
            //printf("%d %d -> ",T[i+p/2][k-1].fi,T[i+p/2][k-1].fi);
            T[i][k] = min(T[i][k-1],T[i+p/2][k-1]);
            //printf("%d %d\n",T[i][k].fi, T[i][k].se);
        }
    }
    lv[1] = 1;lp[1]= 0;
    for(int i =2;i<=size;i++){
        lv[i] =lv[i-1];
        lp[i] =lp[i-1];
        if(2*lv[i]==i){
            lv[i] *= 2;
            lp[i]++;
        }
    }
}

void find(int a,int b){
    pos.clear();
    vector<pi >::iterator it;
    for(it=list.begin();it!=list.end();it++){
        if(a==(*it).se){
            pos.pb((int)distance(list.begin(),it));
            break;
        }
    }
    //printf("pos of %d-> %d\n",a,pos[0]);
    for(it=list.begin();it!=list.end();it++){
        if(b==(*it).se){
            pos.pb((int)distance(list.begin(),it));
            break;
        }
    }
    //printf("pos of %d-> %d\n",b,pos[1]);
}

pair<int,int> query(int l,int r){
    int len =r-l+1;
    int j = lp[len];
    int len2 = lv[len];
    return min(T[l][j],T[r-len2+1][j]);
    
}
int genQ(int a1,int a2){
    return (x*a1 + y*a2 +z)%N;
}

/*void print(){
    for(int i =0;i<list.size();i++){
        for(int j =1;j<=lp[list.size()];j++)
            
    }
}*/
int main(){
    scanf("%d %d",&N,&M);
    for(int i =1;i<N;i++){
        int u;
        scanf("%d",&u);
        G[u].pb(i);
        G[i].pb(u);
}
    dfs(0,0);
    build();
    //print();
    int a1,a2;ll sum=0;int v;
    scanf("%d %d",&a1,&a2);
    scanf("%d %d %d",&x,&y,&z);
    //for(int i =0;i<list.size();i++){
        //printf("\n%d ",list[i].fi);
    //}
    for(int i =0;i<M;i++){
        find(a1,a2);
        v= query(min(pos[0],pos[1]),max(pos[0],pos[1])).se;
        sum +=v;
        //printf("\n%d %d %d\n",pos[0],pos[1],v);
        int a3 = (genQ(a1,a2)+v)%N;
        int a4 = genQ(a2,a3);
        a1 =a3;a2 =a4;
    }
    printf("%lld",sum);
    return 0;
}
