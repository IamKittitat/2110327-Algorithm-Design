#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> g(n);
    for(int i= 0;i<n;i++) cin >> g[i];
    sort(g.begin(),g.end());
    long long ans = (n-1)*g[0];
    for(int i = 1;i<n;i++) ans += g[i];
    cout << ans;
}