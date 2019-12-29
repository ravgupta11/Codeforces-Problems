#include <iostream>
#include <string>
#include <vector>
#include <set>
#define loop(x) for(int i =0; i < x; i++)
#define ll long long int

using namespace std;

int main(){
	string s;
	vector< set<int> > freq(26);
	int n;
	cin >> s;
	n = s.length();
	for(int i =0; i < n;i++) freq[s[i] - 'a'].insert(i);
	int q;
	cin >> q;
	int type, pos_l, val_r, cnt=0;char val;
	loop(q){
		scanf("%d", &type);
		if(type == 1){
			scanf("%d %c", &pos_l, &val);
			pos_l--;
			freq[s[pos_l] - 'a'].erase(pos_l);
			freq[val - 'a'].insert(pos_l);
			s[pos_l] = val;
		}
		else{
			scanf("%d %d", &pos_l, &val_r);
			cnt = 0;
			pos_l--, val_r--;
			loop(26){
				auto p = (freq[i].lower_bound(pos_l));

				if(p != freq[i].end() && *p <= val_r) cnt++;
			}
			printf("%d\n", cnt);
		}
	}
	return 0;
}
