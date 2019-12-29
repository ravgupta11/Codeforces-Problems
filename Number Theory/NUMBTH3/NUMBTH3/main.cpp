#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <math.h>
#include <set>
#define pb push_back
#define ll long long int
#define fi first
#define se second
using namespace std;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,int> pl;
typedef set< pair<ll,int> > s;


ll gcd(int a,int b,int *x,int *y){//a >b
    if(b==0){
        *x =1;
        *y =0;
        return a;
    }
    int x1,y1;
    int g =gcd(b,a%b,&x1,&y1) ;
    *x = y1;
    *y = x1 - (a/b)*y1;
    return g;
}

int main(){
    int a,b,n,m;
    scanf("%d %d %d %d",&a,&b,&n,&m);
    int x,y,x1,y1;
    int ans1  =0;
    int ans2 =0;
    int ans3 = 0;
    int ans4 = 0;
    gcd(m,n,&x,&y);
    ans1 = abs(y)*n + a;
    ans2 =abs(x)*m + b;
    gcd(n,m,&x1,&y1);
    ans3 = abs(x1)*n +a;
    ans4 = abs(y1)*m+b;
    printf("%d %d %d %d",ans1,ans2,ans3,ans4);
    return 0;
}
