#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

typedef pair<int,pair<int,int>> edge;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> start(k),c(n);
    vector<vector<int>> g(n);
    for(int i = 0;i<k;i++) cin >> start[i];
    for(int i = 0;i<n;i++) cin >> c[i];
    for(int i = 0;i<m;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    vector<int> dist(n,10001*40000);
    for(int i = 0;i<k;i++){
        int s = start[i];
        priority_queue<edge,vector<edge>,greater<edge>> pq;
        dist[s] = c[s];
        pq.push({dist[s],{s,s}});

        while(!pq.empty()){
            edge t = pq.top();
            pq.pop();
            int w = t.first, from = t.second.first, to = t.second.second;
            for(auto &u : g[to]){
                if(dist[to] + c[u] < dist[u]){
                    dist[u] = dist[to] + c[u];
                    pq.push({dist[u],{to,u}});
                }
            }
        }
    }
    int ans = -1;
    for(auto &x : dist) ans = max(ans,x);
    cout << ans;

}