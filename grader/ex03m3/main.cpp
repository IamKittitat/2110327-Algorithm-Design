#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0;i<n;i++) cin >> v[i];
    vector<int> dp = v;
    for(int i = k+1;i<n;i++){
        dp[i] = dp[i-1] + v[i];
        for(int j = 1;j<=2*k+1;j++){
            if(j>i) break;
            dp[i] = min(dp[i],dp[i-j] + v[i]);
        }
    }
    int ans = dp[n-1];
    for(int i  = max(n-k-1,0);i<n;i++){
        ans = min(ans,dp[i]);
    }
    cout << ans;
}
