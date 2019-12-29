#include <iostream>
using namespace std;

bool query(int n, int k){
	if(n == 0) return 0;
	else if(n == 1) return 1;
	else{
		if(k % 3 == 0){
			n = n % (k + 1);
			if(n % 3 == 0 && n != k) return 0;
			return 1; 
		}
		else if( n % 3 == 0) return 0;
		else return 1;
	}
}


int main(){
	int q;
	scanf("%d", &q);
	int n, k;
	for(int i =0; i < q; i ++){
		scanf("%d %d", &n, &k);
		bool ans = query(n, k);
		printf("%s", ans ? "Alice\n" : "Bob\n");
	}
	return 0;
}