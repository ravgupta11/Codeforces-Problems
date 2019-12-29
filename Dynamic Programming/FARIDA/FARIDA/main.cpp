#include <vector>
#include <iostream>
#define ll long long int
using namespace std;

const int MAXN = 1e4+5;
bool cal[MAXN][3];
ll calv[MAXN][3];
vector<int> V;
int N;

ll maxF(int i, int flag){
    if(i>=N)
        return 0;
    if(!cal[i][flag]){
        ll max1;
        if (flag==0)
            max1 = maxF(i+1,1-flag);
        else
            max1 = max(V[i]+maxF(i+1,1-flag), maxF(i+1,flag));
        cal[i][flag] = true;
        calv[i][flag] = max1;
    }
    return calv[i][flag];
}

int main() {
    int t;
    scanf("%d",&t);
    for(int it = 0;it<t;it++){
        V.clear();
        scanf("%d",&N);
        for(int i = 0;i<N;i++){
            int u;
            scanf("%d", &u);
            V.push_back(u);
        }
        for(int i = 0;i<N;i++){
            cal[i][0] = false;
            cal[i][1] = false;
        }
        printf("Case %d: %lld\n",(it+1),max(maxF(0,1),maxF(0,0)));
    }
    return 0;
}
