#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <math.h>
#include <set>
#include <string.h>
#include <map>
#define pb push_back
#define ll long long int
#define fi first
#define se second
using namespace std;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector< vector<short> > vii;
typedef pair<int,int> pi;
typedef pair<ll,int> pl;
typedef set< pair<ll,int> > s;
using namespace std;
const int MAXN = 1e6+5;
char str[MAXN];
int N;

vector<int> prefix_function() {
    int n =N;
    vector<int> pi (n);
    for (int i=1; i<n; ++i) {
        int j = pi[i-1];
        while (j > 0 && str[i] != str[j])
            j = pi[j-1];
        if (str[i] == str[j])  ++j;
        pi[i] = j;
    }
    return pi;
}

int main(){
    scanf("%s",str);
    N = (int)strlen(str);
    vector<int> C = prefix_function();
    vi::iterator it;
    for(it = C.begin();it!=C.end();it++){
        printf("%d ",(*it));
    }
    return 0;
}
