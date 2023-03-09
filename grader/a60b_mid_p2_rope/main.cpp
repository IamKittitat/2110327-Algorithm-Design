#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    vector<int> v(3);
    cin >> n;
    for(int i =0;i<3;i++) cin >> v[i];
    sort(v.begin(),v.end());
    vector<int> dp(n+1);
    for(int i =1;i<=n;i++){
        dp[i] = INT32_MIN;
        for(int j = 0;j<3;j++){
            if(v[j] > i) break;
            dp[i] = max(dp[i],dp[i-v[j]]+1);
        }
    }
    cout << dp[n];
}