#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> V;
bool cal[2002][2002];
int val[2002][2002];

int maxF(int i, int j, int a){
    if(i==j)
        return (a*V[i]);
    if(!cal[i][j]){
        int max1 = max(a*V[i]+maxF(i+1,j,a+1), a*V[j]+maxF(i,j-1,a+1));
        cal[i][j] = true;
        val[i][j] = max1;
    }
    return val[i][j];
}

int main() {
    scanf("%d", &N);
    for(int i =0;i<N;i++){
        int u;
        scanf("%d", &u);
        V.push_back(u);
    }
    printf("%d\n", maxF(0,N-1,1));
    return 0;
}
