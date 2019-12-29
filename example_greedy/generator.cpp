#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define FOR(i, a, b) for(int i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a;i>b; i=i-1)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
#define all(x) x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef long double dbl;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<char> vc;
const int INF = 2e6;
const ll LINF = 8e18;
const int MOD = 1e9 + 7;
const dbl EPS = 1e-9;

int random(int l, int r) {
  int v = rand() * RAND_MAX + rand();
  v %= r - l + 1;
  return v + l;
}

int main(){
	srand(time(NULL));
	int r = random(1, 1000);
	if(r < 0) r *= -1;
	printf("%d", r);
	return 0;
}