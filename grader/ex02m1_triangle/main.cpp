#include<iostream>
#include<vector>

using namespace std;

int dp[105][105];

int main(){
    int n;
    cin >> n;
    vector<vector<int>> v(n,vector<int>(n,0));
    for(int i =0;i<n;i++) for(int j=0;j<=i;j++) cin >> v[i][j];

    dp[0][0] = v[0][0];
    for(int i =1;i<n;i++) dp[i][0] = dp[i-1][0]+v[i][0];
    for(int i =1;i<n;i++){
        for(int j=1;j<=i;j++){
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + v[i][j]; 
        }
    }

    int ans = dp[n-1][0];
    for(int i =1;i<n;i++){
        ans = max(ans,dp[n-1][i]);
    }
    cout << ans;
}