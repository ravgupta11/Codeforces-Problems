#include <iostream>
#include <math.h>
using namespace std;
int h1,a1,c1,h2,a2;
void f(int state1,int state2){
    if (state2<=0) return;
    if(state1<=a2&&state2==a1){
        printf("STRIKE\n");
    }
    else if(state1>a2){
        printf("STRIKE\n");
        f(state1-a2,state2-a1);
    }
    else{
        printf("HEAL\n");
        f(state1+c1-a2,state2);
    }
}

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,b%a);
}

int main() {
    scanf("%d %d %d",&h1,&a1,&c1);
    scanf("%d %d",&h2,&a2);
    
    return 0;
}
