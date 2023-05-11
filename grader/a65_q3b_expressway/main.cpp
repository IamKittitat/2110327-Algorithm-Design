#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int,int> edge;

int main(){
    int n,c;
    cin >> n >> c;
    vector<vector<int>> dist(n+1,vector<int>(n+1,INT32_MAX));
    for(int i = 1;i<=n;i++) dist[i][i] = 0;
    dist[1][2] = c; dist[2][1] = c;
    for(int k = 3;k<=n;k++){
        int x;
        cin >> x;
        for(int j= 0;j<x;j++){
            int t,p;
            cin >> t >> p;
            dist[k][t] = min(dist[k][t],p);
            dist[t][k] = min(dist[t][k],p);
        }

    }
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j =1;j<=n;j++){
                if(dist[i][k] == INT32_MAX  || dist[k][j] == INT32_MAX) continue;
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
        if(k>=3)cout << dist[1][2] << " ";
    }
}

// Dijkstra O(elgv) 100/100
// int main(){
//     int n,c;
//     cin >> n >> c;
//     vector<vector<pair<int,int>>> g(n+1);
//     vector<int> minDist(n+1,INT32_MAX);
//     g[1].push_back({2,c});
//     g[2].push_back({1,c});
//     for(int i = 3;i<=n;i++){
//         int k;
//         cin >> k;
//         for(int j= 0;j<k;j++){
//             int t,p;
//             cin >> t >> p;
//             g[i].push_back({t,p});
//             g[t].push_back({i,p});
//         }
//         vector<int> dist(n+1,INT32_MAX);
//         dist[1] = 0;
//         priority_queue<edge,vector<edge>,greater<edge>> pq;
//         pq.push({0,1});
//         while(!pq.empty()){
//             edge t = pq.top();
//             pq.pop();
//             int from = t.second;
//             for(auto &u : g[from]){
//                 if(dist[from] + u.second < dist[u.first]){
//                     dist[u.first] = dist[from] + u.second;
//                     pq.push({dist[u.first],u.first});
//                 }
//             }
//         }
//         for(int i = 1;i<=n;i++){
//             minDist[i] = min(minDist[i],dist[i]);
//         }
//         cout << minDist[2] << " ";
//     }
// }