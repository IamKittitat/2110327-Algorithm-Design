#include<iostream>
#include<vector>

using namespace std;

bool solve(vector<vector<int>> &g,vector<int> &color,int maxColor,int idx,int n){
    if(idx == n) return true;
    
    for(int i = 1;i<=maxColor;i++){
        bool can = true;
        for(auto &u : g[idx]){
            if(u > idx) continue;
            if (color[u] == i) can = false;
        }
        if(can){
            color[idx] = i;
            if(solve(g,color,maxColor,idx+1,n)) return true;
        }
    }
    return false;
}

int main(){
    int n,e;
    cin >> n >> e;
    vector<vector<int>> g(n);
    for(int i = 0;i<e;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 1;i<=n;i++){
        vector<int> color(n,0);
        if(solve(g,color,i,0,n)){
            cout << i;
            break;
        }
    }
}
