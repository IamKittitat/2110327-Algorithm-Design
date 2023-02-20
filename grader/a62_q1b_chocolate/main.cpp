#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> v(k),dp(n+1);
    for(int i = 0;i<k;i++) cin >> v[i];
    sort(v.begin(),v.end());
    dp[0] = 0;
    for(int i =1;i<=n;i++){
        dp[i] = 0;
        for(int j = 0;j<k;j++){
            if(v[j] > i) break;
            if(v[j] == i) dp[i]++;
            dp[i] = (dp[i] + dp[i-v[j]])%1000003;
        }
    }      
    cout << dp[n];
}