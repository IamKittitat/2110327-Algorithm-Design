#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,m;
    cin >> n >> m;
    map<int,map<string,int>> data;
    for(int i = 0;i<n;i++){
        int h,k;
        cin >> h >> k;
        for(int j = 0;j<k;j++){
            string kw;
            int scr;
            cin >> kw >> scr;
            data[h][kw] = scr;
        }
    }
    for(int i = 0;i<m;i++){
        int l;
        cin >> l;
        map<int,int> ans;
        for(int j = 0;j<l;j++){
            string ip;
            cin >> ip;
            for(auto &x : data){
                if(x.second.count(ip) > 0){
                    ans[x.first] += x.second[ip];
                }
            }
            cout << ans.size() << endl;
            vector<pair<int,int>> v;
            for(auto &x : ans) cout << x.first << "," << x.second << endl;
        }
        cout << "\n";
    }
    return 0;
}