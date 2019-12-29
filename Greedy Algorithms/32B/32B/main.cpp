#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
#define ll long long int
#define FOR(i,a,b) for(int  i= a;i<b;i++)
#define rl(x) scanf("%lld ",&x);
#define rll(x,y) scanf("%lld %lld",&x,&y);
#define rs(x) scanf("%s",x);

char ans[203];
char que[203];

void solve(){
    rs(que);
    int k = 0;
    int N = (int)strlen(que);
    FOR(i,0,N){
        if(que[i]=='-' && que[i+1] =='-'){
            ans[k] = '2';
            k++;i++;
            //printf("%c\n",ans[k-1]);
        }
        else if(que[i]=='-' && que[i+1] == '.'){
            ans[k] = '1';
            k++;i++;
            //printf("%c\n",ans[k-1]);
        }
        else if(que[i]=='.'){
            ans[k] = '0';
            k++;
            //printf("%c\n",ans[k-1]);
        }
    }
}

int main(){
    solve();
    printf("%s",ans);
    return 0;
}
