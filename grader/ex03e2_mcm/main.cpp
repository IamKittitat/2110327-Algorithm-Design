#include<iostream>
#include<vector>

using namespace std;

void printChoice(vector<vector<int>> &choice,int l,int r){
    if(l == r){
        cout << "B" << l;
        return;
    }
    if(r-l > 1) cout << "(";
    printChoice(choice,l,choice[l][r]);
    if(r-l > 1) cout << ")(";
    printChoice(choice,choice[l][r]+1,r);
    if(r-l > 1) cout << ")";
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n+2);
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    vector<vector<int>> choice(n+1,vector<int>(n+1,0));
    for(int i =1;i<=n+1;i++) cin >> v[i];
    for(int j = 1;j<=n;j++){
        for(int i =j-1;i>=1;i--){
            dp[i][j] = INT32_MAX;
            for(int x=i;x<j;x++){
                int tmp = dp[i][x] + dp[x+1][j] + v[i]*v[x+1]*v[j+1];
                if(tmp < dp[i][j]){
                    dp[i][j] = tmp;
                    choice[i][j] = x;
                }
            }
        }
    }   
    printChoice(choice,1,n);
    cout << endl;
    cout << dp[1][n];
}