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

int main(){
    int n,e;
    cin >> n >> e;
    vector<vector<int>> g(n+1);
    for(int i = 0;i<e;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = 0;
    vector<int> color(n+1,0);
    for(int i = 1; i<=n;i++){
        if(color[i] == 0){
            ans++;
            dfs(g,color,i);
        }
    }
    cout << ans;
}