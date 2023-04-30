#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    // pair<end,start>
    vector<pair<int,int>> v(n);
    for(int i = 0;i<n;i++) cin >> v[i].second;
    for(int i = 0;i<n;i++) cin >> v[i].first;
    sort(v.begin(),v.end());

    int ans = 0;
    int lastFinish = -1;
    for(int i = 0;i<n;i++){
        if(v[i].second >= lastFinish){
            lastFinish = v[i].first;
            ans++;
        }
    }
    cout << ans;
}
