#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v(n),dp(m+1);
    for(int i =0;i<n;i++) cin >> v[i];
    dp[1] = 1;
    for(int i =2;i<=m;i++){
        dp[i] = INT32_MAX;
        for(int j = 0;j<n;j++){
            if(v[j] > i) continue;
            dp[i] = min(dp[i],dp[i-v[j]]+1);
        }
    }
    cout << dp[m];
}