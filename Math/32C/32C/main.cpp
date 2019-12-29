#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
#define ll long long int
#define FOR(i,a,b) for(int  i= a;i<b;i++)
#define rl(x) scanf("%lld ",&x);
#define rll(x,y) scanf("%lld %lld",&x,&y);
#define rs(x) scanf("%s",x);
int R,C,s;


int main() {
    scanf("%d %d %d",&R,&C,&s);
    ll mi =0,mj =0;
    ll lx =0;
    FOR(i,0,C)
    lx = max(lx,(ll)((C-i-1)/s + i/s +1));
    FOR(i,0,C)
    if((C-i-1)/s + i/s +1 == lx) mi++;
    ll ly = 0;
    FOR(i,0,R)
    ly = max(ly,(ll)((R-i-1)/s + i/s +1));
    FOR(i,0,R)
    if((R-i-1)/s + i/s +1 == ly) mj++;
    ll ans = mi*mj;
    printf("%lld",ans);
}
