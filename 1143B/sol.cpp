//incorrect
#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORR(i, a, b) for (int i = a; i > b; i = i - 1)
#define ri(x) scanf("%d", &x);
#define rl(x) scanf("%lld", &x)
using namespace std;
#define DEBUG 0
typedef long long ll;
typedef long double dbl;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<char> vc;

string d;
int _pow[10000];

ll binpow(int a, int n)
{	
	int it = 0;
	for(int i = n; i > 0;i /= 2)
		_pow[it++] = i % 2;
	ll ans = 1;
	for(int i = it - 1; i  > -1; i--){
		ans *= ans;
		if(_pow[i]) ans *= a;
	}
	return ans;
}



ll get_product_2(int it){
	if(it == d.length()) return 1;

	int fi = (d[it] - '0') - 1;
	ll ans = 0;
	if(fi == -1) ans = 0;
	else if(fi == 0) ans = get_product_2( it + 1);
	else ans = max( fi * binpow(9, d.length() - it - 1) , (fi + 1) * get_product_2(it + 1) );
	/*string sp = "";
	for(int i =0; i < it;i++) sp += ' ';
	printf("%s %lld\n", sp.c_str(), ans);*/
	return ans;
}

int main()
{
	//clock_t begin = clock();
	ll n;
	rl(n);
	d = to_string(n);
	ll ans =  max( (d[0] - '0') * get_product_2(1), (d[0] == '1' ? 1 : (d[0] - '0' - 1) ) * binpow(9, d.length() - 1));

	printf("%lld\n", ans);
	//printf("%lf\n", (double) (clock() - begin) / CLOCKS_PER_SEC);
	return 0;
}