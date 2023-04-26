#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int f,w,n;
    cin >> f >> w >> n;
    vector<int> foods(f);
    for(int i = 0;i<f;i++) cin >> foods[i];
    int l = 2*w+1;
    sort(foods.begin(),foods.end());
    int idx = foods[0];
    int ans = 1;
    while(idx < foods[foods.size()-1]){
        idx += l;
        auto it = lower_bound(foods.begin(),foods.end(),idx);
        if(*it < idx) break;
        idx = *it;
        ans++;
    }
    cout << ans;
}