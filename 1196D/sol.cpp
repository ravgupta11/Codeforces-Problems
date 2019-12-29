#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;

char T[200005];

int n;


int sliding(char * P, int n, int k, char *S){
	int l = 0, r = k - 1;
	int MAX = -1;
	int prefix[200005];
	for(int i = 0; i < n; i++) prefix[i] = (P[i] == S[i % 3]);
	for(int i = 1; i < n; i++) prefix[i] += prefix[i - 1]; 
	while(r < n){
			MAX = max(MAX, prefix[r] - (l > 0) * prefix[l - 1]);
			l++;
			r++;
		}
	return MAX;
}


int main(){;
	int q;int k;int ans;
	scanf("%d", &q);
	for(int it = 1; it <= q; it++){
		
		scanf("%d %d", &n, &k);
		scanf("%s", T);
	
		ans = max( max(sliding(T, n, k, "RGB"), sliding(T, n, k, "GBR") ), sliding(T, n, k, "BRG") );

		printf("%d\n", k - ans);
	}
	return 0;
}