#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> v(n),dp(n);
    for(int i =0;i<n;i++) cin >> v[i];
    dp[0] = 0;
    for(int i =1;i<n;i++){
        int tmp = INT32_MAX;
        for(int j = 1;j<=k;j++){
            if(j>i) break;
            tmp = min(tmp,dp[i-j]+abs(v[i-j]-v[i]));
        }
        dp[i] = tmp;
    }
    cout << dp[n-1];
}