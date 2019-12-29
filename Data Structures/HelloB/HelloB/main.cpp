#include <iostream>
#include <vector>
#define ll long long int
#define pb push_back
using namespace std;
const int MAXN = 1e6+5;
typedef vector<ll> vi;
#define mod 1000000007
vi A,B;
ll F1,F2;
ll a,b;
ll N,Q;
ll F[MAXN];

void calF(){
    F[0] =F1;
    F[1] =F2;
    for(int i =2;i<N;i++)
        F[i] = (a*F[i-2]%mod + b*F[i-1]%mod)%mod;
}

void input(){
    scanf("%lld %lld",&N,&Q);
    scanf("%lld %lld",&F1,&F2);
    scanf("%lld %lld",&a,&b);
    for(int i =0;i<N;i++){
        ll u;
        scanf("%lld",&u);
        A.push_back(u);
    }
}

int main(){
    input();
    B.resize(N+10);
    calF();
    for(int i =0;i<Q;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        l--;r--;
            B[l] += F1;
            if(r-l>0){
                B[l+1] += F2;
                B[r+1] += -F[r-l+1];
            }
            B[r+2] += -a*F[r-l];
            if(l>0)
                B[l+1]+= -b*F[0];
    }
    for(int i=2;i<N;i++)
        B[i] = (B[i]%mod + a*B[i-2]%mod+b*B[i-1]%mod)%mod;
    for(int i =0;i<N;i++){
        A[i] = (A[i]%mod+ B[i]%mod)%mod;
        printf("%lld ",A[i]);
    }
    return 0;
}

