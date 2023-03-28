#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void dfs(vector<vector<int>> &g,vector<int> &color,stack<int> &s,int v){
    color[v] = 1;
    for(auto &u : g[v]){
        if(color[u] == 0) dfs(g,color,s,u);
    }
    color[v] = 2;
    s.push(v);
}

void solve(vector<vector<int>> &g,int n){
    vector<int> color(n,0);
    stack<int> s;
    for(int i = 0;i<n;i++){
        if(color[i] == 0) dfs(g,color,s,i);
    }
    vector<int> ans;
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}

 int main(){
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0;i<n;i++){
        int m;
        cin >> m;
        for(int j = 0;j<m;j++){
           int ip;
           cin >> ip;
           g[ip].push_back(i); 
        }
    }
    solve(g,n);

 }