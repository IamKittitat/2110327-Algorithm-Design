#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int n,e,k;
    cin >> n >> e >> k;
    vector<vector<int>> g(n);
    for(int i = 0;i<e;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int ans = -1;
    for(int i = 0;i<n;i++){
        queue<int> q;
        vector<int> dist(n,INT32_MAX);
        q.push(i);
        dist[i] = 0;
        int tmp = 1;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            for(auto &u : g[t]){
                if(dist[u] == INT32_MAX){
                    dist[u] = dist[t] + 1;
                    if(dist[u] <= k){
                        tmp++;
                        q.push(u);
                    }
                }
            }
        }
        ans = max(ans,tmp);
    }
    cout << ans;
}