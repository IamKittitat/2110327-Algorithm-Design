#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class DSU{
    private:
        vector<int> parent;
    public: 
        DSU(int n){
            parent.resize(n);
            for(int i = 0;i<n;i++) parent[i] = i;
        }
        int findRoot(int u){
            if(parent[u] != u){
                parent[u] = findRoot(parent[u]);
            }
            return parent[u];
        }
        int joinSet(int u,int v){
            int pu = findRoot(u);
            int pv = findRoot(v);
            if(pu != pv){
                parent[pu] = pv;
                return true;
            } else{
                return false;
            }
        }
};

typedef pair<int,pair<int,int>> edge;

int kruskal(priority_queue<edge,vector<edge>,greater<edge>> &e,int n){
    DSU dsu(n);
    int count = 0;
    int ans = 0;
    while(count < n-1){
        edge t = e.top();
        e.pop();
        if(dsu.joinSet(t.second.first,t.second.second)){
            ans+= t.first;
            count++;
        }
    }
    return ans;
}   

int findMin(vector<int> &dist){
    int idx = INT32_MAX, minVal = INT32_MAX;
    for(int i = 0;i<dist.size();i++){
        if(dist[i] < minVal){
            minVal = dist[i];
            idx = i;
        }
    }
    return idx;
}

int prim(vector<vector<int>> &g,int n){
    int ans = 0;
    vector<int> dist(n,INT32_MAX);
    vector<bool> inMST(n,false);
    dist[0] = 0;
    for(int i = 0;i<n;i++){
        int u = findMin(dist);
        ans += dist[u];
        dist[u] = INT32_MAX;
        inMST[u] = true;
        for(int j = 0;j<n;j++){
            if(!inMST[j] && g[u][j] < dist[j]){
                dist[j] = g[u][j];
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> g(n,vector<int>(n,0));
    priority_queue<edge,vector<edge>,greater<edge>> e;
    for(int i = 0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            int ip;
            cin >> ip;
            g[i][j] = ip;
            g[j][i] = ip;
            e.push({ip,{i,j}});
        }
    }
    // cout << kruskal(e,n);
    cout << prim(g,n);
}

/*
4
1 3 4
2 7 
6
*/