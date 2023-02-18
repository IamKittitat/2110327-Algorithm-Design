#include<iostream>
#include<string>

using namespace std;

int dp[505][505];

int bottomUp(string &s1,string &s2){
    // s1.size() row , s2.size() col
    for(int i =0;i<=s1.size();i++) dp[i][0] = 0;
    for(int i =0;i<=s2.size();i++) dp[0][i] = 0;

    for(int i =1;i<=s1.size();i++){
        for(int j =1;j<=s2.size();j++){
            if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[s1.size()][s2.size()];
}

int solve(string &s1,string &s2,int r1,int r2){
    if(r1 < 0 || r2 < 0) return 0;
    if(dp[r1][r2] > 0) return dp[r1][r2];

    int result;
    if(s1[r1] == s2[r2]) result = 1 + solve(s1,s2,r1-1,r2-1);
    else result = max(solve(s1,s2,r1-1,r2),solve(s1,s2,r1,r2-1));

    dp[r1][r2] = result;
    return result;
}

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    // cout << solve(s1,s2,s1.size()-1,s2.size()-1);
    cout << bottomUp(s1,s2);
}