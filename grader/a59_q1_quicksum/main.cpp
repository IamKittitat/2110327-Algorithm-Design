#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n,m,k;
    cin >> n >> m >> k;
    int v[n][m],dp[n][m];
    for(int i =0;i<n;i++) for(int j =0;j<m;j++) cin >> v[i][j]; 

    dp[0][0] = v[0][0];
    for(int i = 1;i<m;i++) dp[0][i] = dp[0][i-1] + v[0][i];
    for(int i = 1;i<n;i++){
        dp[i][0] = dp[i-1][0] + v[i][0];
        for(int j =1;j<m;j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + v[i][j];
        }
    }

    for(int i =0;i<k;i++){
        int r1,c1,r2,c2;
        cin >> r1 >> c1 >> r2 >> c2;
        // P(r2,c2) – P(r1-1,c2) – P(r2,c1-1) + P(r1-1,c1-1).
        int first = r1-1 < 0 ? 0 : dp[r1-1][c2];
        int second = c1-1 < 0 ? 0 : dp[r2][c1-1];
        int third = (r1-1 >= 0 && c1-1 >= 0) ? dp[r1-1][c1-1] : 0;
        cout << dp[r2][c2] - first - second + third << "\n";
    }
}