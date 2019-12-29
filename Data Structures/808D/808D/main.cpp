#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define ll long long int
using namespace std;
vector<ll> a;
ll pref[100002];
ll sum;

bool solve(){
    int n;
    scanf("%d",&n);
    multiset<ll> preff;
    multiset<ll> suff;
    for(int i = 0;i<n;i++){
        ll u;
        scanf("%lld",&u);
        a.push_back(u);
    }
    sum = 0;
    for(int i = 0;i<n;i++){
        sum += a[i];
        pref[i] = sum;
    }
    for(int i = 0;i<n;i++)
        suff.insert(a[i]);
    multiset<ll>::iterator it;
    for(int i = 0;i<n;i++){
        it = suff.find(a[i]);
        preff.insert(a[i]);
        suff.erase(it);
        ll pre = pref[i];
        ll suf = sum - pref[i];
        if(pre==suf) return true;
        ll diff = abs(pre - suf);
        if(diff%2==0)
            if(pre - diff/2 == suf + diff/2) if(preff.find(diff/2)!=preff.end()) return true;
        if(pre + diff/2 == suf - diff/2) if(suff.find(diff/2)!=suff.end()) return true;
    }
    return false;
}
int main(){
    printf(solve()?"YES":"NO");
    return 0;
} 
