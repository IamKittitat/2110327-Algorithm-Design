#include<iostream>
#include<vector>

using namespace std;

int n, ans = 0;

void solve(int last,int need){
    if(need == 0){
        ans++;
        return;
    }

    for(int i = last;i<=need;i++) solve(i,need-i);
}

int main(){
    cin >> n;
    solve(1,n);
    cout << ans;
}