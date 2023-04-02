#include<iostream>
#include<vector>

using namespace std;

int ans = 0;

void dfs(vector<vector<int>> &g,vector<int> &color,int v){
    color[v] = 1;
    ans++;
    for(auto &u : g[v]){
        if(color[u] == 0) dfs(g,color,u);
    }
    color[v] = 2;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n+1);
    for(int i = 0;i<m;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    for(int i = 1;i<=n;i++){
        vector<int> color(n+1,0);
        if(color[i] == 0) dfs(g,color,i);
    }
    cout << ans;
}