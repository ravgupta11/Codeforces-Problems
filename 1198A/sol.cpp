#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int n, I, K = 0, prefix[500004];

map<int, int> f;
vector<int> freq, a;

int calculate(int i){
	if(i == 1) return 0;
	int ans = 0;
	long long value = 1;
	while(value < i){//O(Log(N))
		value *= 2;
		ans++;
	}
	return ans;
}

int main(){
	
	scanf("%d %d", &n, &I);

	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		a.push_back(val);
	}

	for(int i =0; i < n; i++) f[a[i]] = 0;
	for(int i =0; i < n; i++) f[a[i]]++;

	int lo = 0, hi = n;
	while(hi - lo > 1){
		int mi = lo + (hi -  lo)/2;
		int k = calculate(mi);
		if(n * k <= 8 * I )
			lo = mi;
		else
			hi = mi;
	}
	for(int i = hi; i >= lo; i--){
		int k = calculate(i); 
		if( n * k <= 8 * I ){
			K = i;
			break;
		}
	}

	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	for(int ai : a) freq.push_back(f[ai]);

	prefix[0] = freq[0];
	for(int i =1; i < (int) freq.size(); i++) 
		prefix[i] = prefix[i - 1] + freq[i];

	if(K == 0 || K >= (int) a.size()){
		cout<<0;
		return 0;
	}

	int l = 0, r = K - 1;
	int MAX = -1;
	while(r < (int) a.size()){
		MAX = max(MAX, prefix[r] - prefix[l] + freq[l]);
		r++;
		l++;
	}
	cout << n - MAX;
	return 0;
}