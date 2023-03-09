#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    string s1,s2;
    cin >> s1 >> s2;
    int len1 = s1.length(), len2 = s2.length();
    s1 = "x"+s1;
    s2 = "x"+s2;
    vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
    for(int i =1;i<=len1;i++){
        for(int j =1;j<=len2;j++){
            if(s1[i] == s2[j]) dp[i][j] = dp[i-1][j-1]+1;
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    int r = len1,c = len2;
    string ans = "";
    while(r > 0 && c > 0){
        if(s1[r] == s2[c]){
            ans = s1[r] + ans;
            r--; c--;
        } else{
            if(dp[r-1][c] > dp[r][c-1]) r--;
            else c--;
        }
    }
    cout << ans;
}