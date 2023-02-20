#include<iostream>

using namespace std;

int dp[505][505];

int main(){
    int n,k;
    cin >> n >> k;
    for(int i =0;i<=n;i++) {
        dp[i][0] = 1;
        dp[i][1] = 1;
        dp[i][i] = 1;
    }
    for(int i = 2;i<=k;i++){
        for(int j = i;j<=n;j++){
            dp[j][i] = (dp[j-1][i]*i + dp[j-1][i-1])%1997; 
        }
    }
    cout << dp[n][k];

}