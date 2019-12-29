#include <iostream>
using namespace std;
int n;
int a[100004];
int b[100004], c[100004];

int mod(int j){ return ((j + n) % n);}

bool check(int b[]){
	for(int i = 0; i < n; i++){
		if(b[i] >= b[mod(i - 1)] + b[mod(i + 1)])
			return false;
	}
	return true;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		sacnf("%d", &a[i]);
	}
	sort(a, a + n, greater<int> ());
	b[0] = a[0];
	b[n - 1] = a[1];
	b[1] = a[2];
	c[0] = a[0];
	c[n - 1] = a[2];
	c[1] = a[1];

	int j = 3;
	for(int i = 2; i < n - 1; i++){
		c[i] = b[i] = a[j];
		j++;
	}
	if(check(b) == 0 && check(c) == 0){
		printf("NO\n")
	}
	else{
		printf("YES\n");
		if(check(b)){
			for(int i = 0; i < n; i++) printf("%d ", b[i]);
		}
		else{
			for(int i = 0; i < n; i++) printf("%d ", c[i]);
		}
	}
	return 0;
	
}
