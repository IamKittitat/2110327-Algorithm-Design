#include<iostream>
#include<vector>

using namespace std;

bool ok;
int ans = 0;
int one = 0;

void dfs_i(vector<vector<int>> &edge,vector<int> &color,int v){
    color[v] = 1;
    for(auto &u : edge[v]){
        if(color[u] == 0) dfs_i(edge,color,u);
        if(edge[u].size() == 1) one++;
        if(edge[u].size() > 2) ok =false;
        color[u] = 2;
    }
}

void dfs(vector<vector<int>> &edge,vector<int> &color){
    for(int i = 0;i<edge.size();i++){
        ok = true;
        one = 0;
        if(color[i] == 0){
            dfs_i(edge,color,i);
            if(ok && (one == 2 || edge[i].size() == 0)) ans++;
        }
    }
}

int main(){
    int v,e;
    cin >> v >> e;
    vector<vector<int>> edge(v);
    vector<int> color(v,0);
    for(int i =0;i<e;i++){
        int a,b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    // for(int i = 0;i<v;i++){
    //     cout << i << " : ";
    //     for(auto &x : edge[i]) cout << x << " ";
    //     cout << endl;
    // }
    dfs(edge,color);
    cout << ans;
}