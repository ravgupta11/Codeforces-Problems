#include <iostream>
using namespace std;

int ans[100004][22];
int a[100004], n, k, q;

void pre(){
	for(int i = 0; i < n; i++) ans[i][0] = a[i];
	int two = 1;
	for(int sz = 1; sz < k+1; sz++){
		for(int i = 0; i + (2*two - 1) < n; i ++){
			ans[i][sz] = (ans[i][sz - 1] + ans[i + two][sz - 1]);
		}
		two *= 2;
	}
}


int query(int l, int r){
	int len = r - l + 1;
	int sz =0;
	while(len > 1){
		sz ++;
		len /= 2;
	}
	int cand = (ans[l][sz] / 10);
	return cand;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	k = 0;
	int m = n;
	while(m > 1){
		k++;
		m /= 2;
	}

	pre();
	scanf("%d", &q);
	for(int i =0; i < q; i++){
		int l, r;
		scanf("%d %d", &l, &r);
		l--, r--;
		printf("%d\n", query(l, r));
	}
	return 0;
}