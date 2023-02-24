#include<iostream>
#include<vector>
#include<map>

using namespace std;

// dp[i][j] ==> min weight that can get value >= i with items j to N
long long dp[100005][105];

// MinWeight that used to get more value than V
long long solve(vector<long long> &v,vector<long long> &w,int V,int i,int n){
    if(V <= 0) return 0;
    if(i > n) return 2e9;
    if(dp[V][i] > 0) return dp[V][i];

    long long result = min(solve(v,w,V,i+1,n), solve(v,w,V-v[i],i+1,n)+w[i]);
    dp[V][i] = result;

    return result;
}

// Max Value that has weight <= W
long long maxValue(vector<long long> &v,vector<long long> &w,int n,int W){
    int sumV = 0;
    for(auto &x : v) sumV += x;
    for(long long i = sumV;i>=1;i--){
        long long tmp = solve(v,w,i,1,n);
        if(tmp <= W) return i;
    }
    return 0;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,W;
    cin >> n >> W;
    vector<long long> v(n+1),w(n+1);
    for(int i =1;i<=n;i++) cin >> w[i] >> v[i];
    cout << maxValue(v,w,n,W);
}
