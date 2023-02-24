#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> v(n,vector<int>(3,0)),dp(n,vector<int>(3,0));
    for(int i =0;i<n;i++) for(int j =0;j<3;j++) cin >> v[i][j];

    for(int i =0;i<3;i++) dp[0][i] = v[0][i];
    for(int i =1;i<n;i++){
        for(int j = 0;j<3;j++){
            for(int k = 0;k<3;k++){
                if(j!=k){
                    dp[i][j] = max(dp[i-1][k]+v[i][j],dp[i][j]);
                }
            }
        }
    }
    int ans = -1;
    for(int i =0;i<3;i++) ans = max(ans,dp[n-1][i]);
    cout << ans;
}