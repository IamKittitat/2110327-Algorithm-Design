#include <bits/stdc++.h>
#include <fstream>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
    setIO("diamond");
    int n,k,ans=0;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n;i++) cin >> v[i];
    for(auto &x : v){
        int tmp = 0;
        for(auto &y : v){
            if(x <= y && x+k >= y)tmp++;
        }
        ans = max(ans,tmp);
    }
    cout << ans;
}
