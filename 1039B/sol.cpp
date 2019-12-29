#include <iostream>
#include <ctime>
#include <cstdlib>
#define ll long long int
#define ri(x) scanf("%d",&x);
#define rl(x) scanf("%lld", &x)

using namespace std;
ll n; int k;
char ANS[10];

ll random(ll a, ll b){ // a, b always less than 45 MAXRAND 32767
	ll r = rand();
	r %= (b - a + 1);
	r += a;
	return r;
}

bool query(ll a, ll b){
	fflush(stdout);
	printf("%lld %lld\n", a, b);
	fflush(stdout);
	scanf("%s", ANS);
	fflush(stdout);
	if(ANS[0] == 'Y') return 1;
	return 0; 
}

int main(){
	srand(time(NULL));
	rl(n); ri(k);
	ll cur = -1;
	ll hi = n, lo = 1;
	bool flag = 0;
	while(!flag){
		while(hi - lo > 50){
			ll mi = lo + (hi - lo)/2;
			bool f = query(max(1LL, lo - k), min(n, mi + k));
			if(f) hi = min(mi + k, n), lo = max(1LL, lo - k);
			else lo = max(1LL, mi - k), hi = min(hi + k, n);
		}
		cur = random(lo, hi);
		flag = query(cur, cur);
		lo = max(1LL, lo - k), hi = min(n, hi + k);
	}
	fflush(stdout);
	printf("%lld", cur);
	fflush(stdout);
	return 0;
}