#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n),dp(n);
    for(int i =0;i<n;i++) cin >> v[i];
    dp[0] = 1;
    for(int i =1;i<n;i++){
        dp[i] = 1;
        for(int j =0;j<i;j++){
            if(v[i] > v[j]) dp[i] = max(dp[i],dp[j]+1);
        }
    }
    int ans = dp[0];
    for(int i = 0;i<n;i++) ans = max(ans,dp[i]);
    cout << ans;
}