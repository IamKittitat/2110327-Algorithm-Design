#include<iostream>
#include<vector>

using namespace std;

// Check that does v met other vertex that create cycle (DFS)
bool hasCycle(vector<vector<int>> &g,vector<int> &color,vector<int> &p,int v){
    // Visiting v
    color[v] = 1;
    // All vertex adj to v
    for(auto &u : g[v]){
        // If already visit u and not parent == CYCLE!!
        if(color[u] == 1 && p[v] != u) return true;
        // First time visit u
        if(color[u] == 0){ 
            // Set parent of u
            p[u] = v;
            // Check if u create cycle
            if(hasCycle(g,color,p,u)) return true;
        }
    }
    // Finished visit v
    color[v] = 2;
    // No cycle for v
    return false;
}

// DFS all vertex
bool solve(vector<vector<int>> &g,vector<int> &color,vector<int> &p){
    for(int i = 0;i<g.size();i++){
        // First time visit i
        if(color[i] == 0){
            // If create cycle return true
            if(hasCycle(g,color,p,i)) return true;
        }
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    for(int i =0;i<t;i++){
        int n,e;
        cin >> n >> e;
        vector<vector<int>> g(n);
        vector<int> color(n,0);
        vector<int> p(n,n);
        for(int j=0;j<e;j++){
            int a,b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        if(solve(g,color,p)) cout << "YES\n";
        else cout << "NO\n";
    }
}

/*
4
4 0
4 4
2 3
0 1
1 2
2 0
4 3
0 1
1 2
2 0
4 1
1 3
*/