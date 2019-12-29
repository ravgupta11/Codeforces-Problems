#include <iostream>
#include <string.h>
using namespace std;
int N;
int calc[270][260];
int arr[270];

int sum(int i, int j);

int maxF(int i, int s){
    if(i>=N) return 1;
    if(calc[i][s]!=-1) return calc[i][s];
    int suml = 0;
    for(int j = i;j<N;j++){
        int s1 = sum(i,j+1);
        if(s<=s1)
            suml += maxF(j+1,s1);
    }
    calc[i][s] = suml;
    return calc[i][s];
}

int sum(int i, int j){
    int suml = 0;
    for(int k = i;k<j;k++)
        suml += arr[k];
    return suml;
}

void init(){
    for(int i = 0;i<N;i++){
        for(int j = 0;j<260;j++){
            calc[i][j] = -1;
        }
    }
}
int main() {
    char a[27];
    int t = 0;
    while(t++,scanf("%s",a),strcmp(a,"bye")!=0){
        int i;
        for(i = 0;a[i]!='\0';i++)
            arr[i] = ((int)a[i])-48;
        N = i;
        init();
        int ans = maxF(0,0);
        printf("%d. %d\n",t,ans);
    }
    return 0;
}
