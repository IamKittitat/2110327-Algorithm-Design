#include<iostream>
#include<vector>

using namespace std;

vector<int> b;

void dfs(vector<vector<int>> &g, vector<int> &color, int v,int &total){
    color[v] = 1;
    for(auto &u : g[v]){
        if(color[u] == 0){
            dfs(g,color,u,total);
        }
    }
    color[v] = 2;
    if(b[v] > 0){
        total -= b[v];
        b[v] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n);
    b.resize(n);
    vector<int> start(k);
    int total = 0;
    for(int i = 0 ;i<n; i++){
        cin >> b[i];
        total += b[i];
    } 
    for(int i = 0;i<k;i++) cin >> start[i];
    for(int i = 0;i<m;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    for(int i = 0;i<k;i++){
        vector<int> color(n,0);
        if(b[start[i]] != 0) dfs(g,color,start[i],total);
        cout << total << " ";
    }
}