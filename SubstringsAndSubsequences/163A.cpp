#include<iostream>
#include <cstdio>
#include <string.h>
#include<string>
#define ll long long int
using namespace std;
const int SIZE = 5004;
const ll MOD = 1e9 + 7;
int n, m;
char s[SIZE], t[SIZE];
int DP[SIZE][SIZE];

int dp(int i, int j){
	if(i == n || j == m) return 0;
	if(DP[i][j] != -1) return DP[i][j];
	int & ans = DP[i][j] = 0;
	if(s[i] == t[j]){
		ans = (1 + dp(i + 1, j + 1) + dp(i, j + 1) ) % MOD;
	}
	else{
		ans = dp(i, j + 1);
	}
	return ans;
}

int main(){
	gets(s);
	gets(t);
	n = strlen(s);
	m = strlen(t);

	for(int i =0; i < n; i++ ) for(int j =0; j < m; j++) DP[i][j] = -1;

	int ans = 0;
	for(int i =0; i < n; i++) ans = ( ans + dp(i, 0) ) % MOD;
	cout<<ans;
	return 0;
}