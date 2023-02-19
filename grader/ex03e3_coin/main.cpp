#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// int dp[25][10005];
int dp[10010];

// Top Down approach (Slower than Bottom Up)
// int solve(vector<int> &v,int r,int m){
//     if(r < 0){
//         if(m == 0) return 0;
//         else return 10001;
//     }
//     if(dp[r][m] > 0) return dp[r][m];

//     int minChange = 10001;
//     if(m < v[r]) minChange = solve(v,r-1,m);
//     else{
//         int amount = 0,nowChange;
//         while(v[r]*amount <= m){
//             nowChange = amount + solve(v,r-1,m-v[r]*amount);
//             minChange = min(minChange,nowChange);
//             amount++;
//         }
//     }

//     dp[r][m] = minChange;
//     return minChange;
// }

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i =0;i<n;i++) cin >> v[i];

    // Bottom Up approach O(nm)
    dp[0] = 0;
    for(int i =1;i<=m;i++){
        dp[i] = 10005;
        for(int j =0;j<n;j++){
            if(i<v[j]) continue;
            dp[i] = min(dp[i],dp[i-v[j]]+1);
        }
    }
    // for(int i =0;i<=m;i++) cout << dp[i] << " ";
    // cout << endl;
    cout << dp[m];
}

/*
4 28
10 5 2 1

3 13
5 4 1
*/