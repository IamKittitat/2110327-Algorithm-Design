#include<iostream>
#include<vector>

using namespace std;

int dp[50][50];

int bottomUp(int n,int k){
    for(int i =0;i<=n;i++){
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
    for(int i = 1;i<=n;i++){
        for(int j =1;j<=min(k,i);j++){
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }
    return dp[n][k];
}

int solve(int n,int k){
    if(n==k || k ==0) return 1;

    if(dp[n][k] > 0) return dp[n][k];
    int result = solve(n-1,k-1) + solve(n-1,k);
    dp[n][k] = result;
    return result;
}

int main(){
    int n,k;
    cin >> n >> k;
    // for(int i =0;i<50;i++) for(int j =0;j<50;j++) dp[i][j] = -1;
    cout << bottomUp(n,k);
}