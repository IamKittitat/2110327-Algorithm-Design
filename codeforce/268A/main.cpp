#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<pair<int,int>> v;
    int n,home,guest,ans=0;
    cin >> n;
    for(int i =0;i<n;i++){
        cin >> home;
        cin >> guest;
        v.push_back({home,guest});
    }
    for(int i = 0; i< n;i++){
        for(int j = 0;j<n;j++){
            if(i != j){
                if(v[i].first == v[j].second) ans++;
            }
        }
    }
    cout << ans;
}
