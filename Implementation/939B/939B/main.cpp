#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int
using namespace std;

struct box{
    ll cp;
    ll r;
    int id;
};

bool by_rem(const box& a,const box& b){
    return a.r<b.r;
}
int main(){
    ll H;int B;
    vector<struct box> boxes;
    scanf("%lld %d",&H,&B);
    for(int i =0;i<B;i++){
        ll u;
        scanf("%lld",&u);
        struct box tmp;
        tmp.id = i+1;
        tmp.cp = u;
        tmp.r = H%u;
        boxes.push_back(tmp);
    }
    sort(boxes.begin(),boxes.end(),by_rem);
    struct box ans = boxes[0];
    printf("%d %lld",ans.id,(H/ans.cp));
    return 0;
}
