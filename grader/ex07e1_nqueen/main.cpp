#include<iostream>
#include<vector>

using namespace std;

int ans = 0;

bool checkValid(vector<int> &sol,int i,int len){
    for(int r1 = 0;r1<len;r1++){
        // Check diagonal
        if(abs(sol[r1]-i) == len-r1) return false;
    }
    return true;
}

void solve(vector<int> &sol,vector<bool> &used,int len,int n){
    if(len == n){
        ans++;
        return;
    }
    // Backtracking
    for(int i = 0;i<n;i++){
        if(!used[i] && checkValid(sol,i,len)){
            used[i] = true;
            sol[len] = i;
            solve(sol,used,len+1,n);
            used[i] = false;
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> sol(n,0);
    vector<bool> used(n,false);
    solve(sol,used,0,n);
    cout << ans;
}