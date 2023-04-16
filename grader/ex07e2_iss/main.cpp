#include<iostream>
#include<vector>

using namespace std;

int ans = 0;

void solve(int last,int total,int n){    
    if(total == n){
        ans++;
        return;
    }
    
    for(int i = last;i<=n-total;i++){
        solve(i,total+i,n);
    }
}

int main(){
    int n;
    cin >> n;
    solve(1,0,n);
    cout << ans;
}
