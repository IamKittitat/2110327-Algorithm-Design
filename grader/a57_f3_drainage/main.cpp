#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,l;
    cin >> n >> l;
    vector<int> v(n);
    for(int i = 0;i<n;i++) cin >> v[i];
    sort(v.begin(),v.end());
    int idx = v[0];
    int ans = 1;
    while(idx < v.back()){
        idx += l;
        auto it = lower_bound(v.begin(),v.end(),idx);
        if(*it >= idx) idx = *it;
        else break;
        ans++;
    }
    cout << ans;

}