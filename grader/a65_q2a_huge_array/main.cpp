#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<pair<int,int>> v(n);
    vector<int> S(n);
    for(int i = 0;i<n;i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(),v.end());
    S[0] = v[0].second;
    for(int i =1;i<n;i++) S[i] = S[i-1] + v[i].second;




    for(int i =0;i<q;i++){
        int ip;
        cin >> ip;
        auto it = lower_bound(S.begin(),S.end(),ip);
        cout << v[it-S.begin()].first << "\n";
    }
}

/*
for(auto &x : v){
        cout << x.first << " "  << x.second << endl;
    }

    for(auto &x : S) cout << x << " ";


5 3
9 1
4 5
9 3
8 3
7 7
1
15
8
*/