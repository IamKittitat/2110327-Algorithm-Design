#include<iostream>
#include<vector>

using namespace std;

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    int len1 = s1.length(),len2 = s2.length();
    vector<vector<bool>> dp(len1+1,vector<bool>(len2+1,false));
    s1 = " " + s1;
    s2 = " " + s2;
    int k;
    cin >> k;
    for(int x =0;x<k;x++){
        string q;
        cin >> q;
        q = " " +  q;

        dp[1][0] = s1[1] == q[1];
        dp[0][1] = s2[1] == q[1];
        for(int i = 2;i<=len1;i++) dp[i][0] = dp[i-1][0] && s1[i] == q[i];
        for(int i = 2;i<=len2;i++) dp[0][i] = dp[0][i-1] && s2[i] == q[i];

        for(int i = 1;i<=len1;i++){
            for(int j =1;j<=len2;j++){
                dp[i][j] = (dp[i-1][j] && s1[i] == q[i+j]) || (dp[i][j-1] && s2[j] == q[i+j]);
            }
        }
        // for(vector<bool> &mm : dp){
        //     for(bool y : mm) cout << y << " ";
        //     cout << endl;
        // }
        if(dp[len1][len2]) cout << "Yes\n";
        else cout << "No\n";
    }
}

/*
BAB
AB
4
BAABB
BABAB
ABBAB
BBABA
*/