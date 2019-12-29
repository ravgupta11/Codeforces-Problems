#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#define x first
#define y second
using namespace std;


vector<pair<int, pair<int, int> > > a;
vector<pair<int, int> > v;
int n;

bool sortwithindex(pair<int, pair<int, int> > a , pair<int, pair<int, int> > b){
	return a.y.y < b.y.y;
}

bool sortwithtime(pair<int, int> a, pair<int, int> b){
	return a.y < b.y;
}
bool timesort(pair<int, pair<int, int> > a, pair<int , pair<int, int> > b){
	return a.y.x < b.y.x;
}
void moveLeft(){
	int maxv = -1;
	int j = (int) v.size() - 1;
	int i = n - 1;
	while(i > -1){
		while(j > -1 && v[j].y > a[i].y.x ){
			if(v[j].x > maxv)
				maxv = v[j].x;
			j--;

		}
		if(maxv > a[i].x) {
			a[i].x = maxv;
		}
		i--;
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		a.push_back({val, {0, i}});
	}
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++){
		int type, pos, val;
		scanf("%d", &type);
		if(type == 1){
			scanf("%d %d", &pos, &val);
			a[pos - 1].x = val;
			a[pos - 1].y.x = i + 1;
		}
		else{
			scanf("%d", &val);
			v.push_back({val, i + 1});
		}
	}
	sort(v.begin(), v.end(), sortwithtime);
	sort(a.begin(), a.end(), timesort);
	moveLeft();
	sort(a.begin(), a.end(), sortwithindex);
	for(auto ai: a){
		printf("%d ", ai.x);
	}
	return 0;
}