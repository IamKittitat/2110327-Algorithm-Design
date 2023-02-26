#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    string s1,s2;
    cin >> s1 >> s2;
    s1 = " " + s1;
    s2 = " " + s2;
    for(int i = 1;i<=n;i++){
        for(int j =1;j<=m;j++){
            if(s1[i] == s2[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
    string ans = "";
    int r = n, c = m;
    while(r>=1 && c >= 1){
        if(s1[r] == s2[c]){
            ans = s1[r] + ans;
            r--; c--;
        } else{
            if(dp[r-1][c] > dp[r][c-1]) r--;
            else c--;
        }
    }
    cout << ans;
}