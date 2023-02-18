#include<iostream>
#include<vector>

using namespace std;

int dp[105][105];
int choice[105][105];

void printChoice(int l,int r){
    // cout << l << " " << r << endl;
    if(l == r){
        cout << "B" << l;
        return;
    } 
    if(r-l == 1){
        cout << "B" << l << "B" << r;
        return;
    }

    cout << "(";
    printChoice(l,choice[l][r]);
    cout << ")";
    cout << "(";
    printChoice(choice[l][r]+1,r);
    cout << ")";
}

int bottomUp(int n,vector<int> &v){
    for(int i = 1; i<= n;i++) dp[i][i] = 0;

    for(int i = n-1;i>=1;i--){
        for(int j = 1;j<=i;j++){
            int minCost = INT32_MAX;
            int bestChoice = -1;
            int right = j + (n-i);
            for(int x = j;x < right;x++){
                int nowCost = dp[j][x] + dp[x+1][right] + v[j-1]*v[x]*v[right];
                if(nowCost < minCost){
                    minCost = nowCost;
                    bestChoice = x;
                }
            }
            dp[j][right] = minCost;
            choice[j][right] = bestChoice;
        }
    }
    printChoice(1,n);
    cout << endl;
    // for(int i =0;i<=n;i++){
    //     for(int j = 0;j<=n;j++) cout << choice[i][j] << " ";
    //     cout << endl;
    // }
    // cout << "C" << choice[1][n] << endl;
    return dp[1][n];
}

int solve(int l,int r,vector<int> &v){
    if(r == l) return 0;
    if(r-l == 1) return v[l-1]*v[l]*v[l+1];
    if(dp[l][r] > 0) return dp[l][r];

    int minCost = INT32_MAX,left,right;
    for(int i =l;i<r;i++){
        int nowCost = solve(l,i,v) + solve(i+1,r,v) + v[l-1]*v[i]*v[r];
        minCost = min(minCost,nowCost);
    }

    dp[l][r] = minCost;
    return minCost;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i =0;i<=n;i++) cin >> v[i];
    // cout << solve(1,n,v);
    cout << bottomUp(n,v);
}