#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
const int MAXN  = 1e5+5;

struct cup{
    int pos,cap;
};

vector<struct cup> arr;
int ans[MAXN];
int N,W;

struct by_cap{
    bool operator()(struct cup &a1, struct cup &a2){
        return a1.cap>a2.cap;
    }
};

struct by_pos{
    bool operator()(struct cup &a1, struct cup &a2){
        return a1.pos<a2.pos;
    }
};
int main(){
    scanf("%d %d",&N,&W);
    for(int i =0;i<N;i++){
        int u;
        scanf("%d",&u);
        struct cup c;
        c.cap = u;
        c.pos= i;
        arr.push_back(c);
        ans[i] = u;
    }
    sort(arr.begin(),arr.end(),by_cap());
    for(int i =0;i<N;i++){
        int d;
        if(arr[i].cap%2==0) d = arr[i].cap/2;
        else d = arr[i].cap/2 +1;
        W -= d;
        arr[i].cap -= d;
    }
    if(W>=0){
        for(int i =0;i<N&&W!=0;i++){
            int u = min(arr[i].cap,W);
            W-= u;
            arr[i].cap-= u;
        }
        bool fail = false;
        if(W>0){
            printf("-1");
            fail = true;
        }
        sort(arr.begin(),arr.end(),by_pos());
        for(int i =0;i<N&&!fail;i++){
            ans[i] = ans[i] - arr[i].cap;
            printf("%d ",ans[i]);
        }
    }
    else{
        printf("-1");
    }
    return 0;
}
