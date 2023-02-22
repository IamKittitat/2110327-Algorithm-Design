#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dp[11][10003];

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v(n+1,0);
    for(int i =1;i<=n;i++) cin >> v[i];
    
    // Initial Condition
    for(int i =0;i<=n;i++) dp[i][0] = -1;
    for(int i =0;i<=m;i++) dp[0][i] = -1;
    // Cant form area when there is more tile than wanted area
    for(int i =0;i<=n;i++) for(int j =0;j<i;j++) dp[i][j] = -1; 

    dp[0][0] = 0;
    
    // Loop every row
    for(int i =1;i<=n;i++){
        // Loop every column
        for(int j =i;j<=m;j++){
            dp[i][j] = -1;
            int tmp = INT32_MAX;
            // All possible value
            for(int k = 1;k<=100;k++){
                if(k*k > j) break;
                if(dp[i-1][j-k*k] == -1) continue;
                tmp = min(tmp,dp[i-1][j-k*k]+(v[i]-k)*(v[i]-k));
            }
            if(tmp != INT32_MAX) dp[i][j] = tmp;
        }
    }

    cout << dp[n][m];
}