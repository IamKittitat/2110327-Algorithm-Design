#include <bits/stdc++.h>
#include <fstream>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
    setIO("gymnastics");
    int k,n;
    cin >> k >> n;
    vector<int> v(n);
    map<pair<int,int>,int> m;
    for(int i =0;i<k;i++){
        for(int j=0;j<n;j++) cin >> v[j];
        for(int j = 0; j<v.size();j++){
            for(int k = j+1;k<v.size();k++) m[{v[j],v[k]}]++;
        }
    }
    int ans = 0;
    for(auto &x : m){
        if(x.second == k)ans++;
    }
    cout << ans;
}
