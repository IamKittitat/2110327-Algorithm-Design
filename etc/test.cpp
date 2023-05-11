#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<vector<int>> g;
vector<int> color;
stack<int> s;
int n,m;

void dfs(int v, int pa){
    color[v] = 1;
    s.push(v);
    for(auto &u : g[v]){
        if(color[u] == 0) dfs(u,v);
        else{
            if(u != pa){
                while(!s.empty()){
                    cout << "! " << s.top() << endl;
                    if(s.top() == u) break;
                    s.pop();
                }
            }
        }
    }
    if(!s.empty()) s.pop();
}

int main(){
    cin >> n >> m;
    g.resize(n);
    color.resize(n,0);
    for(int i = 0;i<m;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 0;i<n;i++){
        if(color[i] == 0) dfs(i,-1);
    }
}