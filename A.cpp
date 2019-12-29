#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int n;
string s;

vector< pair<int, int> > pr;

bool check(int st, int ed){
	if(2*(pre[ed] - pre[st] + (s[st] - '0')) != ed - st + 1)
		return true;
	return false;
}

int main(){
	cin >> n;
	cin >> s;
	int start = 0, end = n - 1;
	while(start < n){
		if(check( start, end )){
			pr.push_back({start, end});
			start = end + 1;
			end = n - 1;
		}
		else{
			end--;
		}
	}
	printf("%d\n", (int) pr.size());
	for(auto p: pr){
		int st = p.first, ed = p.second;
		for(;st <= ed; st++) printf("%c", s[st]);
		printf(" ");
	}
	return 0;
}