#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

// KOSARAJU's ALGO to find SS of the graph

// DFS and count the amount of vertex in the Component
void dfs(stack<int> &s,vector<vector<int>> &g,vector<int> &color,int v,int &count){
    color[v] = 1;
    for(auto &u : g[v]){
        if(color[u] == 0){
            count++;
            dfs(s,g,color,u,count);
        }
    }
    color[v] = 2;
    s.push(v);
}

vector<int> solve(vector<vector<int>> &g,vector<vector<int>> &gt,int n){
    stack<int> s;
    vector<int> color(n,0);
    int count = 0;
    // DFS in GT to find source of the graph
    for(int i =0 ;i<n;i++){
        if(color[i] == 0) dfs(s,gt,color,i,count);
    }
    vector<int> ans;
    vector<int> color2(n,0);
    
    // DFS in G to find the connected component
    while(!s.empty()){
        // start count with 1 (Vertex t)
        count = 1;
        int t = s.top();
        s.pop();
        if(color2[t] == 0){
            dfs(s,g,color2,t,count);
            // cout << "! " << count << endl;
            ans.push_back(count);
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> g(n),gt(n);
    for(int i = 0;i<n;i++){
        int m;
        cin >> m;
        for(int j =0;j<m;j++){
            int ip;
            cin >> ip;
            g[i].push_back(ip);
        }
    }
    // Make g transpose
    for(int i = 0;i<n;i++){
        for(auto &x : g[i]){
            gt[x].push_back(i);
        }
    }
    vector<int> ans = solve(g,gt,n);
    sort(ans.begin(),ans.end());
    for(auto &x : ans) cout << x << " ";
}