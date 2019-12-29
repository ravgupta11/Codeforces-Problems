#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define FOR(i, a, b) for(int i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a;i>b; i=i-1)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define print(x) for(auto i: x) cout<<i<<" "
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


int n, a[INF];
bool rec[INF];

void read(){
	ri(n);
	FOR(i, 0, n)
		ri(a[i]);
}

void find_rec(){
	int MAX = 0;
	FOR(i, 0, n){
		if(a[i] > MAX)
			rec[i] = 1;
		MAX = max(MAX, a[i]);
	}
}

int find_ans(){
	int MAX = 0, cnt_max =0, i =0;
	while(i < n){
		int cnt = 0;
		int j = i + 1;
		while(rec[i] && j < n &&!rec[j]){
			if (a[j] > MAX)
				cnt++;
			MAX = max(MAX, a[j]);
			j++;
		}
		MAX = a[i];
		i = j;
		if(cnt > 1) cnt_max = max(cnt_max, cnt);
		
	}

	//construction of solution 
	int ans = INF;
	bool flag = 0;
	
	if(cnt_max < 2){
		FOR(i, 0, n)
			if(!rec[i]){
				ans = min(ans, a[i]);
				flag = 1;
			} 
		if(!flag){
			FOR(i, 0, n)
				ans = min(ans, a[i]);
		}
	}
	else{
		MAX = 0, i = 0;
		while(i < n){
			int cnt = 0;
			int j = i + 1;
			while(rec[i] && j < n &&!rec[j]){
				if (a[j] > MAX)
					cnt++;
				MAX = max(MAX, a[j]);
				j++;
			}
			
			if(cnt_max == cnt)
				ans = min(ans, a[i]);
			
			MAX = a[i];
			i = j;
		}
	}
	return ans;
}

int main(){
	read();
	if(n == 1){
		printf("%d\n", a[0]);
		return 0;
	}
	find_rec();
	int ans = find_ans();
	printf("%d\n", ans);
	return 0;
}