#include <iostream>
#define ll long long int
#include <string.h>
using namespace std;
const ll INF = 1e9+8;
ll n1,n2;
ll cal[2002][2002];
char str1[2002],str2[2002];
ll f(ll i,ll j){
    if(i==n1&&j==n2) return 0;
    if(cal[i][j]>0) return cal[i][j];
    ll moves =INF,a=INF,b=INF,c=INF;
    if(str1[i]==str2[j]){
        moves = f(i+1,j+1);
    }
    else{
        if(j<n2)
            a = 1 + f(i,j+1);
        if(i<n1)
            b = 1+ f(i+1,j);
        moves = min(a,b);
        if(i<n1&&j<n2)
            c = 1 +f(i+1,j+1);
        moves = min(moves,c);
    }
    return cal[i][j]=moves;
}
void init(){
    for(int i=0;i<=n1;i++)
        for(int j =0;j<=n2;j++)
            cal[i][j] = -1;
}
ll length(string str1){
    ll i;
    for(i =0;str1[i]!='\0';i++);
    return i;
}
int main() {
    int t;
    scanf("%d",&t);
    for(int i =0;i<t;i++){
        scanf("%s",str1);
        scanf("%s",str2);
        n1 = length(str1);
        n2 = length(str2);
        init();
        ll a = f(0,0);
        printf("%lld\n",a);
    }
    return 0;
}
