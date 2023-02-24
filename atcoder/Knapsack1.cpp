#include<iostream>
#include<vector>

using namespace std;

long long v[105],w[105];
long long dp[105][100005];
int main(){
    int n,W;
    cin >> n >> W;
    for(int i =1;i<=n;i++) cin >> w[i] >> v[i];
    
    for(int i =0;i<n;i++) dp[i][0] = 0;
    for(int i =0;i<W;i++) dp[0][i] = 0;
    
    for(int i =1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(w[i] <= j){
                dp[i][j] = max(dp[i-1][j-w[i]]+v[i],dp[i-1][j]);
            } else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // for(int i =0;i<=n;i++){
    //     for(int j=0;j<=W;j++) cout << dp[i][j] << " ";
    //     cout << endl;
    // }


    cout << dp[n][W];
    
}