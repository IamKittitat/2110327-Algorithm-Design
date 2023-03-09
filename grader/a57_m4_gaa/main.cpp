#include<iostream>
#include<vector>

using namespace std;

string solve(int n,int len,int k){
    if(k == 0){
        if(n == 1) return "g";
        return "a";
    }

    int lm = (len - k - 2)/2 + 1,rm = lm + k + 2;
    if(n < lm) return solve(n,lm-1,k-1);
    if(n > rm) return solve(n-rm,lm-1,k-1);
    if(n == lm) return "g";
    return "a";
}

int main(){
    int n;
    cin >> n;
    int len = 3, k = 0;
    while(len < n){
        k++;
        len = 2*len + k + 3;
    }
    cout << solve(n,len,k);
}