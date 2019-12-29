#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <math.h>
#include <set>
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
const int MAXN = 2e5+5;
char alpha[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int zet[MAXN];
int pref[MAXN];
int str[MAXN];
int N;
void z_function() {
    int n = N;
    for (int i=1, l=0, r=0; i<n; i++) {
        if (i <= r)
            zet[i] = min (r-i+1, zet[i-l]);
        while (i+zet[i] < n && str[zet[i]] == str[i+zet[i]])
            zet[i]++;
        if (i+zet[i]-1 > r)
            l = i,  r = i+zet[i]-1;
    }
}

bool vis[MAXN];
int main(){
    scanf("%d",&N);
    for(int i = 0;i<N;i++)
        scanf("%d",&pref[i]);
    for(int i =0;i<N;i++)
        zet[i]  =0;
    str[0] ='a';
    int it =1;
    for(int i =1;i<N;i++){
        if(pref[i] == 0) {
            str[i] =alpha[it++];
            //printf("%s\n",str);
            continue;
        }
        str[i] = str[pref[i] - 1];
        //printf("%s\n",str);
    }
    //printf("%s\n",str);
    z_function();
    for(int i =0;i<N;i++)
        printf("%d ",zet[i]);
}
