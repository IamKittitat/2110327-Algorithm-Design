#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n),dp(n);
    for(int i =0;i<n;i++) cin >> v[i];
    dp[0] = 0;
    if(n > 1) dp[1] = abs(v[1]-v[0]);
    for(int i =2;i<n;i++){
        dp[i] = min(dp[i-1]+abs(v[i-1]-v[i]),dp[i-2]+abs(v[i-2]-v[i]));
    }
    cout << dp[n-1];
}
