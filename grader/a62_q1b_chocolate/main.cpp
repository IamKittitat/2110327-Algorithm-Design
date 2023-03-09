#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int mod = 1000003;
    int n,k;
    cin >> n >> k;
    vector<int> v(k);
    for(int i =0;i<k;i++) cin >> v[i];
    sort(v.begin(),v.end());
    vector<int> dp(n+1);
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<k;j++){
            if(v[j] > i) break;
            if(i == v[j]) dp[i]++;
            else dp[i] = (dp[i] + dp[i-v[j]])%mod;
        }
    }
    cout << dp[n];
}