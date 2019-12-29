#include <iostream>
using namespace std;
int N,M;
int mat[104][104];
bool cal[104][104];
int calv[104][104];

bool check(int i, int j){
    if((i<N&&i>=0)&&(j<M&&j>=0))
        return true;
    return false;
}
int dx[] = {+1,-1,0};
int dy[] = {+1,+1,+1};

int maxF(int i, int j){
    if(!check(i,j)){
        return 0;
    }
    if(!cal[i][j]){
        int a = 0;
        for(int it = 0;it<3;it++){
            int b = mat[i][j]+ maxF(i+dy[it], j+dx[it]);
            if (b>a)
                a = b;
        }
        cal[i][j] = true;
        calv[i][j] = a;
    }
    return calv[i][j];
}

int main() {
    int t;
    scanf("%d",&t);
    for(int it = 0;it<t;it++){
        scanf("%d %d",&N,&M);
        for(int i = 0;i<N;i++)
            for(int j = 0;j<M;j++){
                scanf("%d",&mat[i][j]);
                cal[i][j] = false;
            }
        int max = 0;
        for(int i = 0;i<M;i++){
            int a = maxF(0,i);
            if(a>max)
                max = a;
        }
        printf("%d\n",max);
    }
    return 0;
}
