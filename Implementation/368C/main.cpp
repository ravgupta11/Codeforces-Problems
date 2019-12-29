#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#define ll long long int
#define pb push_back
#define x first
#define y second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a; i>b; i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
using namespace std;
const int MAXN = 1e5+5;

char s[MAXN];
int cnt[MAXN][255];

int main(){
    scanf("%s", s);
    int n = (int) strlen(s);
    int m;
    int s1 =0, s2 = 0, s3 = 0;
    FOR(i, 0, n){
        cnt[i]['x'] = cnt[max(i-1,0)]['x'];
        cnt[i]['y'] = cnt[max(i-1,0)]['y'];
        cnt[i]['z'] = cnt[max(i-1,0)]['z'];
        cnt[i][s[i]]++;

    }
    ri(m);
    FOR(i, 0, m){
        int l, r;
        ri(l); ri(r);
        if(r - l +1 <3){
            printf("YES\n");
            continue;
        }
        l--; r--;
        int z = cnt[r]['z'] - cnt[l]['z'];
        int y = cnt[r]['y'] - cnt[l]['y'];
        int x = cnt[r]['x'] - cnt[l]['x'];
        if(s[l]=='z') z++;
        else if(s[l]=='x') x++;
        else y++;
        //printf("%d %d %d %d %d\n", l, r, x, y, z);
        if(x==y && x==z) printf("YES");
        else if((x != y && y != z) && x != z) printf("NO");
        else{
            int m = max(max(z,x), y);
            if(m - x >1 || m- y> 1 || m - z> 1) printf("NO");
            else printf("YES");
        }
        printf("\n");
    }
    return 0;
}