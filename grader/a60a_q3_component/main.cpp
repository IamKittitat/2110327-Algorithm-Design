#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<vector<int>> &g,vector<int> &color,int v){
    color[v] = 1;
    for(auto &u : g[v]){
        if(color[u] == 0) dfs(g,color,u);
    }
    color[v] = 2;
}

int dfs_all(vector<vector<int>> &g){
    int ans = 0;
    vector<int> color(g.size());
    for(int i=0;i<g.size();i++){
        if(color[i] == 0){
            ans++;
            dfs(g,color,i);
        }
    }
    return ans;
}

int main(){
    int v,e;
    cin >> v >> e;
    vector<vector<int>> g(v);
    for(int i = 0;i<e;i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cout << dfs_all(g);
}