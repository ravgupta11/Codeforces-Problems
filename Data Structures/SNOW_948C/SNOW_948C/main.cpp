#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int
using namespace std;
typedef vector<ll> vl;

vl F,A,T,M,c;
int N;

void pre(){
    scanf("%d",&N);
    c.resize(N);
    M.resize(N);
    F.resize(N);
    for(int i =0;i<N;i++){
        ll u;
        scanf("%lld",&u);
        A.push_back(u);
    }
    for(int i =0;i<N;i++){
        ll u;
        scanf("%lld",&u);
        T.push_back(u);
    }
    ll sum =0;
    for(int i =0;i<N;i++){
        sum += T[i];
        c[i]=sum;
    }
}
int main(){
    pre();
    for(int i=0;i<N;i++){
        ll u =0;
        if(i>0)
            u = A[i]+c[i-1];
        else
            u = A[i];
        vl::iterator it1,it2;
        it1 =lower_bound(c.begin(),c.end(),u);
        ll it = distance(c.begin(),it1);
        if(it>=N) continue;
        if(u==c[it]){
            if(it-1>=0)
                M[it]+= u -c[it-1];
            else
                M[it]+= u;
            F[it] -= 1;
        }
        else{
            if(it-1>=0)
                M[it]+= u -c[it-1];
            else
                M[it]+= u;
            F[it] -= 1;
        }
    }
    F[0] = F[0] +1;
    for(int i =1;i<N;i++)
        F[i] += F[i-1] +1;
    for(int i =0;i<N;i++){
        ll ans = F[i]*T[i]+M[i];
        printf("%lld ",ans);
    }
    return 0;
}
