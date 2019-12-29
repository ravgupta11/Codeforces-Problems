#include<iostream>
#include <vector>
#include <algorithm>

typedef vector<int> vi

vi A;
vi B;
vi pre;
vi preA;
int N,M;

void calcPre(){
    int s = 0;
    for(int i = 0;i<M;i++){
        s += B[i];
        pre.push_back(s);
    }
    s = 0;
    for(int i = 0;i<N;i++){
        s += A[i];
        preA.push_back(s);
    }
}
void input(){
    scanf("%d %d",&N,&M);
    for(int i =0;i<N;i++){
        int u;
        scanf("%d",&u);
        A.push_back(u);
    }
    for(int i =0;i<M;i++){
        int u;
        scanf("%d",&u);
        B.push_back(u);
    }
}
int main(){
    input();
    calcPre();
    int cnt =0;
    int i = 0;
    int li = -1;
    int c =0;
    while(i<N){
        int S= 0;
        if(l1>-1)
            S = preA[i] - preA[li];
        else
            S = preA[i];
        int S1= *lower_bound(pre.begin(),pre.end(),S+c);
        if(S1==S){
            li = i;
            c += S;
            cnt++;
        }
        i++;
    }
    printf("%d",cnt);
    return 0;
}
