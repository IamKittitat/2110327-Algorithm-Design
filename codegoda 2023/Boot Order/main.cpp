#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

stack<int> ss;

bool dfs(vector<vector<int>> &g,vector<int> &color,int v,vector<int> &parent){
    color[v] = 1;
    for(auto &u : g[v]){
        if(color[u] == 1 && parent[u] != v) return true;
        if(color[u] == 0){
            parent[u] = v;
            if(dfs(g,color,u,parent)) return true;
        }
    }
    color[v] = 2;
    ss.push(v);
    return false;
}

bool hasCycle(vector<vector<int>> &g,int m){
    vector<int> color(m+1,0);
    vector<int> parent(m+1,0);
    for(int i = 1;i<=m;i++) parent[i] = i;

    // for(int i=m;i>=1;i--){
        for(int i = 1;i<=m;i++){
        // cout << i << endl;
        if(color[i] == 0){
            if(dfs(g,color,i,parent)) return true;
        }
    }
    return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios_base::sync_with_stdio(false); cin.tie(0);   
    int m,n;
    cin >> m >> n;
    vector<vector<int>> g(m+1);
    for(int i = 0;i<n;i++){
        int a,b;
        cin >> a >> b;
        g[b].push_back(a);
    }
    for(auto &u : g) sort(u.begin(),u.end(),std::greater<>());
    // for(auto &x : g){
    //     for(auto &y : x) cout << y << " ";
    //     cout << endl;
    // }
    if(hasCycle(g,m)){
        cout << -1;
    } else{
        while(!ss.empty()){
            cout << ss.top() << " ";
            ss.pop();
        }
    }
    return 0;
}