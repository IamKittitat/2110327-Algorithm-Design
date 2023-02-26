#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<long long> dp(n+1);
    dp[1] = 1;
    dp[2] = 2;
    for(int i =0;i<m;i++){
        int tmp;
        cin >> tmp;
        dp[tmp] = -1;
    }
    if(dp[1] == -1 && dp[2] != -1) dp[2] = 1;
    for(int i =3;i<=n;i++){
        if(dp[i] == -1) continue;
        if(dp[i-1] == -1 && dp[i-2] == -1){
            dp[i] = -1;
        }
        else{
            long long r1 = 0,r2 = 0;
            if(dp[i-1] != -1) r1 = dp[i-1];
            if(dp[i-2] != -1) r2 = dp[i-2];
            dp[i] = (r1 + r2)%1000000007;
        }
    }
    if(dp[n] == -1) cout << "0\n";
    else cout << dp[n] << "\n";
}