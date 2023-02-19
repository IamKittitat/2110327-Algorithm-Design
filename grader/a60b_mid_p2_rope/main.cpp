#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(3),dp(n+1);
    for(int i =0;i<3;i++) cin >> v[i];
    sort(v.begin(),v.end());
    for(int i =0;i<v[0];i++){
        if(i%v[0] != 0) dp[i] = INT32_MIN;
        else dp[i] = 0;
    }
    for(int i = v[0];i<=n;i++){
        dp[i] = INT32_MIN;
        for(int j =0;j<3;j++){
            if(v[j] > i) break;
            dp[i] = max(dp[i-v[j]]+1,dp[i]);
        }
    }
    // for(auto &x : dp) cout << x << " ";
    // cout << endl;
    cout << dp[n];
}