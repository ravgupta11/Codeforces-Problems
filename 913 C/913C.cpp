#include <iostream>
#define ll long long int
#define loop(n) for (int i = 0; i < n; i++)
#define loopr(n) for (int i = n - 1; i >= 0; i--)
using namespace std;

ll n, L, cost[35], min_cost[35];
ll INF = 1e18 + 10;
bool used[35];

int main()
{
	scanf("%lld %lld", &n, &L);
	loop(n) scanf("%lld", &cost[i]);
	ll MIN = 1e9 + 1;
	loop(n)
	{
		min_cost[i] = min(2LL * MIN, cost[i]);
		MIN = min_cost[i];
	}
	ll v = (1 << (n - 1));
	ll ans = (L / v) * min_cost[n - 1];
	used[n - 1] = ((L / v) > 0);
	ll left = L % v;
	loopr(n - 1)
	{
		if (left <= 0)
			break;

		ans += (left / (1 << i)) * min_cost[i];
		if ((left / (1 << i)) == 1)
		{
			used[i] = true;
			left -= (1 << i);
		}
	}
	MIN = ans;
	ll diff = 0;
	loop(n)
	{
		if (used[i])
			diff += min_cost[i];
		else
			MIN = min(MIN, ans - diff + min_cost[i]);
	}
	ans = min(((L + v - 1) / v) * min_cost[n - 1], MIN);
	printf("%lld", ans);
	return 0;
}