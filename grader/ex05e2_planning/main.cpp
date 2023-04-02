#include<iostream>
#include<stack>
#include<vector>

using namespace std;

stack<int> ss;

void dfs(vector<vector<int>> &g, vector<int> &color,int v){
    color[v] = 1;
    for(auto &u : g[v]){
        if(color[u] == 0)dfs(g,color,u);
    }
    color[v] = 2;
    ss.push(v);
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

    vector<int> color(n,0);
    for(int i= 0 ;i<n;i++){
        if(color[i] == 0) dfs(g,color,i);
    }
    while(!ss.empty()){
        cout << ss.top() << " ";
        ss.pop();
    }
}