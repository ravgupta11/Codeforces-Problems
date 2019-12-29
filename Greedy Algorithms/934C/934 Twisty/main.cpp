#include <iostream>
#include<cstring>
using namespace std;
const int MAXN =2003;

int pre[MAXN][2];
int suf[MAXN][2];
int g[MAXN][MAXN][2][2];
int N;
int w[MAXN];

int main(){
    scanf("%d",&N);
    for(int i =0;i<N;i++){
        scanf("%d",&w[i]);
        w[i]--;
    }
    for(int i = 0;i<N;i++){
        if(i>0)
            memcpy(pre[i],pre[i-1],sizeof(pre[i]));
        pre[i][w[i]]++;
    }
    for(int j = N-1;j>0;j--){
        if(j<N-1)
            memcpy(suf[j],suf[j+1],sizeof(suf[j]));
        suf[j][w[j]]++;
    }
    for(int i = 0;i<N;i++)
        for(int k =0;k<w[i]+1;k++)
            g[i][i][w[i]][k] = 1;
    
    for(int i = 0;i<N;i++)
        for(int j =i+1;j<N;j++){
            g[i][j][0][0] = g[i][j-1][0][0] + g[j][j][0][0];
            g[i][j][1][0] = max(g[i][j-1][1][1] + g[j][j][1][0], g[i][j-1][1][0] + g[j][j][0][0]);
            g[i][j][1][1] = g[i][j-1][1][1] + g[j][j][1][1];
            
        }
    int ans =max(pre[N-1][1],pre[N-1][0]);
    ans =max(ans,g[0][N-1][1][0]);
    for(int i =0;i<N;i++){
        for(int j =i;j<N;j++){
            if(i>0&&j<N-1)
                ans = max(ans,pre[i-1][0]+g[i][j][1][0]+suf[j+1][1]);
        }
    }
    for(int i =0;i<N;i++){
        if(i!=N-1)
            ans = max(ans,g[0][i][1][0]+suf[i+1][1]);
        if(i)
            ans = max(ans,pre[i-1][0]+g[i][N-1][1][0]);
    }
    printf("%d",ans);
    return 0;
}
