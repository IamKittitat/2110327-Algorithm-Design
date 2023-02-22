#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> v(n,vector<int>(n,0)), dp(n,vector<int>(n,0));
    for(int i =0;i<n;i++) for(int j =0;j<n;j++) cin >> v[i][j];

    for(int i =0;i<n;i++) dp[i][0] = v[i][0];
    for(int i =0;i<n;i++) dp[0][i] = v[0][i];
    int ans = -1;
    for(int i =1;i<n;i++){
        for(int j=1;j<n;j++){
            dp[i][j] = max(dp[i-1][j-1],0) + v[i][j];
            ans = max(ans,dp[i][j]);
        }
    }

    cout << ans;
}