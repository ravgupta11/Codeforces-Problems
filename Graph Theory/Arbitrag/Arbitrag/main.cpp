#include <iostream>
#include <map>
#include <string>
using namespace std;

double v[50][50];
int N,M;

void init(){
    for(int i = 0;i<N;i++)
        for(int j =0;j<N;j++)
            v[i][j] = 0;
    for(int i =0;i<N;i++)
        v[i][i] = 1;
}
void floyd(){
    for(int k = 0;k<N;k++)
        for(int i = 0;i<N;i++)
            for(int j = 0;j<N;j++)
                v[i][j] = max(v[i][k]*v[k][j],v[i][j]);
}

int main() {
    int t = 0;
    while(scanf("%d",&N),t++,N!=0){
        map<string,int> mi;
        init();
        for(int i =0;i<N;i++){
            char arr[1000];
            scanf("%s",arr);
            mi[arr] = i;
        }
        scanf("%d",&M);
        for(int i =0;i<M;i++){
            char arr1[100],arr2[100];double cost;
            scanf("%s %lf %s",arr1,&cost,arr2);
            v[mi[arr1]][mi[arr2]] = cost;
        }
        bool found = false;
        floyd();
        for(int i = 0;i<N&&!found;i++)
            if(v[i][i]>1)
                found = true;
        if(found)
            printf("Case %d: Yes\n",t);
        else
            printf("Case %d: No\n",t);
    }
    return 0;
}
