#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,k,w;
    cin >> n >> m >> k >> w;
    vector<pair<int,int>> mons(m),t(k);
    for(int i = 0;i<m;i++) cin >> mons[i].first;
    for(int i = 0;i<m;i++) cin >> mons[i].second;
    // for(auto &x : mons) cout << x.first << " " << x.second << endl;
    for(int i =0;i<k;i++){
        cin >> t[i].first;
        t[i].second = 1;
    }
    sort(t.begin(),t.end());
    // for(auto &x : t) cout << x.first << " " << x.second << endl;
    if(w == 0){
        for(int i =0;i<k;i++){
            for(int j = 0;j<m;j++){
                if(t[i].first == mons[j].first){
                    mons[j].second--;
                }
            }
        }
        int ans = 0;
        for(auto &x : mons) ans+= x.second;
        cout << ans;
    }
    else{

    for(int i =0;i<m;i++){
        auto it1 = lower_bound(t.begin(),t.end(),make_pair(mons[i].first-w,-3));
        auto it2 = lower_bound(t.begin(),t.end(),make_pair(mons[i].first+w,-3));
        while(it1 != it2){
            if(mons[i].second > 0 && it1->second > 0){
                mons[i].second--;
                it1->second--;
            }
            it1++;
            if(mons[i].second <= 0) break;
        }
    }

    int ans = 0;
    for(auto &x : mons) ans+= x.second;
    cout << ans;
    }
}


/*
10 1 2 1
1
10
2 5


100 3 3 1
80 70 60
1 1 1
70 71 69
*/