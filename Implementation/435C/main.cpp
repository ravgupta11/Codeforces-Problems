#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <string.h>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <sstream>
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
const int MAXN = 3001;
int n, arr[MAXN];

char mat[MAXN][MAXN];


int main(){
    ri(n);
    FOR(i, 0, n) ri(arr[i]);
    FOR(i, 0, 2000) FOR(j, 0, 2000) mat[i][j] = ' ';
    int curx =-1, cury = 1000, MAX = -1, MIN = 3000;
    FOR(i, 0, n){
        int flag = 1;
        FOR(j, 0, arr[i]){
            if(i%2==0){
                if(!flag)
                    cury++;
                curx++; flag = 0;
                //printf("%d %d\n", curx, cury - 1000);
                mat[curx][cury] = '/';
                MIN = min(MIN, cury);
                MAX = max(MAX, cury);
            }
            else{
                if(!flag)
                    cury--;
                curx++; flag =0;
                //printf("%d %d\n", curx, cury - 1000);
                mat[curx][cury] = '\\';
                MIN = min(MIN, cury);
                MAX = max(MAX, cury);
            }
        }
    }
    //printf("%d %d\n", MIN -1000, MAX-1000);
    FORR(i, MAX, MIN-1){ FOR(j, 0, curx+1) printf("%c", mat[j][i]);
        printf("\n");
    }
    return 0;
}