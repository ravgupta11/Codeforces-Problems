#include <iostream>
using namespace std;

int solve(){
    int n;
    scanf("%d",&n);
    int a[2002];
    for(int i =0;i<n;i++)
        scanf("%d",&a[i]);
    int l = -1;
    int m_i=0;
    for(int i =0;i<n;i++){
        int start = a[i];
        int len = 1;
        int k = i+1;
        bool dec = false;
        while(k<n&&a[k]<=start) {
            if(a[k]<start) dec = true;
            start = a[k];
            k++;
            len++;}
        if(len>l&&dec){
            l = len;
            m_i = i;
        }
    }
    if(l==-1){
        printf("%d",n);
        return 0;
    }
    int right = l + m_i;
    int left = m_i-1;
    int d_r = 0;
    int d_l = 0;
    if(right<n&&a[right]>=a[m_i]){
        int s = a[right];
        d_r = 1;
        while(right+1<n&&a[right+1]>=s) {
            s = a[right+1];
            right += 1;
            d_r++;}
    }
    if(left>-1&&a[left]<=a[m_i+l-1]){
        int s = a[left];
        d_l = 1;
        while(left-1>-1&&a[left-1]<=s) {
            s = a[left-1];
            d_l++;
            left-=1;
        }
    }
    int ans = l+d_l+d_r;
    return ans;
}

int main(){
    printf("%d",solve());
    return 0;
}
