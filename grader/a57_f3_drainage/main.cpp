#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n,l;
    cin >> n >> l;
    vector<int> p(n);
    for(int i = 0;i<n;i++) cin >> p[i];
    sort(p.begin(),p.end());
    int idx = p[0];
    int ans = 1;
    while(idx <= p[p.size()-1]){
        idx += l;
        auto it = lower_bound(p.begin(),p.end(),idx);
        if(*it < idx) break;
        ans++;
        idx = *it;
    }
    cout << ans;
}