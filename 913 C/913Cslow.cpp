#include <iostream>
#define ll long long int
#define loop(i, n) for(ll i = 0; i < n; i++)
#define loopr(i, n) for(ll i = n - 1; i >=0; i--)
using namespace std;

ll n, L, c[35], w[35];
const ll INF =  1e9 + 10;
ll dp[32][INF];

ll func(int i, ll left ){
	if(i == n && left > 0) return INF;
	if(left <= 0) return 0;
	if(dp[i][left] != -1) return dp[i][left];
	return dp[i][left] = min(func(i, left - w[i]) + c[i], func(i + 1, left) );
 }


 int main(){
 	scanf("%lld %lld", &n, &L);

	loop(i, n) scanf("%lld", &c[i]);
	loop(i, n) w[i] = 1 << (i);

	loop(i, n) loop(j, L + 5) dp[i][j] = -1;

	ll ans = func(0, L);
	printf("%lld", ans);

	return 0;
 }