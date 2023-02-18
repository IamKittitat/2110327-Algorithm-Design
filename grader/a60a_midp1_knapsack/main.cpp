#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v(n+1),w(n+1);
    for(int i =1;i<=n;i++) cin >> v[i];
    for(int i =1;i<=n;i++) cin >> w[i];
    vector<vector<int>> dp(n+1);
    for(int i=0;i<=n;i++){
        vector<int> tmp(m+1);
        for(int j = 0;j<=m;j++) cin >> tmp[j];
        dp[i] = tmp;
    }

    vector<int> ans;
    // int r = n,c = m;
    // while(r >0 && c >0){
    //     if(w[r] <= c){
    //         if(dp[r][c] == dp[r-1][c-w[r]] + v[r]){
    //             ans.push_back(r);
    //             c-=w[r];
    //         }
    //     }
    //     r--;
    // }
    int col = m;
    for(int i = n;i>0;i--){
        if(dp[i][col] == 0 || col <= 0) break;
        if(w[i] <= col && dp[i-1][col-w[i]] + v[i] == dp[i][col]){
            ans.push_back(i);
            col -= w[i];
        } 
    }
    cout << ans.size() << endl;
    for(auto &x : ans) cout << x << " ";
}