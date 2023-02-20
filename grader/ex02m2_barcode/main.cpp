#include<iostream>
#include<vector>

using namespace std;

int dp[35][35]; // length i with j swap times

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    // Initial Case for col 0 
    for(int i =0;i<=n;i++){
        if(i<=m) dp[i][0] = 1;
        else dp[i][0] = 0;
    }
    // Len 0 can create 0 
    dp[0][0] = 0;

    for(int i =1;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j] = 0;
            // For "m" (Can have same color within this range)
            for(int l =1;l<=m;l++){
                if(l>i) break;
                dp[i][j] += dp[i-l][j-1];
            }
        } 
    }
    cout << dp[n][k];
}
/*
4 3 1

5 2 2

7 9 4
*/