#include <iostream>
#include <string.h>
#include <map>
using namespace std;

string FtoD(int a,int b){
    int rem = a%b;
    map<int,int> mp;
    mp.clear();
    string r = "";
    while(rem!=0 && mp.find(rem)==mp.end()){
        mp[rem] = r.length();
        rem = rem*10;
        int res_part = rem/b;
        r += to_string(res_part);
        rem = rem%b;
    }
    return (rem==0)?r+"0":r;
}

int main() {
    int a, b,c;
    scanf("%d %d %d",&a,&b,&c);
    string r = FtoD(a,b);
    char arr[100000];
    strcpy(arr,r.c_str());
    bool found = false;
    for(int i = 0;arr[i]!='\0';i++){
        if(((int)arr[i]-48)==c){
            printf("%d",(i+1));
            found = true;
            break;
        }
    }
    
    if(!found) printf("-1");
    return 0;
}
