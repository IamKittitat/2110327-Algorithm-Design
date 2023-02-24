#include<iostream>
#include<vector>

using namespace std;

int dp[103];

int main(){
    int n;
    cin >> n;
    vector<int> v = {6,9,20};    

    for(int i = 1;i<=n;i++){
        for(int j =0;j<3;j++){
            if(v[j] > i) break;
            if(v[j] == i) dp[i] = 1;
            if(dp[i-v[j]] != 0) dp[i] = 1;
        }
    }

    bool hasAns = false;
    for(int i =0;i<=n;i++) if(dp[i] == 1){ cout << i << endl; hasAns = true;}
    if(!hasAns) cout << "no";
}