#include<iostream>
#include<vector>

using namespace std;

bool dfs(vector<vector<int>> &g,vector<int> &color,vector<int> &parent,int v){
    color[v] = 1;
    if(g[v].size() > 2) return false;
    for(auto &u : g[v]){
        if(color[u] == 0){
            parent[u] = v;
            dfs(g,color,parent,u);
        }
        if(color[u] == 1 && parent[v] != u) return false;
    }
    color[v] = 2;
    return true;
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
    int ans = 0;
    vector<int> color(n,0),parent(n,-1);
    for(int i = 0;i<n;i++){
        if(color[i] == 0 && dfs(g,color,parent,i)) ans++;
    }
    cout << ans;
}
