#include <vector>
#include<map>
#include <iostream>
#include <algorithm>
#include <string.h>

#define ll long long int
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i, a, b) for(int i = a; i>b; i--)
#define ri(x) scanf("%d", &x)
#define rl(x) scanf("%lld", &x)
#define ub(A,x) upper_bound(A.begin(), A.end(), x)
#define lb(A,x) lower_bound(A.begin(), A.end(), x)
using namespace std;
const int MAXN = 2e5;
map<char, int> RANK;int N; vector<string> ST;

void read(){
    string str,str1;
    cin>>str;
    ri(N);ST.resize(N);
    FOR(i, 0, N)
        cin>>ST[i];
    FOR(i, 0, 26)
        str1.pb(str[i]);
    FOR(i, 0, 26)
        str1.pb(str[i]-32);
    FOR(i, 0, 52){
        RANK[str1[i]] = i;
    }
}

 bool compare(string a , string b) {
    FOR(i, 0 , min(a.length(), b.length())) {
        if(RANK[a[i]] < RANK[b[i]])
            return true;
        else if( RANK[a[i]] > RANK[b[i]])
            return false;
        }
        if(a.length() < b.length())
            return true;
    return false;
 }

int main() {
    read();
    sort(ST.begin(), ST.end(), compare);
    FOR(i, 0, N) cout<<ST[i]<<endl;
    return 0;
}
/*map<char , int> order_array;

bool compare(string a , string b) {
    for(int i = 0 ; i < min(a.length() , b.length()) ; i++) {
        if(RANK[a[i]] < RANK[b[i]])
            return true;
        else if(RANK[a[i]] > RANK[b[i]])
            return false;
    }
    if(a.length() < b.length())
        return true;
    return false;
}

int main() {
    string order;
    cin>>order;
    for(int i = 0 ; i < 26 ; i++)
        order.push_back('A'+order[i]-'a');
    for(int i = 0 ; i < order.length() ; i++)
        order_array[order[i]] = i;
    int N;
    cin>>N;
    vector<string> K;
    for(int i = 0 ; i < N ; i++) {
        string a;
        cin>>a;
        K.push_back(a);
    }
    sort(K.begin() , K.end() , compare);
    for(int i = 0 ; i < K.size() ; i++) {
        cout<<K[i]<<endl;
    }
}*/
