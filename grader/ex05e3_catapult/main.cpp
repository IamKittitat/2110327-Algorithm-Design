#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

stack<int> ss;

void dfs2(vector<vector<int>> &g,vector<int> &color,int &count,int v){
    color[v] = 1;
    count++;
    for(auto &u : g[v]){    
        if(color[u] == 0) dfs2(g,color,count,u);
    }
    color[v] = 2;
}

void dfs1(vector<vector<int>> &g,vector<int> &color,int v){
    color[v] = 1;
    for(auto &u : g[v]){    
        if(color[u] == 0) dfs1(g,color,u);
    }
    color[v] = 2;
    ss.push(v);
}

void dfs_all(vector<vector<int>> &g,int n){
    vector<int> color(n,0);
    for(int i = 0;i<n;i++){
        if(color[i] == 0) dfs1(g,color,i);
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> g(n),gt(n);
    for(int i = 0;i<n;i++){
        int m;
        cin >> m;
        for(int j = 0;j<m;j++){
            int ip;
            cin >> ip;
            g[i].push_back(ip);
            gt[ip].push_back(i);
        }
    }
    dfs_all(gt,n);
    vector<int> ans;
    vector<int> color(n,0);
    while(!ss.empty()){
        int t = ss.top();
        ss.pop();
        int count = 0;
        if(color[t] == 0){
            dfs2(g,color,count,t);
            ans.push_back(count);
        }
    }
    sort(ans.begin(),ans.end());
    for(auto &x : ans) cout << x << " ";

}