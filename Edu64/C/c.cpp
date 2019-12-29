#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll long long int
#define FOR(i, a, b) for(ll i = a; i < b; i++) 
using namespace std;

string s, t, p;
vector<char> st;


void read(){
	cin >> s;
	cin >> t;
	cin >> p;
}

bool subset(){
	int freq[256];
	for(int i =0; i < 256; i ++) freq[i] = 0;
	for(char a: p) freq[a]++;
	for(char b: st){
		freq[b]--;
	}
	for(int i =0; i < 256; i ++) if(freq[i] < 0) return false;
	return true;
}

bool process(){
	int i = 0, j = 0;
	int n = s.length(), m = t.length();
	while(i < n && j < m){
		if(s[i] == t[j]){
			i++;
		}
		else{
			st.push_back(t[j]);
		}
		j++;
	}
	if(i != n) return false;
	while(j < m) st.push_back(t[j++]);
	
	return subset();
}


int main(){
	int q;
	scanf("%d", &q);
	for(int i =0; i < q; i++){
		read();
		st.clear();
		printf("%s", process() ? "YES\n" : "NO\n");
	}
	return 0;
}