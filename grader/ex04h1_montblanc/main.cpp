#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n,d;
vector<int> v;

int totalDay(int k){
    int lastHeight = 0,height = 0, days = 0;
    while(height < v.back()){
        lastHeight = height;
        height += k;
        auto it = upper_bound(v.begin(),v.end(),height);
        if(it != v.begin()) it--;
        days++;
        if(*it < height) height = *it;
        if(height == lastHeight) return 100001;
    }
    return days;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> d;
    v.resize(n);
    for(int i = 0;i<n;i++) cin >> v[i];
    int l = v[0], r = 1000000000;
    int maxDay = -1, bestK = 0;
    while(l < r){
        int k = (l+r)/2;
        int days = totalDay(k);
        if(days > d) l = k + 1;
        else{
            if(days > maxDay){
                maxDay = days;
                bestK = k;
            } else if(days == maxDay && k < bestK){
                bestK = k;
            }
            r = k;
        }
    }
    cout << bestK << " " << maxDay;
}