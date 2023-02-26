#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    for(int i =1;i<=n;i++) dp[i][0] = i > m ? 0 : 1;
    // Loop every row
    for(int i =1;i<=n;i++){
        // Loop every col
        for(int j =1;j<=k;j++){
            // Sum every i-l (Doesnt break M law)
            for(int l = 1;l<=m;l++){
                if(l > i) break;
                dp[i][j] += dp[i-l][j-1];
            }
        }
    }
    cout << dp[n][k];
}

/*
Top Down Approach]

int dp[35][35];

int solve(int n,int m,int k){
    if(n<1) return 0;
    if(k == 0){
        if(n <= m) return 1;
        return 0;
    }
    if(dp[n][k] > -1) return dp[n][k];
    int result = 0;
    for(int i =1;i<=m;i++){
        result += solve(n-i,m,k-1);
    }
    dp[n][k] = result;
    return result;

}

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    for(int i =0;i<=n;i++) for(int j=0;j<=k;j++) dp[i][j] = -1;
    cout << solve(n,m,k);
}
*/


/*
4 3 1

5 2 2

7 9 4
*/