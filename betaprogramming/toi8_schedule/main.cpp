#include<iostream>
#include<vector>

using namespace std;
    
int m,n;

pair<int,int> cal(pair<int,int> old,int newLab){
    pair<int,int> ans;
    if(old.second + newLab > m){
        ans.first = old.first + 1;
        ans.second = newLab;
    } else{
        ans.first = old.first;
        ans.second = old.second + newLab;
    }
    return ans;
}

int main(){
    cin >> m >> n;
    vector<int> j(n+1),k(n+1);
    vector<vector<pair<int,int>>> dp(n+1,vector<pair<int,int>>(n+1));
    for(int i =1;i<=n;i++) cin >> j[i];
    for(int i =1;i<=n;i++) cin >> k[i];
    
    dp[0][0] = {1,0};
    for(int i =1;i<=n;i++) dp[i][0] = cal(dp[i-1][0],j[i]);
    for(int i =1;i<=n;i++) dp[0][i] = cal(dp[0][i-1],k[i]);

    for(int x =1;x<=n;x++){
        for(int y =1;y<=n;y++){
            dp[x][y] = min(cal(dp[x-1][y],j[x]),cal(dp[x][y-1],k[y]));
        }
    }
    cout << dp[n][n].first << endl << dp[n][n].second;
}