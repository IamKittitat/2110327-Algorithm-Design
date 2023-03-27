#include<iostream>
#include<vector>
#include<set>

using namespace std;

bool solve(vector<set<int>> &g,vector<int> &ip){
    for(auto &v : ip){
        if(g[v].size() > 0){
            return false;
        } else{
            // cout << "B";
            for(int i =0;i<g.size();i++){
                if(g[i].count(v) != 0) g[i].erase(v);
            }
        }
    }
    return true;
}

int main(){
    int n,e;
    cin >> n >> e;
    vector<set<int>> g(n+1);
    for(int i = 0;i<e;i++){
        int a,b;
        cin >> a >> b;
        g[b].insert(a);
    }

    for(int i =0 ;i<5;i++){
        vector<int> ip(n);
        for(int j =0;j<n;j++) cin >> ip[j];
        vector<set<int>> tmp = g;
        if(solve(tmp,ip)) cout << "SUCCESS\n";
        else cout << "FAIL\n";
    }

}