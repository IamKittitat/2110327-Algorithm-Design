#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n),dp(n);
    for(int i =0;i<n;i++) cin >> v[i];
    dp[0] = v[0];
    dp[1] = dp[0] + v[1];
    dp[2] = max(dp[0],dp[1]) + v[2];
    for(int i =3;i<n;i++){
        dp[i] = max(dp[i-3],max(dp[i-2],dp[i-1])) + v[i];
    }
    cout << dp[n-1];
}