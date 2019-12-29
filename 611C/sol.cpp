#include <iostream>
#include <string>
using namespace std;

int R, C;
char mat[502][502];
int dp[502][502], down[502][502], lt[502][502];

inline int horizontal(int r, int c){
	return (mat[r][c - 1] != '#' && mat[r][c] != '#' );
}

inline int vertical(int r, int c){
	return (mat[r + 1][c] != '#' && mat[r][c] != '#');
}



inline int query(int r1, int c1, int r2, int c2){
	return dp[r2][c2] + dp[r1][c1] - dp[r1][c2] - dp[r2][c1] + lt[r1][c2] -  lt[r1][c1] + down[r2][c1] - down[r1][c1]; 
}

int main(){
	scanf("%d %d", &R, &C);	
	for(int i = 0; i < R; i++)
		scanf("%s", mat[i]);

	dp[R - 1][0] = 0;
	lt[R - 1][0] = 0;
	down[R - 1][0] = 0;

	for(int i = 1; i < C; i++){
		dp[R - 1][i] = dp[R - 1][i - 1] + 1 * horizontal(R - 1, i);
		lt[R - 1][i] = lt[R - 1][i - 1] + 1 * horizontal(R - 1, i);
	}

	for(int i = R - 2; i > -1; i--){
		dp[i][0] = dp[i + 1][0] + 1 * vertical(i, 0);
		down[i][0] = down[i + 1][0] + 1 * vertical(i, 0);
	}

	for(int j = 1; j < C; j++)
		for(int i = R - 2; i > -1; i--){
			down[i][j] = down[i + 1][j] + 1 * vertical(i, j);
			lt[i][j] = lt[i][j - 1] + 1 * horizontal(i, j);
		}

	for(int i = R - 2; i > -1; i--)
		for(int j = 1; j < C; j++)
			dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + 1 * horizontal(i, j) + 1 * vertical(i, j);
	
	int q;
	scanf("%d", &q);
	int r1, c1, r2, c2;
	for(int i = 0; i < q; i++){
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		r1--, c1--, r2--, c2--;
		printf("%d\n", query(r2, c1, r1, c2) );
	}
	return 0;
}