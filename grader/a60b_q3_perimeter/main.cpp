#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int n,e,k;
    cin >> n >> e >> k;
    vector<vector<int>> g(n+1);
    vector<int> dist(n+1,INT32_MAX);
    for(int i = 0;i<e;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while(!q.empty()){
        int p = q.front(); q.pop();
        for(auto &u : g[p]){
            if(dist[u] == INT32_MAX){
                dist[u] = dist[p] + 1;
                q.push(u);
            }
        }
    }
    
    int ans = 0;
    for(auto &x : dist) if(x == k) ans++;
    cout << ans;
}