#include<iostream>
#include<vector>
#include<queue>

using namespace std;


int ans = -1;

void bfs(vector<vector<int>> &g,vector<int> &dist,int s){
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto & u : g[v]){
            if(dist[u] == INT32_MAX){
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
}

int bfs_all(vector<vector<int>> &g,int k){
    for(int i =0; i<g.size();i++){
        vector<int> dist(g.size(),INT32_MAX);
        bfs(g,dist,i);
        int tmp = 0;
        for(auto &d : dist) if(d <= k) tmp++;
        ans = max(ans,tmp);
    }
    return ans;
}

int main(){
    int n,e,k;
    cin >> n >> e >> k;
    vector<vector<int>> g(n);
    for(int i =0;i<e;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cout << bfs_all(g,k);
}