#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <math.h>
#include <algorithm>
#include <set>
#define pb push_back
#define ll long long int
#define ri(x) scanf("%d", &x)
#define rd(x) scanf("%Lf", &x);
#define x1 first
#define x2 second
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define dbl long double
using namespace std;


const dbl EPS = 1e-9;
const dbl INF = 1e9+9;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<dbl,dbl> pt;
typedef pair<dbl,dbl> pdb;
typedef vector< pdb > vpd;
typedef set< pair<ll,int> > s;
int N;
vpd LS;

dbl f(dbl x){
    dbl d = 0;
    FOR(i, 0, N)
        d += min(abs(LS[i].x1-x), abs(LS[i].x2-x));
    return d;
}

dbl ternary(dbl hi, dbl lo){
    while(hi-lo>EPS){
        dbl m1 = lo + (hi - lo)/3;
        dbl m2 = hi - (hi - lo)/3;
        if(f(m1) - f(m2) > EPS) lo = m1;
        else hi = m2;
    }
    return lo;
}

int main(){
    ri(N);
    FOR(i, 0, N){
        dbl x, nx;
        rd(x); rd(nx);
        LS.pb({x,nx});
    }
    dbl maxx = -INF, minx = INF;
    FOR(i, 0, N){
        maxx = max(maxx, LS[i].x2);
        minx  = min(minx, LS[i].x1);
    }
    dbl ans = f(ternary(maxx,minx));
    printf("%Lf",ans);
    return 0;
}
/*#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
struct dat{
    int lef,righ;
}a[100005];
vector <long long>v;
long long n,i,ans,caut;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i].lef>>a[i].righ;
        v.push_back(a[i].lef);
        v.push_back(a[i].righ);
    }
    sort(v.begin(),v.end());
    ans=0;
    caut=v[v.size()/2];
    for(i=1;i<=n;i++)
    {
        if(a[i].lef<=caut && caut<=a[i].righ)
            continue;
        if(a[i].lef>caut)
        {
            ans+=a[i].lef-caut;
            continue;
        }
        ans+=caut-a[i].righ;
    }
    cout<<ans<<'\n';
}*/

