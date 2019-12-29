#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m, mr, mc;
int col[50003], row[50003];
vector<string> s;

void init(){
	s.resize(n);
	mc = mr = 1000000000;
	for(int i =0; i < n; i++) row[i] = 0;
	for(int i =0; i < m; i++) col[i] = 0;
}

void read(){
	scanf("%d %d", &n, &m);
	init();
	for(int i =0; i < n; i++)
		cin>>s[i];
}
void calc(){
	for(int i =0; i < n; i++){
		for(int j =0; j < m; j++){
			row[i] += s[i][j] == '.';
			col[j] += s[i][j] == '.'; 
		}
	}
	
	for(int i =0; i < n; i++){
		mr = min(mr, row[i]);
	}
	for(int j = 0; j < m; j++){
		mc = min(mc, col[j]);
	}
}

int check(){
		int MIN = 1000000000;
		int a;
		for(int i =0; i < n; i ++ ){
			for(int j =0; j < m; j ++ ){
				a = col[j] + row[i] - (s[i][j] == '.');
				MIN = min(MIN, a);
			}
		}
		return MIN;
}
int main(){
	int t;
	scanf("%d", &t);
	for(int i =0; i < t; i++){
		read();
		calc();
		int ans = check();
		printf("%d\n", ans);
	}
	return 0;
}