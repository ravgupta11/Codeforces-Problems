#include <iostream>
#include <string>
#include <cmath>
using namespace std;
double a[100005];
int b[100005];
double x[100005];
int n;



int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%lf", &a[i]);
	}
    
	double cnt = 0;
	for(int i =0; i < n; i++){
		b[i] = (int) floor(a[i]);
		x[i] = a[i] - b[i];
		cnt += x[i];
	}
    int c = (int) round(cnt);
    
    int i = 0, j = 0;
    while(i < n && j < c){
        if(floor(a[i]) != ceil(a[i])){
            b[i] += 1;
            j++;
        }
        i++;
    }
    
	for(int i = 0; i < n; i ++) 
		printf("%d\n", b[i]);
	return 0;
}