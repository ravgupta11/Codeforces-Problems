#include <iostream>
#include <vector>
#include <utility>
#define ll long long int
using namespace std;
int dp[105][105][120];
vector<pair<int,int>> G[105];
int N,M;

int dpf(int v1,int v2,int c){
    if(dp[v1][v2][c]!=-1) return dp[v1][v2][c];
    for(pair<int,int> u:G[v1]){
        int c2 = u.second;
        int u1 = u.first;
        if(c<=c2&&dpf(v2,u1,c2)==false) return dp[v1][v2][c]=1;
    }
    return dp[v1][v2][c]=0;
}

void init(int N){
    for(int i =0;i<=N;i++)
        for(int j =0;j<=N;j++)
            for(int k = 0;k<27;k++)
                dp[i][j][k] =-1;
}

int main(){
    scanf("%d %d",&N,&M);
    for(int i =0;i<M;i++){
        int u,v;char c;
        scanf("%d %d %c",&u,&v,&c);
        int c1 = (int)c - 97;
        G[u].push_back({v,c1});
    }
    init(N);
    for(int i = 1;i<=N;i++){
        for(int j =1;j<=N;j++){
            if(dpf(i,j,0)) printf("A");
            else printf("B");
        }
        printf("\n");
    }
}
