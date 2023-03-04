#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    long long mod = 100000007;
    vector<vector<long long>> dp(2,vector<long long>(n+1,1));
    dp[0][0] = 0;dp[1][0] = 0;
    dp[0][1] = 1; dp[1][1] = 1;
    for(int i = 2;i<=n;i++){
        if(i <= k){
            dp[0][i] = (dp[0][i-1] + dp[1][i-1])%mod;
        } else{
            dp[0][i] = (dp[0][i-1] + dp[1][i-1])%mod;
            dp[1][i] = (dp[1][i-k] + dp[0][i-k])%mod;
        }
    }

    /*for(auto &x : dp){
        for(auto &y : x) cout << y << " ";
        cout << endl;
    }*/
    cout << (dp[0][n] + dp[1][n])%mod;
}