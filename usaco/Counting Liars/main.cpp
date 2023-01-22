#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,tmp;
    string cmd;
    vector<int> l,g;
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> cmd >> tmp;
        if(cmd == "G") g.push_back(tmp);
        else l.push_back(tmp);
    }
    sort(l.begin(),l.end());
    sort(g.begin(),g.end());
    int ans = g.size();
    for(int i =0 ;i < g.size();i++){
        tmp = g.size()-(i+1);
        for(int j = 0 ; j < l.size();j++){
            if(l[j] < g[i]) tmp++;
        }
        ans = min(ans,tmp);
    }
    cout << ans;
}
