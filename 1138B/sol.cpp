#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100000;
int n;
char s[maxn + 10], t[maxn + 10];
vector<int> a, b, c, d;
 
int main() {
	scanf("%d", &n);
	scanf("%s%s", s + 1, t + 1);
	for (int i = 1; i <= n; ++i)
		if (s[i] == '0' && t[i] == '0') a.push_back(i);
		else if (s[i] == '1' && t[i] == '0') b.push_back(i);
		else if (s[i] == '0' && t[i] == '1') c.push_back(i);
		else if (s[i] == '1' && t[i] == '1') d.push_back(i);
	for (int i = 0; i <= (int)b.size(); ++i)
		for (int j = 0; j <= (int)d.size(); ++j) {
			int s = (int)c.size() - i - 2 * j + (int)d.size();
			if (s >= 0 && s <= (int)c.size()) {
				int all = i + s + j;
				int k = n / 2 - all;
				if (k >= 0 && k <= (int)a.size()) {
					for (int p = 0; p < k; ++p) printf("%d ", a[p]);
					for (int p = 0; p < i; ++p) printf("%d ", b[p]);
					for (int p = 0; p < s; ++p) printf("%d ", c[p]);
					for (int p = 0; p < j; ++p) printf("%d ", d[p]);
					return 0;
				}
			}
		}
	printf("-1");
}