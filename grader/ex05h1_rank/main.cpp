#include<iostream>
#include<vector>
#include<stack>
#include<set>

using namespace std;

int maxLevel;
vector<int> level;

// DFS GT (1st step of Kosaraju)
void dfs(vector<vector<int>> &g,vector<int> &color,stack<int> &s, int v){
    color[v] = 1;
    for(auto &u : g[v]){
        if(color[u] == 0){
            dfs(g,color,s,u);
        }
    }
    color[v] = 2;
    s.push(v);
}

void dfs2(vector<vector<int>> &g,vector<int> &color, int v,vector<int> &component){
    color[v] = 1;
    component.push_back(v);
    for(auto &u : g[v]){
        if(color[u] == 0){
            dfs2(g,color,u,component);
        }
        // Already visited --> update maxlevel
        else{
            maxLevel = max(maxLevel,level[u]);
        }
    }
    color[v] = 2;
}

// DFS ALL And returen order of kosaraju node
stack<int> dfs_all(vector<vector<int>> &g, int n){
    vector<int> color(n,0);
    stack<int> s;
    for(int i = 0;i<n;i++){
        if(color[i] == 0) dfs(g,color,s,i);
    }
    return s;
}

int main(){
    int n,p;
    cin >> n >> p;
    vector<vector<int>> g(n),gt(n);
    for(int i = 0;i<p;i++){
        int a,b;
        cin >> a >> b;
        g[b].push_back(a);
        gt[a].push_back(b);
    }
    // DFS in g transpose
    stack<int> s = dfs_all(gt,n);
    vector<int> ans(n,0);
    int idx = 0;
    level.resize(n);

    vector<int> color(n,0);
    set<int> previous;
    while(!s.empty()){
        stack<int> tmp;
        int t = s.top();
        s.pop();
        if(color[t] == 0){
            maxLevel = 0;
            // Component that in the same SCC
            vector<int> component;
            dfs2(g,color,t,component);
            // Same level for the same SCC
            for(int i = 0;i<component.size();i++) level[component[i]] = maxLevel+1;
            // ans[maxLeve] --> in case not in the same SCC
            ans[maxLevel] += component.size();
        }
    }

    idx = 0;
    while(ans[idx] != 0) cout << ans[idx++] << " ";

}