#include <iostream>
#define ll long long int
#include <string.h>
using namespace std;
const ll INF = 1e9+8;
ll n1,n2;
ll cal[2002][2002];
int pre[2002][2002];
char str1[2002],str2[2002];
ll f(ll i,ll j){
    if(i==n1&&j==n2) return 0;
    if(cal[i][j]>0) return cal[i][j];
    ll moves =INF,a=INF,b=INF,c=INF;
    if(str1[i]==str2[j]){
        moves = f(i+1,j+1);
        pre[i][j]=4;
    }
    else{
        if(i<n1&&j<n2)
            c = 1 +f(i+1,j+1);
        if(i<n1)
            b = 1+ f(i+1,j);
        if(j<n2)
            a = 1 + f(i,j+1);
        if(a>=b){
            if(b>=c){
                pre[i][j] = 3;
                moves = c;
            }
            else{
                pre[i][j] = 2;
                moves = b;
            }
        }
        else{
            if(a>=c){
                pre[i][j] = 3;
                moves = c;
            }
            else{
                pre[i][j] = 1;
                moves = a;
            }
            
        }
    }
    return cal[i][j]=moves;
}
int T=1;
void print(int i,int j,int k){
    if(i==n1&&j==n2) return;
    if(pre[i][j] == 1){
        printf("%d Insert %d,%c\n",T,i+1+k,str2[j]);
        T++;
        print(i,j+1,k+1);
    }
    if(pre[i][j] == 3){
        printf("%d Replace %d,%c\n",T,i+k+1,str2[j]);
        T++;
        print(i+1,j+1,k);
    }
    if(pre[i][j] == 2){
        printf("%d Delete %d\n",T,i+1+k);
        T++;
        print(i+1,j,k-1);
    }
    if(pre[i][j]==4)
        print(i+1,j+1,k);
}
void init(){
    for(int i=0;i<=n1;i++)
        for(int j =0;j<=n2;j++){
            cal[i][j] = -1;
            pre[i][j] = 0;
        }
    T=1;
}
ll length(string str1){
    ll i;
    for(i =0;str1[i]!='\0';i++);
    return i;
}
int main() {
    while(scanf("%s",str1)!=EOF){
        scanf("%s",str2);
        n1 = length(str1);
        n2 = length(str2);
        init();
        ll a = f(0,0);
        printf("%lld\n",a);
        print(0,0,0);
    }
    return 0;
}
