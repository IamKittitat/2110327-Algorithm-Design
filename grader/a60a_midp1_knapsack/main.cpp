#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v(n+1),w(n+1);
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i =1;i<=n;i++) cin >> v[i];
    for(int i =1;i<=n;i++) cin >> w[i];
    for(int i =1;i<=n;i++){
        for(int j =1;j<=m;j++){
            if(w[i] > j) dp[i][j] = dp[i-1][j];
            else{
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]] + v[i]);
            }
        }
    }

    vector<int> ans;
    
    int r = n,c = m;
    while(r >= 1 && c >= 1){
        // cout << r << " " << c << endl;
        if(w[r] <= c && dp[r][c] - v[r] == dp[r-1][c-w[r]]){
            ans.push_back(r);
            c-=w[r];
        } 
        r--;
    }
    cout << ans.size() << endl;
    for(auto &x : ans) cout << x << " ";


}