#include<iostream>

using namespace std;

int dp[3002][3002];

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    int len1 = s1.length(), len2 = s2.length();
    s1 = " " + s1;
    s2 = " " + s2;
    // cout << len1 << " " << len2 << endl;
    for(int i =0;i<=len1;i++) dp[i][0] = 0;
    for(int i =0;i<=len2;i++) dp[0][i] = 0;

    for(int i =1;i<=len1;i++){
        for(int j =1;j<=len2;j++){
            if(s1[i] == s2[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
    string ans = "";
    int r = len1,c = len2;
    while(r >= 1 && c >= 1){
        if(s1[r] == s2[c]){
            ans = s1[r] + ans;
            r--; c--;
        } else{
            if(dp[r-1][c] > dp[r][c-1]) r--;
            else c--;
        }
    }
    cout << ans << endl;
}