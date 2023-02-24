#include<iostream>
#include<vector>

using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<int>> v(h,vector<int>(w)),dp(h,vector<int>(w));
    for(int i =0;i<h;i++){
        string s;
        cin >> s;
        for(int j =0 ;j<w;j++){
            // Change obstacle to 1, pathway to 0
            v[i][j] = s[j] == '.' ? 0 : 1;
        }
    }

    bool hasObstacle = false;
    for(int i =0;i<h;i++){
        if(v[i][0] == 1){
            hasObstacle = true;
        }    
        if(!hasObstacle) dp[i][0] = 1;
    }
    hasObstacle = false;
    for(int i =0;i<w;i++){
        if(v[0][i] == 1) hasObstacle = true;
        if(!hasObstacle) dp[0][i] = 1;
    }
    for(int i =1;i<h;i++){
        for(int j =1;j<w;j++){
            if(v[i][j] == 0){
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%1000000007;
            }
        }
    }
    cout << dp[h-1][w-1]%1000000007;
}