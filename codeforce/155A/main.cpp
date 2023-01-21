#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,tmp,ans = 0;
    vector<int> v;
    cin >> n;
    for(int i =0 ; i< n; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    int minP = v[0],maxP = v[0];
    for(int i =1;i<n;i++){
        if(v[i] < minP){
            minP = v[i];
            ans++;
        }
        if(v[i] > maxP){
            maxP = v[i];
            ans++;
        }
    }
    cout << ans;
}
