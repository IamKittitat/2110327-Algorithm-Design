#include<iostream>
#include<vector>

using namespace std;

int n,x,y;
bool found = false;
vector<vector<int>> g;
vector<int> color;

int dfs(vector<int> &sol,int v){
    color[v] = 1;
    for(auto &u : g[v]){
        if(color[u] == 0){
            color[u] = 1;
            sol.push_back(u);
            if(dfs(sol,u) == y){
                found = true;
                return y;
            } 
            sol.pop_back();
            color[u] = 0;
        }
    }
    color[v] = 0;
    return v;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> x >> y;
    g.resize(n+1);
    color.resize(n+1);
    for(int i = 0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> sol;
    sol.push_back(x);
    dfs(sol,x);
    if(found) for(auto &a : sol) cout << a << " ";

}