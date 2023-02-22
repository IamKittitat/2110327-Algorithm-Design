#include<iostream>
#include<vector>

using namespace std;

int main(){
    int r,c;
    cin >> r >> c;
    vector<vector<int>> v(r,vector<int>(c)),dp(r,vector<int>(c));
    
    for(int i =0;i<r;i++){
        // Handle input by change it to int
        string s;
        cin >> s;
        for(int j =0;j<c;j++){
            v[i][j] = s[j] == '1' ? 1 : 0;
        }
    }

    // Initial Case
    for(int i =0;i<r;i++) dp[i][0] = (v[i][0] == 1) ? 1 : 0;
    for(int i =0;i<c;i++) dp[0][i] = (v[0][i] == 1) ? 1 : 0;

    for(int i =1;i<r;i++){
        for(int j = 1;j<c;j++){
            if(v[i][j] == 0) continue;
            dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1;
        }
    }

    int ans = 0;
    for(int i =0;i<r;i++) for(int j=0;j<c;j++) ans = max(ans,dp[i][j]);
    cout << ans;
}