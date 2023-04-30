#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int f,n,w;
    cin >> f >> w >> n;
    vector<int> v(f);
    for(int i = 0;i<f;i++) cin >> v[i];
    sort(v.begin(),v.end());
    int idx = v[0];
    int ans = 1;
    int len = 2*w + 1;

    while(idx <= v.back()){
        idx += len;
        auto it = lower_bound(v.begin(),v.end(),idx);
        if(*it >= idx) idx = *it;
        else break;
        ans++;
    }
    cout << ans;
}