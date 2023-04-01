#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int,pair<int,int>> edge;

int main(){
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> g(n);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            int ip;
            cin >> ip;
            if(ip >= 0){
                g[i].push_back({j,ip});
            }
        }
    }

    vector<int> dist(n,INT32_MAX);
    priority_queue<edge,vector<edge>,greater<edge>> pq;
    dist[0] = 0;
    pq.push({0,{0,0}});
    while(!pq.empty()){
        edge t = pq.top();
        pq.pop();
        int from = t.second.first, to = t.second.second;
        for(auto &u : g[to]){
            if(dist[to] + u.second < dist[u.first]){
                dist[u.first] = dist[to] + u.second;
                pq.push({dist[u.first],{to,u.first}});
            }
        }
    }
    int ans = -1;
    for(auto &x : dist) ans = max(ans,x);
    if(ans == INT32_MAX) cout << -1;
    else cout << ans;
}

/*
5
0 1 -1 -1 7
-1 0 2 3 5
-1 -1 0 4 -1
-1 4 2 0 -1
-1 -1 -1 4 0
*/