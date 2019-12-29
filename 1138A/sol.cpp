#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define FOR(i, a, b) for(int i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a;i>b; i=i-1)
#define ri(x) scanf("%d", &x);
#define rl(x) scanf("%lld", &x)
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
 
int N;
vi arr;
int seg[INF];
 
int main(){
	ri(N);
	FOR(i, 0, N){int x; ri(x); arr.pb(x);}
	int cur = arr[0], cnt = 0, indx = 0;
	FOR(i, 0, N){
		if(arr[i]== cur){
			cnt++;
			seg[indx] = cnt;
		}
		else{
		    indx++;
			cnt = 1;
			seg[indx] = cnt;
			cur = arr[i];
		}
	}
	int MAX = 0;
	FOR(i, 0, indx){
		int MIN = min(seg[i], seg[i+1])*2;
		MAX = max(MAX, MIN);
	} 
	printf("%d", MAX);
	return 0;
}