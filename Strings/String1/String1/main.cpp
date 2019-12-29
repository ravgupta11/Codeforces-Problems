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
const int MAXN = 2e5+5;

int zet[MAXN];
int pref[MAXN];
vector<pi > zs;
int N;
bool vis[MAXN];
int main(){
    scanf("%d",&N);
    for(int i = 0;i<N;i++)
        scanf("%d",&zet[i]);
    for(int i =0;i<N;i++)
        pref[i]  =0;
    int bst = 0;
    for(int i=1;i<N;i++){//O(N)
        if(zet[i]-1<0) continue;
        if(i+zet[i]-1<=bst) continue;
        for(int j =zet[i];i+j-1>bst;j--)
            pref[i+j-1] = max(j,pref[i+j-1]);
        bst =i+zet[i]-1;
    }
    for(int i =0;i<N;i++)
        printf("%d ",pref[i]);
}
